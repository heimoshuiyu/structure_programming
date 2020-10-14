/* Programmer Walter Chinese: 陈永源
 * Student ID: 1930006025
 * Date: 2020.10.14
 * Task no: Week_2_Task_4
 * Requirments:
 * Write a program following the control flow
 */

#include <stdio.h>

int main() {
	float height, weight;

	printf("Input height (cm): ");
	scanf("%f", &height);

	printf("Input weight (kilo): ");
	scanf("%f", &weight);

	if ((height - 105.0f) > (weight + 20.0f)) {
		printf("You are too slim\n");
	} else {
		float tmp = height - 105.0;
		if (((weight - 10.0f) < tmp) && (tmp <= (weight + 20.0f))) {
			printf("You are fit\n");
		} else {
			printf("You are too fat\n");
		}
	}

	return 0;

}
