const express = require("express");
const router = express.Router();
const data = require("../data");
const pal = data.palindrome;

router.post("/", (req,res) => {
	const result = req.body['text-to-test'];
	if(result) {
		const value = pal.palindromeChecker(result);
		let succ = "";
		if(value) {
			succ = "success";
		} else {
			succ = "failure";
		}
		const display = {
			title: "The Palindrome Results!",
			text: result,
			isPalindrome: value,
			class: succ
		};
		res.render("result", display);
	} else {
		const display = {
			title: "Error 400",
			description: "No text was entered"
		};
		res.status(400).render("error", display);
	}
});

router.get("/", (req, res) => {
	const display = {
		title: "Error 400",
		description: "No text was entered"
	};
	res.status(400).render("error", display);
});
module.exports = router;