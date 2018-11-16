#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
using namespace std;

int main(int argc, char** argv) {
	clock_t begin = clock();
	long num =(long) argv[0];
	while(num % 2 == 0) {
		printf("%d ", 2);
		num = num / 2;
	}
	for(int i = 3; i <= sqrt(num); i = i + 2) {
		while (num % i == 0) {
            printf("%d ", i);
            num = num / i;
        }
    }
    if (num > 2) {
       printf ("%ld \n", num);
    }

  	clock_t end = clock();
  	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  	cout << "running time (s): " << elapsed_secs << endl;
  	double ms = elapsed_secs * 1000;
  	cout << "running time (ms): " << ms << endl;
}


