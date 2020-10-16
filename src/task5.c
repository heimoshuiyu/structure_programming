/* Programmer Walter Chinese: 陈永源
 * Student ID: 1930006025
 * Date: 2020.10.14
 * Task no: Week_2_Task_5
 * Requirments:
 * Use switch statement to implement a program
 * that can read and transfer a GPA grade to
 * GPA point.
 */

#include <stdio.h>

int main() {
	char grade;
	float point;

	printf("Input a GAP grade: ");
	scanf("%c", &grade);

	/* convert UPPER CASE to lower case
	 * 97 is A
	 * 102 is F */
	if (grade>=97 && grade<=102) {
		grade -= 32;
	}

	/* output GPA point */
	switch (grade) {
		case 'A':
			point = 4.0f;
			break;
		case 'B':
			point = 3.0f;
			break;
		case 'C':
			point = 2.0f;
			break;
		case 'D':
			point = 1.0f;
			break;
		case 'F':
			point = 0.0f;
			break;
		default:
			printf("Fatal: invalid input %c\n", grade);
			return 1;
	}

	printf("%.2f\n", point);

	return 0;
}
