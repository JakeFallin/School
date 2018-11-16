import java.util.ArrayList;
import java.util.List;

public class PrimeFinder implements Runnable {

	private Integer start;
	private Integer end;
	private List<Integer> primes;

	//constructor
	public PrimeFinder(Integer startNum, Integer endNum) {
		start = startNum;
		end = endNum;
		primes = new ArrayList<Integer>();
	}

	//return primes
	public List<Integer> getPrimesList() {
		return primes;
	}

	//quicker way to check if a number is prime
	public Boolean isPrime(int s) {
		if(s < 0) {
			return false;
		}
		for(int i = 2; i <= s/2; i++) {
			if(s % i == 0) {
				return false;
			}
		}
		return true;
	}

	//actually run
	public void run() {
		for(int i = start; i <= end; ++i) {
			if(isPrime(i)) {
				primes.add(i);
			}
		}

	}
}