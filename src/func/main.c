#include <stdio.h>

int input(const char word[]);
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);

int main() {
	int value_one, value_two;
	printf("Type two numbers");
	value_one = input(" value one = ");
	printf("\n");
	value_two = input(" value two = ");
	printf("\n");
	printf(" Added:\n");
	printf(" %d + %d = %d\n",
			value_one, value_two,
			add(value_one, value_two)
			);
	printf(" subtracted:\n");
	printf(" %d - %d = %d\n",
			value_one, value_two,
			subtract(value_one, value_two)
			);
	printf(" multiplied:\n");
	printf(" %d * %d = %d\n",
			value_one, value_two,
			multiply(value_one, value_two)
			);
	printf(" divided\n");
	printf(" %d / %d = %.3f\n",
			value_one, value_two,
			divide(value_one, value_two)
			);
	
	return 0;
}

int input(const char word[]) {
	int value;
	printf("%s", word);
	scanf("%d", &value);
	return value;
}

int add(int a, int b) {
	return a + b;
}

int subtract(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

double divide(int a, int b) {
	return (double)a / b;
}
