#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int arr[6][6];
    for(int arr_i = 0; arr_i < 6; arr_i++){
       for(int arr_j = 0; arr_j < 6; arr_j++){
          
          scanf("%d",&arr[arr_i][arr_j]);
       }
    }
    int sum = -1000;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
                    int top3 = arr[i][j]+arr[i][j+1]+arr[i][j+2];
                    int middle1 = arr[i+1][j+1];
                    int bottom3 = arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
                    if(top3 + middle1 + bottom3 > sum) {
                        sum = top3 + middle1 + bottom3;
                    }       
            }
        }
    printf("%d",sum);
    return 0;
}
