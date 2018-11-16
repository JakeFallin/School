//Jacob Fallin
//I pledge my honor that I have abided by the stevens honor system

package Assignment2;

import java.util.Random;

public enum WeightPlateSize {
	SMALL_3KG, MEDIUM_5KG, LARGE_10KG;

	//random enum
	static WeightPlateSize getRandomWeightPlateSize() {
		return WeightPlateSize.values()[new Random().nextInt(WeightPlateSize.values().length)];
	}
}