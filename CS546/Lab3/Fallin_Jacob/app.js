//Jacob Fallin
//I Pledge My Honor That I Have Abided By The Stevens Honor System

const fileData = require("./fileData");
const textMetrics = require("./textMetrics");

async function main() {

	// console.log(textMetrics.createMetrics("Helllo, my -! This i's a great day to say helllo.Helllo! 2 3 4 234"));
	// //console.log(textMetrics.createMetrics("Helllo, my -! This is a great day to say helllo. riojrgiHelllo! 2 3 4 23"));
	// //console.log(textMetrics.createMetrics("H!hi  2 a"));


	console.log("chapter 1");
	try {
		console.log(await fileData.getFileAsJSON("chapter1.result.json"));
	} catch(e) {
		console.log("chapter1.result.json doesn't exist");
		console.log("Loading chapter1.txt");
		try {
			var c1 = await fileData.getFileAsString('chapter1.txt');
		} catch(e) {
			console.log(e);
		}
		console.log("Saving chapter1.txt");
		try {
			await fileData.saveStringToFile("chapter1.debug.txt", c1);
		} catch(e) {
			console.log(e);
		}
		console.log("Running TextMetric");
		var tm = textMetrics.createMetrics(c1);
		console.log(tm);
		console.log("Saving TextMetric");
		try {
			await fileData.saveJSONToFile("chapter1.result.json", tm);
		} catch(e) {
			console.log(e);
		}
	}

	console.log("\n");
	console.log("chapter 2");

	try {
		console.log(await fileData.getFileAsJSON("chapter2.result.json"));
	} catch(e) {
		console.log("chapter2.result.json doesn't exist");
		console.log("Loading chapter2.txt");
		try {
			var c2 = await fileData.getFileAsString("chapter2.txt");
		} catch(e) {
			console.log(e);
		}
		console.log("Saving chapter2.txt");
		try {
			await fileData.saveStringToFile("chapter2.debug.txt", c2);
		} catch(e) {
			console.log(e);
		}
		console.log("Running TextMetric");
		var tm = textMetrics.createMetrics(c2);
		console.log(tm);
		console.log("Saving TextMetric");
		try {
			await fileData.saveJSONToFile("chapter2.result.json", tm);
		} catch(e) {
			console.log(e);
		}
	}


	console.log("\n");
	console.log("chapter 3");

	try {
		console.log(await fileData.getFileAsJSON("chapter3.result.json"));
	} catch(e) {
		console.log("chapter3.result.json doesn't exist");
		console.log("Loading chapter3.txt");
		try {
			var c3 = await fileData.getFileAsString("chapter3.txt");
		} catch(e) {
			console.log(e);
		}
		console.log("Saving chapter3.txt");
		try {
			await fileData.saveStringToFile("chapter3.debug.txt", c3);
		} catch(e) {
			console.log(e);
		}
		console.log("Running TextMetric");
		var tm = textMetrics.createMetrics(c3);
		//console.log(tm);
		console.log("Saving TextMetric");
		try {
			await fileData.saveJSONToFile("chapter3.result.json", tm);
		} catch(e) {
			console.log(e);
		}
	}
}
main();
//console.log('tt');