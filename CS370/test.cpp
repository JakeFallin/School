#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
using namespace std;

int main() {
	clock_t begin = clock();
	long n;
	cin >> n;
	while(n % 2 == 0) {
		printf("%d ", 2);
		n = n / 2;
	}
	for(int i = 3; i <= sqrt(n); i = i + 2) {
		while (n % i == 0) {
            printf("%d ", i);
            n = n / i;
        }
    }
    if (n > 2) {
       printf ("%ld \n", n);
    }

  	clock_t end = clock();
  	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  	cout << "running time (s): " << elapsed_secs << endl;
  	double ms = elapsed_secs * 1000;
  	cout << "running time (ms): " << ms << endl;
}


