/*
 * Author: Walter 陈永源
 * Student ID: 1930006025
 * Task: Week_5_Lab_6_Task_3
 * Requirement: 
 * Write a program  to read a sequence of positive integers
 * and sort them in ascending order. You can use -1 to
 * indicate the  end of input sequence.
 */

#include <stdio.h>

/* define how many integers can be store in data array
 * default is 256 */
#define MAX_STORAGE_NUM 256

int main() {
	int len = 0;
	int data[MAX_STORAGE_NUM] = {-1};

	/* read user input */
	/* store user input to data array */
	/* record the len of data */
	for (
			int input;
			/* call getchar() once after scanf()
			 * allow comma between integer */
			scanf("%d", &input), getchar(), input!=-1;
			len++
	    ) {
		/* check input positive */
		if (input < 0) {
			printf("Fatal: Input data %d must be positive\n",
					input);
			return 1;
		}
		/* check input data size */
		if (len >= MAX_STORAGE_NUM) {
			printf("Fatal: MAX_STORAGE_NUM is set to %d\n",
					MAX_STORAGE_NUM);
			/* print the data array for debug */
			for (int i=0; i<MAX_STORAGE_NUM; i++) {
				printf("%d ", data[i]);
			}
			return 2;
		}
		/* store data */
		data[len] = input;
	}

	/* bubble sort */
	for (int n=len-1; n>0; n--) {
		for (int i=0; i<n; i++) {
			/* ascending order */
			if (data[i] > data[i+1]) {
				/* swap */
				int tmp = data[i];
				data[i] = data[i+1];
				data[i+1] = tmp;
			}
		}
	}

	/* output result */
	for (int i=0; i<len; i++) {
		printf("%d", data[i]);

		/* print comma between integer */
		if (i < len-1) {
			printf(", ");
		}
	}
	/* new line at the end of result */
	printf("\n");

	return 0;
}
