#include <stdio.h>

int main() {
	char lName[81], fName[81];
	int id_num;
	puts("Enter the last name, firstname, ID number"
			"separated by spaces ");
	puts("then press Enter \n");
	scanf("%s%s%d", lName, fName, &id_num);
	printf("3 items entered: %s %s %d\n",
			fName, lName, id_num);
	return 0;
}
