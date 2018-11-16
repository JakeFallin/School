const express = require('express');
const router = express.Router();
const data = require('../data/users');
const path = require('path');
const bcrypt = require('bcrypt');

router.get('/', async (req,res) => {
	if(req.cookies.AuthCookie && req.cookies) {
		res.redirect('/private');
	} else {
		res.render('static/signin', {layout: false});
	}
})

router.get('/logout', async (req, res) => {
	res.clearCookie("AuthCookie");
	res.render('static/signin', {layout: false, messages: "Sucsessfully logged out."});
})

router.get('/private', async (req, res) => {
	if(req.cookies.AuthCookie && req.cookies) {
		const cookie = await data.findID(req.cookies.AuthCookie);
		if(cookie) {
			res.render('layouts/main', {
				username: cookie.username,
				firstname: cookie.firstname,
				lastname: cookie.lastname,
				profession: cookie.profession,
				bio: cookie.bio
			});
		} else {
			res.status(404).json({messages: "Unknown user"});
		}
	} else {
		res.status(403).render('static/failure', {layout: false});
	}
})

router.post('/login', async (req, res) => {
	const username = req.body.username;
	const cookie = await data.findUsername(username);
	if(!(cookie)) {
		res.render('static/signin', {layout: false, messages: "Username is invalid"});
		return;
	}
	const password = req.body.password;
	const hashSlashingSlasher = await bcrypt.compare(password, cookie.hashedPassword);
	if(!(hashSlashingSlasher)) {
		res.render('static/signin', {layout: false, messages: "Password is invalid"});
	} else {
		res.cookie('AuthCookie', cookie._id, { expires: new Date(Date.now() + 900000) });
		res.redirect('/private');
	}
})

module.exports = router;

