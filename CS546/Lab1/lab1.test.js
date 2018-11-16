const lab1 = require("./lab1");

console.log("");

console.log("Q1:")
console.log(lab1.questionOne([1, 2, 3])); 
console.log("Question 1 tests:");
console.log(lab1.questionOne([10, 12, 11])); 
console.log(lab1.questionOne([9, 15, 21])); 
console.log(lab1.questionOne([0, 0, -1])); 
console.log(lab1.questionOne([3, 1, 33])); 
console.log(lab1.questionOne([18, 19, 20])); 
console.log("\n");

console.log("Q2:")
console.log(lab1.questionTwo(7)); 
console.log("Question 2 tests:");
console.log(lab1.questionTwo(0)); 
console.log(lab1.questionTwo(-1)); 
console.log(lab1.questionTwo(34)); 
console.log(lab1.questionTwo(2)); 
console.log(lab1.questionTwo(15)); 
console.log("\n");

console.log("Q3:")
console.log(lab1.questionThree("Mr. and Mrs. Dursley, of number four, Privet Drive, were  proud  to  say  that  they  were  perfectly  normal,  thank you  very  much. They  were  the  last  people  youd  expect  to  be  involved in anything strange or mysterious, because they just didn't hold with such nonsense. \n Mr. Dursley was the director of a firm called Grunnings, which  made  drills.  He  was  a  big,  beefy  man  with  hardly  any  neck,  although he did have a very large mustache. Mrs. Dursley was thin and blonde and had nearly twice the usual amount of neck, which came in very useful as she spent so much of her time craning over garden fences, spying on the neighbors. The Dursleys had a small son  called  Dudley  and  in  their  opinion  there  was no finer boy anywhere.")); 
console.log("Question 3 tests:");
console.log(lab1.questionThree("Stevens Institute of Technology is the best school ever!"));
console.log(lab1.questionThree("The quick brown fox jumps over the lazy dog"));
console.log(lab1.questionThree("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
console.log(lab1.questionThree("Jacob Fallin"));
console.log(lab1.questionThree("This last example seems excessive but here we go."));
console.log("\n");

console.log("Q4:")
console.log(lab1.questionFour(10)); 
console.log("Question 4 tests:");
console.log(lab1.questionFour(-5)); 
console.log(lab1.questionFour(0)); 
console.log(lab1.questionFour(1)); 
console.log(lab1.questionFour(2)); 
console.log(lab1.questionFour(15)); 
console.log("\n");