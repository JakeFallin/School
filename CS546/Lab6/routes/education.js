const express = require("express");
const education = express();

education.get("/", async (req, res) => {

	res.json([
		{
		schoolName: "The British School in Tokyo",
		degree: "First Grade",
		favoriteClass: "Gym",
		favoriteMemory: "Riding my razor scooter on the way to class through the Shibuya Crossing every morning."
		},{
		schoolName: "ACS Cobham International School",
		degree: "Elementary School",
		favoriteClass: "ACS Cobham International School",
		favoriteMemory: "The international day where every country any student was from would be represented by some sort of room theme featuring their foods, music, clothing, and more."
		},{
		schoolName: "Ridgewood High School",
		degree: "Elementary School",
		favoriteClass: "Advanced Topics in Computer Science",
		favoriteMemory: "Winning the regional tournament with my hockey team."	
		}
	]);

});

module.exports = education;