#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 64

void my_strcpy(char *, const char *);
void my_strcat(char *, const char *);
void show(const char *);

int main() {
	char str1[MAX_LENGTH], str2[MAX_LENGTH];
	char dest1[MAX_LENGTH*2], dest2[MAX_LENGTH*2];

	/* input */
	printf("Input the first word: ");
	scanf("%s", str1);
	getchar();
	printf("Input the second word: ");
	scanf("%s", str2);
	getchar();

	/* method 1 */
	strcpy(dest1, str1);
	strcat(dest1, str2);

	/* method 2 */
	my_strcpy(dest2, str1);
	my_strcat(dest2, str2);

	/* show result */
	printf("method 1 result: %s\n", dest1);
	printf("method 2 result: %s\n", dest2);

	if (strcmp(dest1, dest2) == 0) {
		printf("They are the same\n");
	} else {
		printf("They are not the same\n");
	}
	return 0;
}

void my_strcpy(char dest[], const char src[]) {
	for (unsigned int i = 0; src[i]; i++) {
		dest[i] = src[i];
	}
}

void my_strcat(char dest[], const char src[]) {
	unsigned int dest_i = 0;

	for (; dest[dest_i]; dest_i++) {}

	for (unsigned int i = 0; src[i]; i++, dest_i++) {
		dest[dest_i] = src[i];
	}
}

/* for debug */
void show(const char src[]) {
	printf("%s: ", src);
	for (unsigned int i = 0; src[i]; i++) {
		printf("%d ", src[i]);
	}
}
