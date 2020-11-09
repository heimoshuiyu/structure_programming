#include <stdio.h>

int main() {
	char data[] = "Frans Conen";
	for (unsigned int i = 0; data[i]; i++) {
		printf("%d ", data[i]);
	}
	return 0;
}
