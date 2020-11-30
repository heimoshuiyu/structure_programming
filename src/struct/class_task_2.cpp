/*****
Author:Nina
Date: 2020/04/27
Description:
Write a program to read students ’ information and sort
according to the names. Assume that each student has the
following information: name, score and major. The total
number of students can be inputted from the keyboard but
will not exceed 50.
If you use array to store the information, you need to check if the input number is
beyond the array upper limit.

**************/
#include<stdio.h>

#include<string.h>

struct Student {// each student will have three elements: name, major, score
	char name[10];
	float score;
	char major[10];
};//Please always define the structure outside the main function, so that each sub function can use it.

void sort(Student stu[], int n);// sort the student by name, no need to return, so the return type is void
void sort_2(Student stu[], int n);
void sort_by_score(Student stu[], int n);
void printList(Student stu[], int n);
void printList(Student stu[], int n, char major[]);

int main() {
  Student stu[] = {{"Eric", 70.0, "APSY"}, {"Donna", 62.0, "CST"}, {"Carol", 34.0, "CST"},{"Bob", 45.0, "CST"},   {"Adam", 23.0, "CST"},  {"Frieda", 30.0, "FM"},};
	int num = 6;
	/*
	printf("Please input the number of students(<=50):");
	scanf("%d", &num);
	while(num>50){// check if the input number is beyond the array upper limit
		
		printf("Warning: Please input a number which does not exceed 50\n");
		printf("Input again:");
		scanf("%d", &num);

	}
	printf("Please input students' information like this:\n");
	printf("----------\n");
	printf("Nina 90 cst\n");
	printf("----------\n");

	for(int i=0; i<num; i++){
		scanf("%s%f%s",stu[i].name, &stu[i].score, stu[i].major);// read information
	}	
	*/
	sort(stu, num);// call the sort function to sort the students by name. Notice that we use the array name as the input
	printf("Sorted Alphabetically\n");
	printList(stu, num);
	printf("\n");
	sort_2(stu, num);
	printf("Sorted by score Highest to Lowest\n");
	printList(stu, num);
	while (1) {
		int a;
		printf("Select the a menu\n0 to exit\n1 Order by name (a-Z)\n2 Order by Name (Z-a)\n3 Order by score\n4 List a department\nPlease select: ");
		scanf("%d", &a);
		if (a==0) {
			return 0;
		}
		else if (a==1) {
			sort(stu, num);
			printList(stu, num);
		}
		else if (a==2) {
			sort_2(stu, num);
			printList(stu, num);
		}
		else if (a==3) {
			sort_by_score(stu, num);
			printList(stu, num);
		}
		else if (a==4) {
			char major[10];
			printf("Input your major:");
			scanf("%s", major);
			printList(stu, num, major);
		}
	}

	return 0;
}


void sort(Student stu[], int n){// n is the number of students
	int i, j;
	Student temp;// declare temp, use when swap
	for (i = 0; i <= n - 2; i++) { 
		for (j = i + 1; j <= n - 1; j++) {
			if (strcmp(stu[i].name,stu[j].name)>0) {// use strcmp to compare two strings. 
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}
}
void sort_2(Student stu[], int n) {	// n is the number of students
	int i, j;
	Student temp;	// declare temp, use when swap
	for (i = n; i >= 0; i--) {
		for (j = 0; j <= n - 1; j++) {
			if (strcmp(stu[i].name, stu[j].name) < 0) {	// use strcmp to compare two strings.
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}
}
void sort_by_score(Student stu[], int n) {	// n is the number of students
	int i, j;
	Student temp;	// declare temp, use when swap
	for (i = n; i >= 0; i--) {
		for (j = 0; j <= n - 1; j++) {
			if (stu[i].score < stu[i + 1].score) {
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}
}

void printList(Student stu[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%s %.2f %s\n", stu[i].name, stu[i].score, stu[i].major);
	}
}

void printList(Student stu[], int n, char major[]) {
	printf("Department: %s\n", major);
	for (int i = 0; i < n; i++) {
		if (strcmp(stu[i].major, major) == 0) {
			printf("%s %.2f %s\n", stu[i].name, stu[i].score, stu[i].major);
		}
	}
}
