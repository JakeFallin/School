const createMetrics = function createMetrics(text) {
    var letters = ['a','b','c','d','e','f','g','h','i','j','k','l',
    'm','n','o','p','q','r','s','t','u','v','w','x','y','z'];
    var vowels = ['a','e','i','o'];
    
    // Variables
    var totalLetters = 0, totalNonLetters = 0, totalVowels = 0, 
    totalConsonants = 0, totalWords = 0, uniqueWords = 0,
    longWords = 0, averageWordLength = 0;
    
    text = text.toLowerCase(); //Convert all letters to lower

    // totalLetters
    for(var i = 0; i < text.length; i++){
        for(var j = 0; j < letters.length; j++){
            if(text.charAt(i) == letters[j]) totalLetters++;
        }
    }

    // totalNonLetters
    totalNonLetters = text.length - totalLetters;
    
    // totalVowels
    for(var i = 0; i < text.length; i++){
        for(var j = 0; j < vowels.length; j++){
            if(text.charAt(i) == vowels[j]) totalVowels++;
        }
    }

    // totalConsonants
    totalConsonants = totalLetters - totalVowels; 
    
    text = text.replace(/[^a-z]+/g, " "); //Remove all non-letter
    text = " " + text + " "; //Guaruntee spaces on both ends at all times
    text = text.replace(/\s\s+/g, " "); //Remove all spaces, 2 and up.
    
    // totalWords
    for(var i = 1; i <= text.length; i++){
        if(text.charAt(i) == " "){
            totalWords++;
        }
    }

    // uniqueWords
    var words = [];
    var currWord = "";
    for(var i = 1; i < text.length; i++){
        if(text.charAt(i) == " "){
            words.push(currWord);
            currWord = "";
        }else{
            currWord = currWord + text.charAt(i);
        }
    }

    let uniqueArr = [...new Set(words)]; //https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Set
    uniqueWords = uniqueArr.length;
    
    // long words
    for(var i = 0; i < words.length; i++){
        if(words[i].length >= 6){
            longWords++;
        }
    }

    // averageWordLength
    averageWordLength = totalLetters / totalWords;

    // wordOccurences
    // Use similar solution from lab 2

    function wordOccurencesInArray(arr, word){
        var occurences = 0;
        for(var i = 0; i < arr.length; i++){
            if(arr[i] == word){
                occurences++;
            }
        }
        return occurences;
    }
    
    var wordOccurrences = {};
    var uniqueArrCount = [];

    for(var i = 0; i < uniqueArr.length; i++){
        uniqueArrCount.push(wordOccurencesInArray(words, uniqueArr[i]));
    }
    
    for(var i = 0; i < uniqueArr.length; i++){
        wordOccurrences[uniqueArr[i]] = uniqueArrCount[i];
    }

    var textMetricObj = {
        totalLetters, 
        totalNonLetters,
        totalVowels, 
        totalConsonants,
        totalWords,
        uniqueWords,
        longWords,
        averageWordLength,
        wordOccurrences
    }
    
    return textMetricObj;
}

// *** totalLetters: total number of letter characters in the text,
// *** totalNonLetters: total number of non-letters in the text,
// *** totalVowels: total number of vowels in the text (not counting y),
// *** totalConsonants: total number of consonants in the text (counting y),
// *** totalWords: total number of words in the text; a word is defined as any sequence of letters broken by any not-letter. For example, the phrase to-do is two words; a word does not start until a letter appears,
// *** uniqueWords: total number of unique words that appear in the lowercased text,
// *** longWords: number of words in the text that are 6 or more letters long; this is a total count of individual words, not unique words,
// *** averageWordLength: the average number of letters in a word in the text; this is counting the individual words, not unique words,
// wordOccurrences: a dictionary of each word and how many times each word occurs in the text.

module.exports = {
    createMetrics
}