/*
 * Author: Walter
 * Student ID: 1930006025
 * Q5_sequence.cpp
 */

#include <stdio.h>

#define MAX_STORE_NUM 256

/* bubble sort data with len */
void sortn(int data[], const int len);

int main() {
	int data[MAX_STORE_NUM];
	int len=0;
	
	/* read input until -1 */
	for (
			int value;
			scanf("%d", &value), getchar(), value!=-1;
	    ) {
		/* discarded negative number */
		if (value <= 0) {
			continue;
		}

		/* record data, increase len at the same time */
		data[len++] = value;
	}

	/* sort data */
	sortn(data, len);

	/* print result */
	for (int i=0; i<len; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	return 0;
}

void sortn(int data[], const int len) {
	/* bubble sort */
	for (int a=len; a>0; a--) {
		for(int b=0; b<a-1; b++) {
			if (data[b] > data[b+1]) {
				/* swap */
				int tmp = data[b];
				data[b] = data[b+1];
				data[b+1] = tmp;
			}
		}
	}
}
