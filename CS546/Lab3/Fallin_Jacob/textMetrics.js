//Jacob Fallin
//I Pledge My Honor That I Have Abided By The Stevens Honor System

let metric = exports = module.exports;

metric.createMetrics = (text) => {

	//console.log("text: " + text);
	//var words = text.split(" ");

	var sanitize = text;
	sanitize = sanitize.toLowerCase();
	sanitize = sanitize.replace(/[.,\/#!$%\^&\*;:{}=\-_`~()]/g,' ');
	sanitize = sanitize.replace(/['"?=]+/g, ' ');
	sanitize = sanitize.replace(/\\n\\t/g, " ")
	sanitize = sanitize.replace(/[0-9]/g, ' ');
	sanitize = sanitize.replace(/\s{2,}/g, " ");

	var words = sanitize.split(" ");
	words.splice(words.length-1, 1);

	//console.log(words);

	// for(let i in words) {
	// 	console.log("len:" + words[i].length);

	// 	for(let j = 0; j < words[i].length; j++) {
	// 		var t = words[i].charAt(j);
	// 		console.log(t);
	// 		if(!(t.match(/[a-z]/))) {
	// 			//console.log(t);
	// 				words.splice(i, 1);
	// 				break;
	// 		}
	// 	}
	// }
	//console.log(words);

	var unique = words.filter(function(elem,index,self) {
		return index==self.indexOf(elem);
	});

	//console.log("unique: " + unique);
	var nonletters = [];
	var m = {
		totalLetters:0,
		totalNonLetters:0,
		totalVowels:0,
		totalConsonants:0,
		totalWords:0,
		uniqueWords:0,
		longWords:0,
		averageWordLength:0,
		wordOccurences:{}
	};

	var occurences = {};

	for(let i = 0; i < text.length; i++) { 
		var temp = text.charAt(i);
		console.log(temp);
		if(temp.match(/[a-z]/i)) {
			m.totalLetters++;
		} else {
			m.totalNonLetters++;
			nonletters.push(temp);
		}
		if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') {
			m.totalVowels++;
		} else if(temp){
		}

	}
	for(let i in words) {
		if(words[i].length>= 6) {
			m.longWords++;
		}
	}
		console.log(nonletters);

	m.uniqueWords = unique.length;
	m.totalWords = words.length;
	m.averageWordLength = m.totalLetters / m.totalWords;
	for(let i in unique) {
		occurences[unique[i]] = 0;
	}
	
	for(var item in occurences) {
		//console.log('key:' + item + ' value:'+occurences[item]);
		for(var i in words) {
			//console.log("words" + words[i] + "   item:" + item) ;
			if(words[i] == item) {
				occurences[item]++;
			}
		}
	}
	//console.log(occurences);
	m.wordOccurences = occurences;
	m.totalConsonants = m.totalLetters - m.totalVowels;
	return m;
	//console.log(m);
}

