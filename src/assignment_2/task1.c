/*
 * Author: Walter
 * Student ID: 1930006025
 * Assignment_2_task_1
 * Requirement:
 * A program include main and inverse function.
 */

#include <stdio.h>

#define DATA_LENGTH 20
#define END_SIGN -1

/* inverse Data list, with the length of Data[] */
void inverse(int Data[], int Data_len);

int main() {
	int Data[DATA_LENGTH];
	int Data_len=0;

	printf("Input numbers, end with %d: ", END_SIGN);
	/* read number from stdin until END_SIGN */
	for (int tmp; (scanf("%d", &tmp), tmp!=END_SIGN); Data_len++) {
		Data[Data_len] = tmp;
	}

	/* inverse */
	inverse(Data, Data_len);

	/* print out the elements in array */
	for (int i=0; i<Data_len; i++) {
		printf("%d ", Data[i]);
	}
	printf("\n");

	return 0;
}

/* inverse function, for example, int Data[] = {1, 2, 3, 4}
 * then swap Data[0] <> Data[3] and Data[1] <> Data[2] */
void inverse(int Data[], int Data_len) {
	for (int i=0; i<Data_len/2; i++) {
		/* find inverse i */
		int inverse_i = Data_len - 1 - i;
		/* swap */
		int tmp = Data[inverse_i];
		Data[inverse_i] = Data[i];
		Data[i] = tmp;
	}
}
