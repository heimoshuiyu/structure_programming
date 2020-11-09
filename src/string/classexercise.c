#include <stdio.h>

int main() {
	char str[15] = "unix and c";
	printf("%s", str);
	printf("\n");
	str[6] = '\0';
	printf("%s", str);
	printf("\n");
	str[2] = '%';
	printf("%s", str);
	printf("\n");
	return 0;
}
