"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
//to parse the server requests
const bodyParser = require("body-parser");
//web framework
const express = require("express");
//js util
const _ = require("lodash");
//import methods from blockchain file
const blockchain_1 = require("./blockchain");
//import p2p methods
const p2p_1 = require("./p2p");
//import transaction pool methods
const transactionPool_1 = require("./transactionPool");
//import wallet methods
const wallet_1 = require("./wallet");
//setup the http port to 3001
const httpPort = parseInt(process.env.HTTP_PORT) || 3001;
//setup the p2p port 6001
const p2pPort = parseInt(process.env.P2P_PORT) || 6001;
//init the http server with port 3001
const initHttpServer = (myHttpPort) => {
    //usee express as a web framework
    const app = express();
    //with json
    app.use(bodyParser.json());
    //use req and result
    app.use((err, req, res, next) => {
        //if theres an error return 400
        if (err) {
            res.status(400).send(err.message);
        }
    });
    //***
    // /setupAccoun?name=myName&root=0
    app.get('/mine/:name', (req, res) => {
        var name = req.params.name;
        const r = blockchain_1.mine(name);
        res.send({ 'Mining': 'Success' });
    });
    app.get('/setupAccount/:name', (req, res) => {
        var name = req.params.name;
        const r = wallet_1.setupAccount(name);
        res.send({ 'Account': r });
    });
    app.get('/sendTransaction/:name/:send/:amount', (req, res) => {
        var name = req.params.name;
        var send = req.params.send;
        var amount = req.params.amount;
        var r = blockchain_1.simpleSend(name, send, amount);
        var s = blockchain_1.simpleRecieve(name, send, amount);
        res.send({ 'Transaction': 'Success' });
    });
    //if /blocks then return the blockchain 
    app.get('/blocks', (req, res) => {
        res.send(blockchain_1.getBlockchain());
    });
    //if /block:hash find the block with the designated hash
    app.get('/block/:hash', (req, res) => {
        const block = _.find(blockchain_1.getBlockchain(), { 'hash': req.params.hash });
        res.send(block);
    });
    //if /transaction/:id find the transaction with the specified id
    app.get('/transaction/:id', (req, res) => {
        //convert blockchain into map so we can search by id
        const tx = _(blockchain_1.getBlockchain())
            .map((blocks) => blocks.data)
            .flatten()
            .find({ 'id': req.params.id });
        res.send(tx);
    });
    //if /address/:address find the transactions associated with this address
    app.get('/address/:address', (req, res) => {
        const unspentTxOuts = _.filter(blockchain_1.getUnspentTxOuts(), (uTxO) => uTxO.address === req.params.address);
        res.send({ 'unspentTxOuts': unspentTxOuts });
    });
    //if /unspentTransactionOutputs then just return getUnspentTxOuts
    app.get('/unspentTransactionOutputs', (req, res) => {
        res.send(blockchain_1.getUnspentTxOuts());
    });
    //if /unspentTransactionOutputs then get own transaction unspent outputs
    app.get('/myUnspentTransactionOutputs', (req, res) => {
        res.send(blockchain_1.getMyUnspentTransactionOutputs());
    });
    //NEEDED permissions
    //if /mineRawBlock then try to mine a new raw block
    app.post('/mineRawBlock', (req, res) => {
        if (req.body.data == null) {
            res.send('data parameter is missing');
            return;
        }
        //generates next raw block and as long as not null send it
        const newBlock = blockchain_1.generateRawNextBlock(req.body.data);
        if (newBlock === null) {
            res.status(400).send('could not generate block');
        }
        else {
            res.send(newBlock);
        }
    });
    //if /mineBlock mines next block
    app.post('/mineBlock', (req, res) => {
        const newBlock = blockchain_1.generateNextBlock();
        if (newBlock === null) {
            res.status(400).send('could not generate block');
        }
        else {
            res.send(newBlock);
        }
    });
    //if /balance return account balance
    app.get('/balance', (req, res) => {
        const balance = blockchain_1.getAccountBalance();
        res.send({ 'balance': balance });
    });
    //if /address then return account address
    app.get('/address', (req, res) => {
        const address = wallet_1.getPublicFromWallet();
        res.send({ 'address': address });
    });
    //if /mineTransaction then generate new block with transaction and return it
    app.post('/mineTransaction', (req, res) => {
        const address = req.body.address;
        const amount = req.body.amount;
        try {
            //generate block with your address and the amount
            const resp = blockchain_1.generatenextBlockWithTransaction(address, amount);
            res.send(resp);
        }
        catch (e) {
            console.log(e.message);
            res.status(400).send(e.message);
        }
    });
    //if /sendTransaction then send transaction and return the proof
    app.post('/sendTransaction', (req, res) => {
        try {
            const address = req.body.address;
            const amount = req.body.amount;
            if (address === undefined || amount === undefined) {
                throw Error('invalid address or amount');
            }
            const resp = blockchain_1.sendTransaction(address, amount);
            res.send(resp);
        }
        catch (e) {
            console.log(e.message);
            res.status(400).send(e.message);
        }
    });
    //if /transactionPool just return the transaction pool
    app.get('/transactionPool', (req, res) => {
        res.send(transactionPool_1.getTransactionPool());
    });
    //if /peers find all connected peers and return it
    app.get('/peers', (req, res) => {
        res.send(p2p_1.getSockets().map((s) => s._socket.remoteAddress + ':' + s._socket.remotePort));
    });
    //if addPeers connects a new pper
    app.post('/addPeer', (req, res) => {
        p2p_1.connectToPeers(req.body.peer);
        res.send();
    });
    //if /stop stops the server
    app.post('/stop', (req, res) => {
        res.send({ 'msg': 'stopping server' });
        process.exit();
    });
    //setup the server and prints to console thats its working
    app.listen(myHttpPort, () => {
        console.log('Listening http on port: ' + myHttpPort);
    });
};
//init the servers
initHttpServer(httpPort);
p2p_1.initP2PServer(p2pPort);
//init the wallet
wallet_1.initWallet();
//# sourceMappingURL=main.js.map