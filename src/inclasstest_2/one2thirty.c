/*
 * Author: Walter 
 * Student ID: 1930006025
 * inclasstest_2
 * one2thirty.cpp
 */

#include <stdio.h>

int main() {
	/* value to print */
	int value;

	/* half */
	value = 2;
	/* loop for 5 row */
	for (int row=0; row<5; row++) {
		/* loop for each column */
		for (int col=0; col<row+1; col++) {
			printf("%d,", value);
			/* increase value */
			value += 2;
		}
		/* new line at the end */
		printf("\n");
	}

	/* half */
	value = 29;
	/* loop for 5 row */
	for (int row=5; row>0; row--) {
		/* loop for each column */
		for (int col=row; col>0; col--) {
			printf("%d,", value);
			/* decrease value */
			value -= 2;
		}
		/* new line at the end */
		printf("\n");
	}
	return 0;
}
