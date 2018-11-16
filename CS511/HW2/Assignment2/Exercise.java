//Jacob Fallin
//I pledge my honor that I have abided by the stevens honor system
	
package Assignment2;

import java.util.Random;
import java.util.HashMap;
import java.util.Map;

public class Exercise {

	private ApparatusType at;
	private Map<WeightPlateSize, Integer> weight;
	private int duration;
	private static Random rand;

	public Exercise(ApparatusType at, Map<WeightPlateSize, Integer> weight, int duration) {
		this.at = at;
		this.weight = weight;
		this.duration = duration;
	}

	public ApparatusType getAt() {
		return at;
	}
	public Map<WeightPlateSize, Integer> getWeight() {
		return weight;
	}
	public int getDuration() {
		return duration;
	}

	public static Exercise generateRandom(Map<WeightPlateSize, Integer> m) {

		rand = new Random();
		//seems sufficient
		int duration = 300 + rand.nextInt(500);

		ApparatusType at = ApparatusType.getRandomApparatusType();

		//initalize so we know what to replace
		Map<WeightPlateSize, Integer> weight = new HashMap<>();
		for(WeightPlateSize w : m.keySet()) {
			weight.put(w, 0);
		}
		//no more than 10 exercises
		for(int i = 0; i < rand.nextInt(10) + 1; i++) {
			WeightPlateSize wps = WeightPlateSize.getRandomWeightPlateSize();
			//to make sure there is always 1
			weight.replace(wps, 1 + weight.get(wps));
		}

		return new Exercise(at, weight, duration);
	}

	public String toString() {
		return "ApparatusType:" + getAt().toString() +  
		" | Weight:" + getWeight().toString() + 
		" | Duration:" + getDuration();
	}
}