const express = require("express");
const router = express.Router();

router.get("/", (req,res) => {
	var display = {
		title: "The Best Palindrome Checker in the World!",
		//h1: "The Best Palindrome Checker in the World!",
		//p: "This is a Palindrome"
	}
	res.render("form", display);
});
module.exports = router;