//Jacob Fallin
//I pledge my honor that I have abided by the stevens honor system

package Assignment2;

import java.util.Random;

public enum ApparatusType {
	LEGPRESSMACHINE, BARBELL, HACKSQUATMACHINE, LEGEXTENSIONMACHINE, LEGCURLMACHINE, LATPULLDOWNMACHINE, PECDECKMACHINE, CABLECROSSOVERMACHINE;

	//random enum
	static ApparatusType getRandomApparatusType() {
		return ApparatusType.values()[new Random().nextInt(ApparatusType.values().length)];
	}
}