/*
 * Author: Walter
 * Student ID: 1930006025
 * inclasstest_2
 * Top3.cpp
 */

#include <stdio.h>

#define LENGTH 10

/* sort array with descending order */
void sortn(int data[], const int len);

int main() {
	/* make sure length of number is 10 */
	int numbers[] = {12, 23, 34, 13, 31, 45, 3, 37, 15, 25};
	sortn(numbers, LENGTH);

	/* show result */
	printf("The top 3 scores are:\n");
	printf("1st: %d\n", numbers[0]);
	printf("2nd: %d\n", numbers[1]);
	printf("3rd: %d\n", numbers[2]);

	/* output all the sorted numbers in descending order after the third */
	printf("Others: ");
	for (int i=3; i<LENGTH; i++) {
		printf("%d ", numbers[i]);
	}
	printf("\n");

	return 0;
}

void sortn(int data[], const int len) {
	/* bubble sort */
	for (int a=len; a>0; a--) {
		for(int b=0; b<a-1; b++) {
			if (data[b] < data[b+1]) {
				/* swap */
				int tmp = data[b];
				data[b] = data[b+1];
				data[b+1] = tmp;
			}
		}
	}
}
