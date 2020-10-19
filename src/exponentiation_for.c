#include <stdio.h>

int main() {
	int base, n;
	long long result = 1;
	
	printf("Input the base: ");
	scanf("%d", &base);

	printf("Input the n: ");
	scanf("%d", &n);

	/* do the calc */
	for (int count=0; count<n; count++) {
		result *= base;
	}

	printf("Result is %Ld\n", result);
}
