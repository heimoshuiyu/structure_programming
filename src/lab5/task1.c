/*
 * Programmer: Walter 陈永源
 * Student ID: 1930006025
 * Date 2020/22/10
 * Task: Week_5_Task_1
 * Requirments:
 * Write a program calculate the odd number and
 * even number from 1 to 100 (inclusive)
 */

#include <stdio.h>

int main() {

	/* calc the even number sum */
	unsigned int result=0;
	for (unsigned int i = 1; i<=100; i++) {
		/* pass if not even number */
		if (!(i&1)) {
			continue;
		}

		result += i;
	}
	printf("sum even number from 1 to 100: %d\n", result);

	/* reset result */
	result = 0;

	for (unsigned int i = 1; i<=100; i++) {
		/* pass if even number */
		if (i&1) {
			continue;
		}

		result += i;
	}
	printf("sum odd number from 1 to 100: %d\n", result);

	return 0;
}
