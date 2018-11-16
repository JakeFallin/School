//Jacob Fallin
//I Pledge My Honor That I Have Abided By The Stevens Honor System

const bluebird = require("bluebird");
const Promise = bluebird.Promise;
const fs = bluebird.promisifyAll(require("fs"));

async function getFileAsString(path) {
	if(!path) {
		throw Error("No file path");
	}
	if(typeof(path) !== 'string') {
		throw Error("Path isn't string");
	}
	let fd = await fs.readFileAsync(path, "utf-8");
	return fd;
}

async function getFileAsJSON(path) {
	if(!path) {
		throw Error("No file path");
	}
	if(typeof(path) !== 'string') {
		throw Error("Path isn't string");
	}	
	let fd = await getFileAsString(path);
	let json = await JSON.parse(fd);
	return json;
}

async function saveStringToFile(path, text) {
	if(!path) {
		throw Error("No file path");
	}
	if(typeof(path) !== 'string') {
		throw Error("Path isn't string");
	}	
	if(!text) {
		throw Error("No text");
	}
	if(typeof(text) !== 'string') {
		throw Error("text isn't string");
	}
	await fs.writeFileAsync(path, text);
	return true;
}

async function saveJSONToFile(path, obj) {
	if(!path) {
		throw Error("No file path");
	}
	if(typeof(path) !== 'string') {
		throw Error("Path isn't string");
	}
	if(!obj) {
		throw Error("No object");
	}
	if(typeof(obj) !== 'object') {
		throw Error("obj isn't object");
	}
	let text = JSON.stringify(obj);
	await saveStringToFile(path, text);
	return true;
}

module.exports = {
	getFileAsString,
	getFileAsJSON,
	saveStringToFile,
	saveJSONToFile
};