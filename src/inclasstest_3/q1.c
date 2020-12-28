/*
 * Author: Walter
 * Student ID: 1930006025
 * Assignment_2_task_3
 * Requirement:
 * Write a recursive function int strchar(char str[], char ch)
 * Count the occurrences of the ch in the str
 */

#include <stdio.h>

int strchar(char str[], char ch);

int main() {
	char str[256] = {0};
	char c;
	printf("Enter str\n");
	scanf("%s", str);
	printf("Enter char\n");
	scanf("%c", &c);
	printf("%d\n", strchar(str, c));
	return 0;
}

int strchar(char str[], char ch) {
	/* exit if str is at the end */
	if (!str[0]) {
		return 0;
	}
	/* count and compare the next character */
	return (str[0]!=ch) + strchar(str + 1, ch);
}
