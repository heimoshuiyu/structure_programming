/*
 * Author: Walter
 * Student ID: 1930006025
 * inclasstest_2
 * a2Z.cpp
 */

#include <stdio.h>

int main() {
	int multiple;

	/* input a multiple */
	printf("Input a multiple ");
	scanf("%d", &multiple);

	/* show result */
	printf("Letters with the ASCII value that are a multiple of %d\n", multiple);

	/* show result from a-z */
	for (char i='a'; i<='z'; i++) {
		if (i % multiple == 0) {
			printf("%c ", i);
		}
	}
	/* new line at the end */
	printf("\n");

	/* show result from a-z */
	for (char i='A'; i<='Z'; i++) {
		if (i % multiple == 0) {
			printf("%c ", i);
		}
	}
	/* new line at the end */
	printf("\n");

	return 0;
}
