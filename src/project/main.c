#include <stdio.h>
#include <stdlib.h>

void function_list();
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
		printf("\t\t|    Welcome to Use My Personal note book       |\n");
		printf("\t\t|                                               |\n");
		printf("\t\t|   Please Select The Following Functions:      |\n");
		printf("\t\t|                                               |\n");
		printf("\t\t|   $$ 1 -Add Person                            |\n");
		printf("\t\t|   $$ 2 -Remove Person                         |\n");
		printf("\t\t|   $$ 3 -Update Person                         |\n");
		printf("\t\t|   $$ 4 -Find and View Person details          |\n");
		printf("\t\t|   $$ 5 -All female / male                     |\n");
		printf("\t\t|   $$ 6 -List by name A-z / Z-a                |\n");
		printf("\t\t|   $$ 7 -By age                                |\n");
		printf("\t\t|   $$ 8 -Quit -                                |\n");
		printf("\t\t|                                               |\n");
		printf("\t\t|###############################################|\n");

		printf("\n\n\n\n");

		printf("Please Input Number:");
		scanf("%d", &i);

		switch (i) {

			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				Quit();
				break;
			default:
				printf("Number should between 1 -- 8!\n");
		}

	} while (1);
}
