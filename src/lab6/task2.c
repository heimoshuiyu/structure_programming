#include <stdio.h>

int main() {

	/* declare a string not exceed 49 */
	const unsigned short LENGTH = 50;
	char s[LENGTH];
	unsigned int count = 0;

	/* read the string in */
	scanf("%s", s);

	/* count the number of a */
	for (unsigned short i=0; i<LENGTH; i++) {
		if (s[i] == 'a') {
			count++;
		}
	}

	/* print the result */
	printf("%d\n", count);

	return 0;

}
