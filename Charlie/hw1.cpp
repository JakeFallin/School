#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int8_t mystery1(int8_t a, int8_t b);

int8_t mystery1(int8_t a, int8_t b) {
	int8_t c = a -b;
	int8_t d = (c >> 7) & 1;
	int8_t mystery = a - c * d;
	return mystery;
 }

	//int8_t* xx = mystery2([1, 2, 3, 4], 0, 3);
 	//int8_t* yy = mystery2([1, 2, 3, 4], 1, 2);

 int8_t mystery2(int8_t v1, int8_t v2, int8_t v3, int8_t v4, int8_t i, int8_t j) {
 	v1 = v1 ^ v4;
 	v2 = v2 ^ v3;

 	printf("%d.%d\n", v1, v2);
 	return v1;
 }

 int8_t mystery3(int8_t x, int8_t y) {
 	int8_t s, c;
 	s = x ^ y; 
 	c = x & y;
 	while(c != 0) {
 		c = c << 1;
 		x = s;
 		y = c;
 		s = x ^ y;
 		c = x & y;
 	}
 	return s;
 }

 int main() {
 	int8_t x = mystery1(3, 7);
 	int8_t y = mystery1(8, 7);

	//int8_t* xx = mystery2([1, 2, 3, 4], 0, 3);
 	//int8_t* yy = mystery2([1, 2, 3, 4], 1, 2);
 	int8_t xx = mystery2(1, 2, 3, 4, 0, 3);
 	int8_t xxx = mystery3(3, 7);
 	int8_t yyy = mystery3(8, 7);

 	printf("\nMystery1: %d  .  %d\n", x, y);
 	//printf("\nMystery2: %d %d %d   .  %d %d %d \n", xx[0], xx[1], xx[2], yy[0], yy[1], yy[2]);  
 	printf("\nMystery3: %d  .  %d\n", xxx, yyy); 

 }