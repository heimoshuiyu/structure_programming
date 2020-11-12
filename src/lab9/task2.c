/*
 * Programmer: Walter 1930006025
 * Student ID: 1930006025
 * Date: 2020.11.12
 * Task no: Week_7_Task_2
 * Requirements:
 * Change the following program such that it will
 * find and print out the biggest value in
 * the array value.
 */

#include <stdio.h>

/* return the highest number in array a[],
 * array size should be n */
float get_highest(float a[], int n);

int main() {
	float value[4] = {2.5, 1, 1.2, 5.2};

	/* get the highest number in value[4] */
	float highest = get_highest(value, 4);

	/* outpu the highest number */
	printf("highest number is %.1f\n", highest);

	return 0;
}

float get_highest(float a[], int n) {

	/* take first number */
	float highest = a[0];

	/* loop to find the highest number */
	for (int i=0; i<n; i++) {
		if (highest < a[i]) {
			highest = a[i];
		}
	}

	return highest;
}
