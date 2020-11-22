/*
 * Author: Walter
 * Student ID: 1930006025
 * Q2_mutiple.cpp
 */

#include <stdio.h>

int main() {
	int input;
	int result = 0;

	/* input a integer */
	printf("Input a integer: ");
	scanf("%d", &input);

	/* check if mutiple of 3 */
	if (input % 3 == 0) {
		result += 3;
	}

	/* check if mutiple of 2 */
	if (input % 2 == 0) {
		result += 2;
	}

	/* show result */
	switch (result) {
		case 0: printf("%d - is not a multiple of 2 or 3\n", input); break;
		case 2: printf("%d - is a multiple of 2\n", input); break;
		case 3: printf("%d - is a multiple of 3\n", input); break;
		case 5: printf("%d - is a multiple of 2 and 3\n", input); break;
		default:
			printf("Error, result is %d\n", result);
			return 1;
	}

	return 0;
}
