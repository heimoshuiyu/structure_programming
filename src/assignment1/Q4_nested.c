/*
 * Author: Walter
 * Student ID: 1930006025
 * Q4_nested.cpp
 */

#include <stdio.h>

int main() {
	/* loop for line length */
	for (int length=10; length>0; length-=2) {
		/* loop for each character */
		for (int i=0; i<length; i++) {
			/* output depends one odd or even number */
			if (i&1) {
				printf("*");
			} else {
				printf("#");
			}
		}
		/* \n at the end of each line */
		printf("\n");
	}
	return 0;
}
