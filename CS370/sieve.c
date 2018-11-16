

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {


    int nums;
    int a, b;

    cin >> nums;
    for(int x = 0; x < nums; x++) {
        cin >> a >> b;
    


    bool lowprimes[b-a];
    for(int k = a; k < b; k++) {
        lowprimes[k] = true;
    }

    
 

    for(int i = a; i*i <= b; i++) {
        if(lowprimes[i] == true) {
            for(int j = i*2; j <= b; j+= i) {
              lowprimes[j] = false;
            }
        }
    }
    for(int i = 2; i < b; i++) {
        if(lowprimes[i] && i > a && i < b) {
            printf("Prime=%d ",i);
        } 
    }
}

    return 0;
}