"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
//javascript library that provides SHA256 security
const CryptoJS = require("crypto-js");
const _ = require("lodash");
//import methods from p2p
const p2p_1 = require("./p2p");
//import methods from transaction
const transaction_1 = require("./transaction");
//import methods from transaction pool
const transactionPool_1 = require("./transactionPool");
//import methods from util
const util_1 = require("./util");
//import methods from wallet
const wallet_1 = require("./wallet");
//Block class that has the most basic data needed for a block in the blockchain
class Block {
    //constructors for previous variables
    constructor(index, hash, previousHash, timestamp, data, difficulty, nonce) {
        this.index = index;
        this.previousHash = previousHash;
        this.timestamp = timestamp;
        this.data = data;
        this.hash = hash;
        this.difficulty = difficulty;
        this.nonce = nonce;
    }
}
exports.Block = Block;
const mysql = require('mysql');
//mysql connection parameters
var connection = mysql.createConnection({
    host: "polomoto.com",
    user: "wordpress",
    password: "WordPressUserPassword",
    database: "wordpress"
});
//This is to setup the first transaction. It uses a default address and amount
const genesisTransaction = {
    'txIns': [{ 'signature': '', 'txOutId': '', 'txOutIndex': 0 }],
    'txOuts': [{
            'address': '04bfcab8722991ae774db48f934ca79cfb7dd991229153b9f732ba5334aafcd8e7266e47076996b55a14bf9913ee3145ce0cfc1372ada8ada74bd287450313534a',
            'amount': 50
        }],
    'id': 'e655f6a5f26dc9b4cac6e46f52336428287759cf81ef5ff10854f69d68f43fa3'
};
//The way a blockchain works is by linking each block to the hash of the previous block
//however, there must be a hardcoded 0th block-- called the genesis block
//this has a index of 0 (obviously), a hash, no previous block, the current Unix timestamp, and a name
const genesisBlock = new Block(0, '816534932c2b7154836da6afc367695e6337db8a921823784c14378abed4f7d7', '', 1521580268, [genesisTransaction], 0, 0);
//this is just an array of blocks that currently only contains the genesis block
let blockchain = [genesisBlock];
//this is just a constant variable that points to the blockchain array
const getBlockchain = () => blockchain;
exports.getBlockchain = getBlockchain;
//this is a constant variable that points to the most recent block (-1)
const getLatestBlock = () => blockchain[blockchain.length - 1];
exports.getLatestBlock = getLatestBlock;
//unspent transaction outputs of genesis block is set to this on start
let unspentTxOuts = transaction_1.processTransactions(blockchain[0].data, [], 0);
//get the unspent transaction outputs from unspentTxOuts
const getUnspentTxOuts = () => _.cloneDeep(unspentTxOuts);
exports.getUnspentTxOuts = getUnspentTxOuts;
//setUnspentTxOuts updates txPool and should be only updated at the same time
const setUnspentTxOuts = (newUnspentTxOut) => {
    console.log('replacing unspentTxouts with: %s', newUnspentTxOut);
    unspentTxOuts = newUnspentTxOut;
};
//generate blocks at this interval in seconds
const BLOCK_GENERATION_INTERVAL = 10;
//every x blocks increase the mining difficulty
const DIFFICULTY_ADJUSTMENT_INTERVAL = 10;
//get current time
const getCurrentTimestamp = () => Math.round(new Date().getTime() / 1000);
//getDifficult method to adjust the difficulty of the current block / the block difficulty
//does computation in getAdjustedDifficulty
const getDifficulty = (aBlockchain) => {
    //get newest block
    const latestBlock = aBlockchain[blockchain.length - 1];
    if (latestBlock.index % DIFFICULTY_ADJUSTMENT_INTERVAL === 0 && latestBlock.index !== 0) {
        return getAdjustedDifficulty(latestBlock, aBlockchain);
    }
    else {
        return latestBlock.difficulty;
    }
};
//getAdjustedDifficulty
const getAdjustedDifficulty = (latestBlock, aBlockchain) => {
    //get the last adjusted block
    const prevAdjustmentBlock = aBlockchain[blockchain.length - DIFFICULTY_ADJUSTMENT_INTERVAL];
    //get time expected to mine
    const timeExpected = BLOCK_GENERATION_INTERVAL * DIFFICULTY_ADJUSTMENT_INTERVAL;
    //current time taken since last block
    const timeTaken = latestBlock.timestamp - prevAdjustmentBlock.timestamp;
    //if theres less time then increase difficulty 
    if (timeTaken < timeExpected / 2) {
        return prevAdjustmentBlock.difficulty + 1;
        //else decrease difficulty
    }
    else if (timeTaken > timeExpected * 2) {
        if (prevAdjustmentBlock.difficulty > 0) {
            return prevAdjustmentBlock.difficulty - 1;
        }
        else {
            return 0;
        }
        //else nothing
    }
    else {
        return prevAdjustmentBlock.difficulty;
    }
};
//generate a raw block actual does things
const generateRawNextBlock = (blockData) => {
    //getLatestblock
    const previousBlock = getLatestBlock();
    //getDifficulty with above method
    const difficulty = getDifficulty(getBlockchain());
    //increment index
    const nextIndex = previousBlock.index + 1;
    //just get current time
    const nextTimestamp = getCurrentTimestamp();
    //create a new block, if its unique add to blockchain else return error
    const newBlock = findBlock(nextIndex, previousBlock.hash, nextTimestamp, blockData, difficulty);
    if (addBlockToChain(newBlock)) {
        p2p_1.broadcastLatest();
        return newBlock;
    }
    else {
        return null;
    }
};
exports.generateRawNextBlock = generateRawNextBlock;
//MICHAEL DINEEN
//Generates next block. uses hash from previous block to create the rest of required content
//index,hash,data,timestamp
const generateNextBlock = () => {
    //get transaction and block data and actually do everything in generateRawNextBlock
    const coinbaseTx = transaction_1.getCoinbaseTransaction(wallet_1.getPublicFromWallet(), getLatestBlock().index + 1);
    const blockData = [coinbaseTx].concat(transactionPool_1.getTransactionPool());
    return generateRawNextBlock(blockData);
};
exports.generateNextBlock = generateNextBlock;
const calculateHashForBlock = (block) => calculateHash(block.index, block.previousHash, block.timestamp, block.data, block.difficulty, block.nonce); //takes in all of the parameters for the block in order to calculate
//a formal unique hash code for a new block
//Calculates a unique hash code, takes in index, previoushash, timestamp,data, and returns a type string
const calculateHash = (index, previousHash, timestamp, data, difficulty, nonce) => CryptoJS.SHA256(index + previousHash + timestamp + data + difficulty + nonce).toString(); //CryptoKS.SHA256 <--- Library function that calculates hash for user
//toString converts hash to type string which is the type returned by this function
const addBlock = (newBlock) => {
    if (isValidNewBlock(newBlock, getLatestBlock())) {
        blockchain.push(newBlock); //Most recent block will allow for previous hash to create new hash code
    } //Blockchain.push(newblock) <--- Pushes the new block onto block chain stack
};
//Michael Dineen 2nd commit 
//Adds the created block to the overall blockchain
const addBlockToChain = (newBlock) => {
    if (isValidNewBlock(newBlock, getLatestBlock())) {
        const retVal = transaction_1.processTransactions(newBlock.data, getUnspentTxOuts(), newBlock.index); //checks to see if transactions are valid
        if (retVal === null) {
            console.log('block is not valid in terms of transactions'); //Returns invalid message to log
            return false;
        }
        else {
            blockchain.push(newBlock); //Push new block onto the block chain 
            setUnspentTxOuts(retVal); //sets unspenttxouts to the retval if that return value has been determined not to be null
            transactionPool_1.updateTransactionPool(unspentTxOuts); //Updates the transaction pool with the value of the unspent transaction outputs
            return true; //Returns true since the transaction is valid 
        }
    }
    return false; //Return false otherwise
};
exports.addBlockToChain = addBlockToChain;
const hashMatchesDifficulty = (hash, difficulty) => {
    const hashInBinary = util_1.hexToBinary(hash); //converts hexidecimal to binary in string
    const requiredPrefix = '0'.repeat(difficulty); //Checks to see if the string contains required prefic
    return hashInBinary.startsWith(requiredPrefix); //Determines that hash code starts with proper binary prefix 
};
//Mitchell Brooks
//isValidBlockStructure validates that a newly submitted block matches the correct types specified by the following variables:
const isValidBlockStructure = (block) => {
    return typeof block.index === 'number' //block.index === ensures the type of index is a number
        && typeof block.hash === 'string' //block.hash === ensures that the hash type is a string
        && typeof block.previousHash === 'string' //block.previousHash === ensures that the previous hash of the block is of type string
        && typeof block.timestamp === 'number' //block.timestamp === ensures that the timestamp of the block is a number
        && typeof block.data === 'object'; //block.data === ensures that the data of the block is of type string (i.e "block2data")
};
exports.isValidBlockStructure = isValidBlockStructure;
const isValidNewBlock = (newBlock, previousBlock) => {
    //checks to see if the block is valid
    if (!isValidBlockStructure(newBlock)) {
        console.log('Block has invalid structure');
        return false;
    }
    //makes sure the blocks are not the same
    if (previousBlock.index + 1 !== newBlock.index) {
        console.log('Blocks are the same');
        return false;
    }
    else if (previousBlock.hash !== newBlock.previousHash) {
        //Hashes the previous block and compares it to the newBlock to see if they are the same, fails if they are different
        console.log('Hashes are not the same');
        return false;
    }
    else if (calculateHashForBlock(newBlock) !== newBlock.hash) {
        //Determines it is an invalid hash if the newBlock.hash does not equal the calculated hash for the newBlock
        console.log(typeof (newBlock.hash) + ' ' + typeof calculateHashForBlock(newBlock));
        console.log('Invalid Hash: ' + calculateHashForBlock(newBlock) + ' ' + newBlock.hash);
        return false;
    }
    return true;
};
//Helper for replaceChain, returns if an inputted blockchain is a valid one
const isValidChain = (blockchainToValidate) => {
    //checks if the genesis block is valid if so return the JSON version of it
    const isValidGenesis = (block) => {
        return JSON.stringify(block) === JSON.stringify(genesisBlock);
    };
    if (!isValidGenesis(blockchainToValidate[0])) {
        return false; //If the first block is invalid, the blockchain cannt be valid
    }
    //Loops through each remaining block to see if it is a valid addition to the blockchain so far
    for (let i = 1; i < blockchainToValidate.length; i++) {
        if (!isValidNewBlock(blockchainToValidate[i], blockchainToValidate[i - 1])) {
            return false;
        }
    }
    return true;
};
//Replaces current blockchain with inputted blockchain
const replaceChain = (newBlocks) => {
    if (isValidChain(newBlocks) && newBlocks.length > getBlockchain().length) {
        //Checks to make sure the inputted blockchain is a valid one
        console.log('New Blockchain is valid, replacing old Blockchain with new one.');
        blockchain = newBlocks;
        p2p_1.broadcastLatest();
    }
    else {
        //Rejects the invalid blockchain
        console.log('New Blockchain is invalid, cannot replace it.');
    }
};
exports.replaceChain = replaceChain;
const generatenextBlockWithTransaction = (receiverAddress, amount) => {
    //Takes in a string and an amount and generates the amount of new blocks in the recievers address
    if (!transaction_1.isValidAddress(receiverAddress)) {
        //Checks to make sure there is a valid receiving address 
        throw Error('invalid address');
    }
    if (typeof amount !== 'number') {
        //Checks to make sure "amount" is a number
        throw Error('invalid amount');
    }
    const coinbaseTx = transaction_1.getCoinbaseTransaction(wallet_1.getPublicFromWallet(), getLatestBlock().index + 1);
    //Adds the transaction to the Public Wallet
    const tx = wallet_1.createTransaction(receiverAddress, amount, wallet_1.getPrivateFromWallet(), getUnspentTxOuts(), transactionPool_1.getTransactionPool());
    //Creates the transaction from the receivers end 
    const blockData = [coinbaseTx, tx];
    //Generates the next block 
    return generateRawNextBlock(blockData);
};
exports.generatenextBlockWithTransaction = generatenextBlockWithTransaction;
const findBlock = (index, previousHash, timestamp, data, difficulty) => {
    //Takes the information of a block and finds it
    let nonce = 0;
    while (true) {
        //Permanent for loop 
        const hash = calculateHash(index, previousHash, timestamp, data, difficulty, nonce);
        //Goes through the hashes 
        if (hashMatchesDifficulty(hash, difficulty)) {
            //Returns the block when the block is found
            return new Block(index, hash, previousHash, timestamp, data, difficulty, nonce);
        }
        //Simple counter
        nonce++;
    }
};
//send transaction method
const sendTransaction = (address, amount) => {
    //makes transaction
    const tx = wallet_1.createTransaction(address, amount, wallet_1.getPrivateFromWallet(), getUnspentTxOuts(), transactionPool_1.getTransactionPool());
    //add to pool
    transactionPool_1.addToTransactionPool(tx, getUnspentTxOuts());
    //broadcast
    p2p_1.broadCastTransactionPool();
    return tx;
};
exports.sendTransaction = sendTransaction;
// const updateMining = schedule.scheduleJob('0 0 * * *', () => {
//     var sql = "update accounts set balance = 500 where name='MiningLimit'";
//         // var sendSQL = "UPDATE accounts set balance = " + amount + " where name='" + send + "'";
//     connection.query(sql, (err, res) => {
//         if(err) {
//             connection.end();
//             return "FAILURE";
//         }
//         console.log("Refeshed Mining Limit");
//     });
// });
//for sending
const simpleSend = (name, send, amount) => {
    var sql = "SELECT name, balance from accounts where name='" + name + "'";
    var sql2 = "SELECT publickey, balance from accounts where name='" + send + "'";
    var result;
    var sendPublic;
    var sendAmount;
    var recievePublic;
    var recieveAmount;
    var amt = Number(amount);
    connection.query(sql, (err, res) => {
        if (err) {
            connection.end();
            return "FAILURE";
        }
        else {
            console.log('>> results: ', res);
            var string = JSON.stringify(res);
            console.log('>> string: ', string);
            var json = JSON.parse(string);
            console.log('>> json: ', json);
            console.log('>> Send publickey: ', json[0].publickey);
            console.log('>> Send balance: ', json[0].balance);
            sendPublic = json[0].name;
            sendAmount = Number(json[0].balance);
            var x = sendAmount - amt;
            updateSend(sendPublic, x);
        }
    });
    // connection.query(sql2, (err, res) => {
    //     if(err) {
    //         connection.end();
    //         return "FAILURE";
    //     }
    //     console.log('>> results: ', res );
    //     var string=JSON.stringify(res);
    //     console.log('>> string: ', string );
    //     var json =  JSON.parse(string);
    //     console.log('>> json: ', json);
    //     console.log('>> Recieve publickey: ', json[0].publickey);
    //     console.log('>> Recieve balance: ', json[0].balance);
    //     recievePublic = json[0].name;
    //     recieveAmount = Number(json[0].balance);
    //     var pay = recieveAmount + amt;
    // });
    var sendSQL = "UPDATE accounts set balance = " + amount + " where name='" + send + "'";
    // var sendSQL2 = "UPDATE accounts set balance = " + 0 + " where name='" + name + "'";
    //     connection.query(sendSQL, (err, res) => {
    //         if(err) {
    //             return "FAILURE";
    //         }
    //         console.log("UPDATE:"+JSON.stringify(res));
    //     });
    //     connection.end();
    // connection.query(sendSQL2, (err, res) => {
    //     if(err) {
    //         return "FAILURE";
    //     }
    //     console.log("UPDATE2:"+JSON.stringify(res));
    // });
    // connection.end();
    return "Success";
};
exports.simpleSend = simpleSend;
//mine REST function
const mine = (name) => {
    console.log("Starting Mine");
    var sql = "select balance from accounts where name='MiningLimit'";
    connection.query(sql, (err, res) => {
        if (err) {
            connection.end();
            return "FAILURE";
        }
        else {
            var string = JSON.stringify(res);
            var json = JSON.parse(string);
            var limit = json[0].balance;
            doMine(name, limit);
            doUpdate(name, limit);
        }
    });
    return "Success";
};
exports.mine = mine;
//updates the mining limit
const doMine = (name, limit) => {
    //console.log("Updating Limit:"+limit+"Name:"+name);
    var l = Number(limit);
    var MINEAMT = 50;
    if (l > 0 && name == 'DD') {
        var sql = "update accounts set balance = " + (l - MINEAMT) + " where name='MiningLimit'";
        connection.query(sql, (err, res) => {
            if (err) {
                connection.end();
                return "FAILURE";
            }
            else {
                console.log(res);
            }
        });
    }
};
//updates the account balance
const doUpdate = (name, limit) => {
    console.log("Getting Account Balance");
    var l = Number(limit);
    var MINEAMT = 50;
    var sql2 = "select balance from accounts where name='" + name + "'";
    connection.query(sql2, (err, res) => {
        if (err) {
            connection.end();
            return "FAILURE";
        }
        else {
            var string = JSON.stringify(res);
            var json = JSON.parse(string);
            var amt = json[0].balance;
            var a = Number(amt);
            var x = a + MINEAMT;
            updateSend(name, x);
        }
    });
};
//For transaction recieving
const simpleRecieve = (name, send, amount) => {
    var sql2 = "SELECT name, balance from accounts where name='" + send + "'";
    var recievePublic;
    var recieveAmount;
    connection.query(sql2, (err, res) => {
        if (err) {
            connection.end();
            return "FAILURE";
        }
        //console.log('>> results: ', res );
        var string = JSON.stringify(res);
        //console.log('>> string: ', string );
        var json = JSON.parse(string);
        //console.log('>> json: ', json);
        console.log('>> Recieve publickey: ', json[0].publickey);
        console.log('>> Recieve balance: ', json[0].balance);
        recievePublic = json[0].name;
        recieveAmount = Number(json[0].balance);
        var amt = Number(amount);
        var x = recieveAmount + amt;
        updateSend(recievePublic, x);
    });
    return "Rec";
};
exports.simpleRecieve = simpleRecieve;
const updateSend = (name, amt) => {
    console.log("DOING UPDATE");
    var sendSQL = "update accounts set balance = " + amt + " where name='" + name + "'";
    connection.query(sendSQL, (err, res) => {
        if (err) {
            connection.end();
            return "FAILURE";
        }
    });
    return "UPDATE";
};
//deal with transaction by adding to pool
const handleReceivedTransaction = (transaction) => {
    transactionPool_1.addToTransactionPool(transaction, getUnspentTxOuts());
};
exports.handleReceivedTransaction = handleReceivedTransaction;
// gets the unspent transaction outputs owned by the wallet
const getMyUnspentTransactionOutputs = () => {
    return wallet_1.findUnspentTxOuts(wallet_1.getPublicFromWallet(), getUnspentTxOuts());
};
exports.getMyUnspentTransactionOutputs = getMyUnspentTransactionOutputs;
//get account balance
const getAccountBalance = () => {
    return wallet_1.getBalance(wallet_1.getPublicFromWallet(), getUnspentTxOuts());
};
exports.getAccountBalance = getAccountBalance;
//checks to see if block has a valid hash
const hasValidHash = (block) => {
    //checks for valid hash if not then returns false
    if (!hashMatchesBlockContent(block)) {
        console.log('invalid hash, got:' + block.hash);
        return false;
    }
    //makes sure that the block difficulty is correct 
    if (!hashMatchesDifficulty(block.hash, block.difficulty)) {
        console.log('block difficulty not satisfied. Expected: ' + block.difficulty + 'got: ' + block.hash);
    }
    return true;
};
//checks to make sure hash matches block content via calculating the hash for the block
const hashMatchesBlockContent = (block) => {
    const blockHash = calculateHashForBlock(block);
    return blockHash === block.hash;
};
//# sourceMappingURL=blockchain.js.map