const questionOne = function questionOne(arr) {
    var sum = 0;
    for(var i = 0; i < arr.length; i++) {
        sum += (arr[i]*arr[i]);
    }
    return sum;
}

const questionTwo = function questionTwo(num) {
    if(num <= 0) {
        return 0;
    }
    if(num <= 2) {
        return 1;
    }
    return questionTwo(num-1) + questionTwo(num-2);
}

const questionThree = function questionThree(text) {
    var undercase = text.toLowerCase();
    var vowels = 0;
    for(var i = 0; i < undercase.length; i++) {
        var c = undercase.charAt(i);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels++;
        }
    }
    return vowels;
}

const questionFour = function questionFour(num) {
    var fact;
    if(num < 0) {
        return 'NaN';
    } else if(num == 0) {
        return 1;
    } else {
        fact = num;
        for(var i = num-1; i >= 1; i--) {
            fact *= i;
        }
    }
    return fact;20
}

module.exports = {
    firstName: "Jacob",
    lastName: "Fallin",
    studentId: "10418656",
    questionOne,
    questionTwo,
    questionThree,
    questionFour
};
