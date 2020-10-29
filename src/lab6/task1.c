#include <stdio.h>

int main() {

	char c;
	unsigned int count = 0;

	/* read char until get a new line */
	while (c=getchar(), c!='\n') {

		/* count the number of a */
		if (c=='a') {
			count++;
		}

	}

	/* give the count of a */
	printf("%d\n", count);

	return 0;

}
