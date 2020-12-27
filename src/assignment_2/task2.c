/*
 * Author: Walter
 * Student ID: 1930006025
 * Assignment_2_task_2
 * Requirement:
 * Write a program to find a16 using recursive function.
 */

#include <stdio.h>

#define NDEBUG
#include <assert.h>

int get_a_by_n(int n);

int main() {
	printf("a16 is %d\n", get_a_by_n(16));
	return 0;
}

int get_a_by_n(int n) {
	/* check n>0, disable this by using #define NODEBUG for performance */
	assert(n > 0);

	/* a1 = 2 */
	if (n == 1) {
		return 2;
	}

	return 2 * get_a_by_n(n - 1) + 1;
}
