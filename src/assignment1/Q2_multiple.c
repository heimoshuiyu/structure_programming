/*
 * Author: Walter
 * Student ID: 1930006025
 * Q2_mutiple.cpp
 */

#include <stdio.h>

int main() {
	int input;

	/* input a integer */
	printf("Input a integer: ");
	scanf("%d", &input);

	/* check if mutiple of 3 */
	if (input % 3 == 0) {
		printf("%d is mutiple of 3\n", input);
	}

	/* check if mutiple of 2 */
	if (input % 2 == 0) {
		printf("%d is mutiple of 2\n", input);
	}

	return 0;
}
