/*
 * Programmer: Walter 陈永源
 * Student ID: 1930006025
 * Date 2020/22/10
 * Task: Week_5_Task_2
 * Requirments:
 * Write a program using nested for statement to print out this:
 * *******
 * ******
 * *****
 * ****
 * ***
 * **
 * *
 */

#include <stdio.h>

int main() {

	/* loop for line */
	for (int i=7; i>0; i--) {

		/* loop for char */
		for (int s=0; s<i; s++) {
			printf("*");
		}

		/* printf \n at the end of line */
		printf("\n");
	}

	return 0;
}
