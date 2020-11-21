#include <stdio.h>

/* return the type of a char
 * 1 is digit
 * 2 is English
 * 3 is Others
 * 0 means error */
int get_type_of_char(char);

int main() {
	char c;
	int type;
	/* type description */
	char *type_dict[] = {
		"Error",
		"Digit",
		"English",
		"Others",
	};

	/* input a character */
	printf("Input one character: ");
	scanf("%c", &c);

	/* find the type of the character */
	type = get_type_of_char(c);

	/* show result */
	printf("You input %c, ASCII code is %d\n", c, c);
	printf("It is %s\n", type_dict[type]);

	return 0;
}

int get_type_of_char(char c) {
	if (c >= '0' && c <= '9') {
		return 1;
	}
	if (c >= 'A' && c <= 'Z') {
		return 2;
	}
	if (c >= 'a' && c <= 'z') {
		return 2;
	}
	return 3;
}
