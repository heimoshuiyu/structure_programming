/**********************

Author：Walter 1930006025
Date： 2020/11/02
Task no: In Class Test 1

Requirements:
 write a program that will input only up to 10 positive integer numbers; you should not allow the user to input more than 10 integers
 to end input type any number less than 0 will stop the program inputting or once 10 numbers have been inputted the program will output the results.
 output all odd numbers on one line and all even numbers on another line
 output the sum of all numbers, average, highest and lowest number

 example: input 3 5 2 5 1 4 -3

 output: 
 odd  numbers: 3 5 5 1
 even numbers: 2 4
 Sum of all numbers = 20
 total integer numbers = 6, 
 average = 3.333 (to three decimal points) 
 
************************/

#include <stdio.h>

int main() {

	int data[10];
	int len = 0;
	int sum = 0;
	int highest;
	int lowest;
	
	/* take input */
	for (
			int input;
			scanf("%d", &input), input >= 0;
			len++
	    ) {
		/* give warning if user input more than 10 numbers */
		if (len >= 10) {
			printf("Warning: You can not input more than 10 integer\n");
			break;
		}
		/* record the value */
		data[len] = input;
	}

	/* output odd number */
	printf("odd numbers: ");
	for (int i = 0; i < len; i++) {
		if (data[i] & 1) {
			printf("%d ", data[i]);
		}
	}
	printf("\n");
	
	/* output even number */
	printf("even numbers: ");
	for (int i = 0; i < len; i++) {
		if (!(data[i] & 1)) {
			printf("%d ", data[i]);
		}
	}
	printf("\n");

	/* output sum of all numbers */
	for (int i = 0; i < len; i++) {
		sum += data[i];
	}
	printf("Sum of all numbers = %d\n", sum);

	/* output total integer numbers */
	printf("total integer numbers = %d\n", len);

	/* output average */
	printf("average = %.3f\n", (double)sum/len);

	/* output highest number */
	highest = data[0];
	for (int i = 0; i < len; i++) {
		if (highest < data[i]) {
			highest = data[i];
		}
	}
	printf("highest number: %d\n", highest);

	/* output lowest number */
	lowest = data[0];
	for (int i = 0; i < len; i++) {
		if (lowest > data[i]) {
			lowest = data[i];
		}
	}
	printf("lowest number: %d\n", lowest);

	return 0;
}
