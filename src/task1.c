/* Programmer Walter Chinese: 陈永源
 * Student ID: 1930006025
 * Date: 2020.10.14
 * Task no: Week_2_Task_1
 * Requirments:
 * Write a program to read two integers.
 * Output two results:
 * one is about integer divided by
 * another is float divided by
 */

#include <stdio.h>

int main() {
	int inputi, value;
	float inputf;
	printf("Input two integer: ");
	scanf("%d %d", &inputi, &value);
	inputf = (float)inputi;

	float result;
	result = inputf / value;
	printf("Integer: %d divided by %d is %d\n", inputi, value, (int)result); 
	printf("Float: %d divided by %d is %.2f\n", inputi, value, result);

	return 0;
}
