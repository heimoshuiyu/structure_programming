/* Programmer Walter Chinese: 陈永源
 * Student ID: 1930006025
 * Date: 2020.10.14
 * Task no: Week_2_Task_2
 * Requirments:
 * Write a program following control flow
 */

#include <stdio.h>

int main() {
	int n;
	printf("Input an integer: ");
	scanf("%d", &n);
	if (!(n > 0)) {
		n = -n;
	}
	n = n + n;
	printf("n is: %d\n", n);
	return 0;
}
