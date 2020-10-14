/* Programmer Walter Chinese: 陈永源
 * Student ID: 1930006025
 * Date: 2020.10.14
 * Task no: Week_2_Task_3
 * Requirments:
 * Write a program to read amount of Euro
 * and change to HK dollar or RMB
 * depends on user's choice
 */

#include <stdio.h>

int main() {
	double result;
	int euro, type;
	const char *typeDict[] = {
		"HK dollar",
		"RMB",
	};

	printf("Please input amount in Euro: ");
	scanf("%d", &euro);
	printf("Please choose the currency converting to (1: HK dollar, 2: RMB): ");
	scanf("%d", &type);

	switch (type) {
		case 1:
			result = (double)euro * 8.1f;
			break;
		case 2:
			result = (double)euro * 7.2f;
			break;
		default:
			printf("Fatal: Unknown type");
			return 1;
	}

	printf("%d euro = %.2f %s\n", euro, result, typeDict[type-1]);

	return 0;
}
