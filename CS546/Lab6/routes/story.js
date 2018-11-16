const express = require("express");
const story = express();

story.get("/", async (req, res) => {

	res.json({
		storyTitle:"The Rodeo",
		story:"Last spring break, two of my good friends and I decided to go to Costa Rica for a week. We had a fantastic time, everything was great. We had this friend/guide named Abraham that had helped us book things like ATVing and Surfing and he invited us to go out with him.\nAbraham comes over to our AirBNB and hangs out for while and then tells us to hop in a cab to go to a neighbouring town. Now, Costa Rica is safe, but where he took us is what I would call, off the beaten path.\nWhen we arrive, I realize we are in the middle of a carnival, which was really cool to experience. We stopped and got a few beers and then he led us to the main attraction, the Bull Fight. Imagine this place, made only of hand cut tree logs and planks, and we are the only foriegners in sight.\nHe motions to me, asking if we want to go into the VIP area, and of course we respond yes. Abraham then proceeds to lead us through the gate that the bulls come out. Already I knew we were out of place. Picture 3 guys, in flip flops and pastel shorts holding beers, and about 100 costa rican young guys who seem like they are pros. Before I know it, a bell rings and out roars a 1500 beast. I start panicking and ask Abraham what to do. All he can seem to say is that if the Bull comes near you, climb on the ledge and hope for the best. So we did. At one point the bull was about 3 inches from mauling my thigh. We powered through about 8 different, increasingly angry bulls before finally making it out barely alive.\nAnd it turns out the night before we went, someone had died in the ring doing the exact same thing."
	});

});

module.exports = story;