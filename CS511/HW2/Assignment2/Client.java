//Jacob Fallin
//I pledge my honor that I have abided by the stevens honor system

package Assignment2;

import java.util.List;
import java.util.LinkedList;
import java.util.Random;
import java.util.Map;
import java.util.HashMap;

public class Client {

	private int id;
	private List<Exercise> routine;
	private static Random rand;


	public Client(int id) {
		this.id = id;
		this.routine = new LinkedList<Exercise>();
	}

	public void addExercise(Exercise e) {
		routine.add(e);
	}

	public static Client generateRandom(int id, Map<WeightPlateSize,Integer> noOfWeightPlates) {
		rand = new Random();
		Client client = new Client(id);
		//number of unique exercises per client
		int r = rand.nextInt(6) + 15;
		for(int i = 0; i < r; i++) {
			client.routine.add(Exercise.generateRandom(noOfWeightPlates));
		}
		return client;
	}

	//where the magic happens
	public void doWorkout() throws InterruptedException {

		for(Exercise exercise : routine) {

			Gym.mutex.acquire();
			//tell that the exercise has begun
			System.out.println("Client:" + id + " started " + exercise.toString());
			int exerciseNum = 0;

			switch(exercise.getAt()) {
				case LEGPRESSMACHINE: 
					exerciseNum = 0;
				case BARBELL: 
					exerciseNum = 1;
				case HACKSQUATMACHINE: 
					exerciseNum = 2;
				case LEGEXTENSIONMACHINE: 
					exerciseNum = 3;
				case LEGCURLMACHINE: 
					exerciseNum = 4;
				case LATPULLDOWNMACHINE: 
					exerciseNum = 5;
				case PECDECKMACHINE: 
					exerciseNum = 6;
				case CABLECROSSOVERMACHINE: 
					exerciseNum = 7;
				default:
					//System.out.println("other");
			}
			//acquire semaphore
			Gym.apparatusType[exerciseNum].acquire();
			Map<WeightPlateSize, Integer> weight = exercise.getWeight();
			//get the plates for use
			for(WeightPlateSize wps : weight.keySet()) {
				if(wps == WeightPlateSize.SMALL_3KG) {
					for(int i = 0; i < weight.get(wps); i++) {
						Gym.n_SmallPlates.acquire();
					}
				}
				else if(wps == WeightPlateSize.MEDIUM_5KG) {
					for(int i = 0; i < weight.get(wps); i++) {
						Gym.n_MediumPlates.acquire();
					}
				}
				else if(wps == WeightPlateSize.LARGE_10KG) {
					for(int i = 0; i < weight.get(wps); i++) {
						Gym.n_LargePlates.acquire();
					}
				//this shouldnt occur
				} else {
					System.out.println("FATAL");
					return;
				}
			}
			//release
			Gym.mutex.release();
			//to prevent many problems
			Thread.sleep(exercise.getDuration() + 100);
			Gym.apparatusType[exerciseNum].release();
			//release correct semaphore
			for(WeightPlateSize wps : weight.keySet()) {
				if(wps == WeightPlateSize.SMALL_3KG) {
					for(int i = 0; i < weight.get(wps); i++) {
						Gym.n_SmallPlates.release();
					}
				}
				else if(wps == WeightPlateSize.MEDIUM_5KG) {
					for(int i = 0; i < weight.get(wps); i++) {
						Gym.n_MediumPlates.release();
					}
				}
				else if(wps == WeightPlateSize.LARGE_10KG) {
					for(int i = 0; i < weight.get(wps); i++) {
						Gym.n_LargePlates.release();
					}
				}
				//this shouldnt occur
				else {
					System.out.println("FATAL");
					return;
				}
			}
			System.out.println("Client: " + id + " finished " + exercise.toString());
		}

		System.out.println("Client " + id + " finished all exercises");

	}
}