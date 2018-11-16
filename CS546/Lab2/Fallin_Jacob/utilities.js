
const deepEquality = function deepEquality(obj1, obj2) { 

	try {
		if(obj1 === Object(obj1) || obj2 === Object(obj2)) {
			throw("Not an Object Error");
		}
		var first = Object.getOwnPropertyNames(obj1);
		var second = Object.getOwnPropertyNames(obj2);

		if(!(first.length == second.length)) {
			return false;
		}

		for(var i = 0; i < first.length; i++) {

			var test = first[i];
			if(obj1[test] !== obj2[test]) {
				return false;
			}
		}
		return true;
	} catch(e) {
		return e;
	}

}

const uniqueElements = function uniqueElements(arr) {
	try {
		if(!(arr.constructor === Array) {
			throw("Empty Array");
		}
		//taking advantage of Sets in addition to the spread operator
		var unique = [...new Set(arr)];
		return unique.length;
	} catch(e) {
		return e;
	}
}

const countOfEachCharacterInString = function countOfEachCharacterInString(str) {
	try {
		if(str.length <= 0) {
			throw("Invalid String Length Error");
		}
		if(typeof str === 'string') {
			throw("Not a String Error");
		}


		var dict = {};

		var unique = String.prototype.concat(...new Set(str));
		var result = unique.split("");
		var count = new Array((result.length)+1).join('0').split('').map(parseFloat)

		for(var i = 0; i < str.length; i++) {
			var c = str.charAt(i);
			for(var j = 0; j < result.length; j++) {
				if(result[j] == c) {
					//console.log("C: " + c + " J: " + j);
					count[j] += 1;
					//console.log("Count: " + count[j]);
				}
			}
		}
		for(var k = 0; k < count.length; k++) {
			dict[result[k]] = count[k];
			//console.log(count[k]);
		}
		
		return dict;
	} catch(e) {
		return e;
	}

}

module.exports = {
    deepEquality,
    uniqueElements,
    countOfEachCharacterInString
};