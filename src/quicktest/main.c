/*
 * Programmer: Walter 1930006025 陈永源
 * Date 2020/10/26
 * Requirment
 * print * depend on user input
 */

#include <stdio.h>

int main() {
	
	int line;

	/* ask use to input an integer */
	printf("Please input an integer: ");
	scanf("%d", &line);

	/* check input number */
	if (line < 0) {
		printf("Fatal: number can not be nagetive!\n");
		return 1;
	}

	/* loop for each line */
	for (int i = 1; i <= line; i++) {
		
		/* loop for char */
		for (int c = 0; c < i; c++) {
			printf("*");
		}

		/* new line at the end of each line */
		printf("\n");
	}

	return 0;
}
