/*
 * Programmer: Walter 陈永源
 * Student ID: 1930006025
 * Date 2020/22/10
 * Task: Week_5_Task_3
 * Requirments:
 * Write a program using nested for statement to print out this:
 * *********
 * =======
 * *****
 * ===
 * *
 */

#include <stdio.h>

int main() {
	char c='=';

	/* loop for line */
	for(int length=9; length>0; length -= 2) {

		/* switch * and = */
		c = (c == '*') ? '=' : '*';

		for (int i=0; i<length; i++) {
			printf("%c", c);
		}

		/* print \n at the end of line */
		printf("\n");
	}
}

