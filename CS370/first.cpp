#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	long n;
	cin >> n;

	while(n % 2 == 0) {
		printf("%d", 2);
		n = n/2;
	}

for(int i = 3; i <= sqrt(n); i = i+2) {
	while (n%i == 0)
        {
            printf("%ld", i);
            n = n/i;
        }
    }
     if (n > 2)
        printf ("%ld", n);
}


