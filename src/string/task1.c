#include <stdio.h>
#include <string.h>

/* Assume that the length of each word in the sentences
 * is less than 20 */
#define MAX_LENGTH 20 + 1


int main() {
	char word[MAX_LENGTH];
	unsigned int count = 0;
	static char END[] = "End";

	while (1) {
		/* read input word */
		scanf("%s", word);
		getchar();

		/* compare word with End */
		if (strcmp(word, END) == 0) {
			break;
		}

		/* count the number of words */
		count++;
	}

	/* show result */
	printf("%d\n", count);

	return 0;
}
