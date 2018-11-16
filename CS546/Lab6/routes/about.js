const express = require("express");
const about = express();

about.get("/", async (req, res) => {

	res.json({
		name:'Jacob Fallin',
		cwid:'10418656',
		biography:'It feels weird to try and summarize my life in a short biography for someone I dont even know, but lets see how this goes\nI was born in Summit, NJ. Pretty normal life nothing interesting really happened. I have a brother whose 4.5 years younger than me. I moved to Japan when I was 5 and then England after that for 5 years. We moved back to Ridgewood after a while because my Dad died of a Glioblastoma. Moved around a lot after that to Maryland, Connecticut, but never for long. Ended up back in New Jersey and decided to go to College close by. Now Im here. In college, I have found a love of programming, working for a startup and then a large investment banking firm. Not sure where life is going to take me after this.',
		favoriteShows:["South Park", "Breaking Bad", "Game of Thrones", "True Detective"],
		hobbies:["Skiing", "Music", "Longboarding", "Poker"]
	});

});

module.exports = about;