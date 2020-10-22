/*
 * Programmer: Walter 陈永源
 * Student ID: 1930006025
 * Date 2020/22/10
 * Task: Week_5_Task_5
 * Requirments:
 * Write a program to print the floowing output
 * *******
 * ******~
 * *****~~
 * ****~~~
 * ***~~~~
 * **~~~~~
 * *~~~~~~
 */

#include <stdio.h>

int main() {

	/* loop for how many * in the left of one line */
	for(int left=7; left>0; left--) {
		
		/* print * */
		for (int i=0; i<left; i++) {
			printf("*");
		}

		/* print ~ */
		for (int i=7; i>left; i--) {
			printf("~");
		}

		/* print new line at the end */
		printf("\n");
	}

	return 0;
}
