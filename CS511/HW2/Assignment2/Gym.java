//Jacob Fallin
//I pledge my honor that I have abided by the stevens honor system

package Assignment2;

import java.util.concurrent.Semaphore;
import java.util.Random;
import java.util.Set;
import java.util.HashSet;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;

public class Gym implements Runnable {

	private static final int GYM_SIZE = 30;
	private static final int GYM_REGISTERED_CLIENTS = 10000;
	private Map<WeightPlateSize, Integer> noOfWeightPlates;
	private Set<Integer> clients;
	private ExecutorService executor;

	static Semaphore mutex;
	static Semaphore apparatusType[];
	static Semaphore n_SmallPlates;
	static Semaphore n_MediumPlates;
	static Semaphore n_LargePlates;

	private static Random rand;


	public Gym() {

		//initialization
		clients = new HashSet<Integer>(GYM_REGISTERED_CLIENTS);
		noOfWeightPlates = new HashMap<WeightPlateSize, Integer>();
 		
 		//initialization
		mutex = new Semaphore(1);
		apparatusType = new Semaphore[ApparatusType.values().length];
		
		//initialization
		noOfWeightPlates.put(WeightPlateSize.SMALL_3KG, 110);
		noOfWeightPlates.put(WeightPlateSize.MEDIUM_5KG, 90);
		noOfWeightPlates.put(WeightPlateSize.LARGE_10KG, 75);
		
		//initialization
		n_SmallPlates = new Semaphore(noOfWeightPlates.get(WeightPlateSize.SMALL_3KG));
		n_MediumPlates = new Semaphore(noOfWeightPlates.get(WeightPlateSize.MEDIUM_5KG));
		n_LargePlates = new Semaphore(noOfWeightPlates.get(WeightPlateSize.LARGE_10KG));

		rand = new Random();
		
		//initialization
		for(int i = 0; i < GYM_SIZE; i++) {
			clients.add(rand.nextInt(GYM_REGISTERED_CLIENTS));
		}

		//initialization
		for(int i = 0; i < apparatusType.length; i++) {
			apparatusType[i] = new Semaphore(5);
		}
	}

	//actually run all the clients
	public void run() {
		for(int clientID : clients) {
			executor = Executors.newFixedThreadPool(GYM_SIZE);
			executor.execute(new Runnable() {
				public void run() {
					Client client = Client.generateRandom(clientID, noOfWeightPlates);
					try { 
						client.doWorkout();
					} catch(InterruptedException e) {
						e.printStackTrace();
					}
				}
			});
			executor.shutdown();
		};
	}
 
}