/*
 * Programmer: Walter 陈永源
 * Student ID: 1930006025
 * Date 2020/22/10
 * Task: Week_5_Task_4
 * Requirments:
 * Write a program to satisfy the floowing condition
 * 1. under 1000
 * 2. multiple of 5, and 
 * 3. not multiple of 7
 */

#include <stdio.h>

int main() {

	int result=0;
	
	/* satisfy first condition under 1000 */
	for (int i=0; i<1000; i++) {

		/* satisfy second condition multiple of 5 */
		if (i % 5) {
			continue;
		}

		/* satisfy third condition not multiple of 7 */
		if (!(i % 7)) {
			continue;
		}

		/* add the number */
		result += i;
	}

	printf("%d\n", result);
}

