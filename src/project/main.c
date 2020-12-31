#include <stdio.h>
#include <stdlib.h>
void function_list();
void Import() {
	printf("Here is the Import function\n");
	getchar();
	getchar();
	/*
	   You write code here about the Import
	   */
}
void Delete() {
	printf("Here is the Delete function\n");
	getchar();
	getchar();

	/*
	   You write code here about the Delete
	   */
}
void Calculate() {
	printf("Here is the Calculate function\n");
	getchar();
	getchar();
	/*
	   You write code here about the Calculate
	   */
}
void Export() {
	printf("Here is the Export function\n");
	getchar();
	getchar();
	/*
	   You write code here about the Export
	   */
}
void Quit() { exit(0); }

int main() {

	function_list();

	return 0;
}

void function_list() {
	int i;

	do {

		printf("\t\t|###############################################|\n");
		printf("\t\t|                                               |\n");
		printf("\t\t|    Welcome to Use Grade management System     |\n");
		printf("\t\t|                                               |\n");
		printf("\t\t|   Please Select The Following Functions:      |\n");
		printf("\t\t|                                               |\n");
		printf("\t\t|   $$ 1 -Import grades for a course            |\n");
		printf("\t\t|   $$ 2 -Delete a course                       |\n");
		printf("\t\t|   $$ 3 -Calculate GPA                         |\n");
		printf("\t\t|   $$ 4 -Export file with GPA                  |\n");
		printf("\t\t|   $$ 5 -Quit                                  |\n");
		printf("\t\t|                                               |\n");
		printf("\t\t|###############################################|\n");

		printf("\n\n\n\n");

		printf("Please Input Number:");
		scanf("%d", &i);

		switch (i) {

			case 1:
				Import();
				break;
			case 2:
				Delete();
				break;
			case 3:
				Calculate();
				break;
			case 4:
				Export();
				break;
			case 5:
				Quit();
				break;
			default:
				printf("Number should between 1 -- 5!\n");
		}

	} while (1);
}
