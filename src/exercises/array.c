#include <stdio.h>

#define length 5

int main() {

	/* init var */
	int values[length] = {0};
	int total = 0;

	for (int i=0; i<length; i++) {

		/* ask user to input value */
		printf("Input an integer of of value[%d]: ", i);
		scanf("%d", &values[i]);

	}

	for (int i=0; i<length; i++) {
		
		/* print out the number */
		printf("values[%d] = %d\n", i, values[i]);

		/* calculate the total number */
		total += values[i];

	}

	printf("Total number is %d\n", total);

	return 0;
}
