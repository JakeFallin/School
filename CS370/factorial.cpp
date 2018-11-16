#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
using namespace std;

void dofact(int num);

int main() {
  long num;
  int nums;
  cin >> nums;
  int nums2 = nums;
  int j = 0;
  int foo [nums];
  while(j < nums) {
    int n;
    cin >> n;
    foo[j] = n;
    j++;
  }
  int k = 0;
  while(k < nums2) {
    dofact(foo[k]);
    k++;
  }
  

    // double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    // cout << "running time (s): " << elapsed_secs << endl;
    // double ms = elapsed_secs * 1000;
    // cout << "running time (ms): " << ms << endl;
}

void dofact(int num) {
 double kd = log(num) / log (5);
 int k = round(kd);
 int sum = 0;
  
  for(int i = 1; i <= k; i++) {
    sum = sum + (num / (pow(5, i)));
  }
    cout << sum << "\n";


  }

