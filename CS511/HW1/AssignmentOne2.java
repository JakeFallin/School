import java.util.ArrayList;
import java.util.List;

public class AssignmentOne {

	public static List<Integer> lprimes(List<Integer[]> intervals) {

		List<PrimeFinder> primeFinder = new ArrayList<PrimeFinder>();
		List<Integer> primes = new ArrayList<Integer>();
		List<Thread> threads = new ArrayList<Thread>();

		int increasing1 = 0, increasing2 = 0;
		for(int i = 0; i < intervals.size(); i++) {
			Integer[] range = intervals.get(i);
			if(range[0] > increasing1) {
				increasing1 = range[0];
			} else {
				System.out.println("Error increasing1");
			}
			if(range[1] > increasing2) {
				increasing2 = range[1];
			} else {
				System.out.println("Error increasing2");
			}
			if(range[0] < 2 || range[1] < 2) {
				System.out.println("Error range");
			}

			PrimeFinder pf = new PrimeFinder(range[0], range[1]);
			primeFinder.add(pf);
			Thread t = new Thread(pf);
			t.start();
			threads.add(t);
		}

		for(int i = 0; i < threads.size(); i++) {
			Thread t = threads.get(i);
			try {
				t.join();
			} catch(a e) {
				System.out.println(e);
			}
		}

		for(int i = 0; i < primeFinder.size(); i++) {
			PrimeFinder pf = primeFinder.get(i);
			primes.addAll(pf.getPrimesList());
		}

		return primes;
	}

	public static void main(String[] args) {

		if((args.length > 1) && (args.length % 2 == 0)) {

			List<Integer[]> l = new ArrayList<Integer[]>();
			int i = 0;
			while(i < args.length - 1) {
				Integer[] x = {Integer.valueOf(args[i]), Integer.valueOf(args[++i])};
				if(x[0] > x[1]) {
					System.out.println("Error bounds");
					return;
				}
				l.add(x);
			}
			AssignmentOne one = new AssignmentOne();
			List<Integer> p = one.lprimes(l);
			System.out.println("List of Primes:\n " + p);


		} else {
			System.out.println("Argument Error");
			return;
		}
	}
}