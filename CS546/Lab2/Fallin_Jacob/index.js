const geometry = require("./geometry");
const utilities = require("./utilities");
    // deepEquality,
    // uniqueElements,
    // countOfEachCharacterInString
console.log("volumeOfRectangularPrism Test");
console.log(geometry.volumeOfRectangularPrism(1,2,3));
console.log(geometry.volumeOfRectangularPrism(0,0,0));
console.log(geometry.volumeOfRectangularPrism(1000,0,-1000));
console.log(geometry.volumeOfRectangularPrism(10,10,10));
console.log(geometry.volumeOfRectangularPrism(4,40,400));

console.log();

console.log("surfaceAreaOfRectangularPrism Test");
console.log(geometry.surfaceAreaOfRectangularPrism(1,2,3));
console.log(geometry.surfaceAreaOfRectangularPrism(-1,0,1));
console.log(geometry.surfaceAreaOfRectangularPrism(1,1,1));
console.log(geometry.surfaceAreaOfRectangularPrism(10,20,30));
console.log(geometry.surfaceAreaOfRectangularPrism(100,200,300));

console.log();

console.log("volumeOfSphere Test");
console.log(geometry.volumeOfSphere(0));
console.log(geometry.volumeOfSphere(-10));
console.log(geometry.volumeOfSphere(10));
console.log(geometry.volumeOfSphere());
console.log(geometry.volumeOfSphere(999));

console.log();

console.log("surfaceAreaOfSphere Test");
console.log(geometry.surfaceAreaOfSphere(0));
console.log(geometry.surfaceAreaOfSphere(-50));
console.log(geometry.surfaceAreaOfSphere(22));
console.log(geometry.surfaceAreaOfSphere(68));
console.log(geometry.surfaceAreaOfSphere(419));

console.log();

const a = 1;
const b = 2;
const c = 3;
const d = 1;
const e = "1";
const f = "2";
console.log("deepEquality Test");
console.log(utilities.deepEquality(a,b));
console.log(utilities.deepEquality(a,e));
console.log(utilities.deepEquality(a,d));
console.log(utilities.deepEquality(c-a,b));
console.log(utilities.deepEquality(e,f));

console.log();

console.log("uniqueElements Test");
console.log(utilities.uniqueElements(["a", "b", "c", "d", "e", "f"]));
console.log(utilities.uniqueElements([]));
console.log(utilities.uniqueElements(["a", "a", "a", "a", "a", "b"]));
console.log(utilities.uniqueElements(["a", 1, "b", 1, "c", 1]));
console.log(utilities.uniqueElements(["1", 1, "2", 2, "3", 3]));

console.log();

console.log("countOfEachCharacterInString Test");
console.log(utilities.countOfEachCharacterInString("jake fallin is so cool"));
console.log(utilities.countOfEachCharacterInString("YESTERDAY YOU SAID TOMMOROW, Don't let your dreams be memes, Don't meme your dreams be beams, Jet fuel won't melt tomorrow's memes, DON'T LET YOUR STEEL MEMES BE JET DREAMS"));
console.log(utilities.countOfEachCharacterInString("abcdefghijklmnopqrstuvwxyz"));
console.log(utilities.countOfEachCharacterInString("Hey guys. Me and my friends have always dreamed about joining the NA LCS. We created a ranked team, climbed up all the ranks till we got Silver 5. We have finally done it. Time for NA LCS!"));
console.log(utilities.countOfEachCharacterInString(""));

