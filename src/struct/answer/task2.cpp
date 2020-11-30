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
	char major[10];
	float score;
};//Please always define the structure outside the main function, so that each sub function can use it.

void sort(Student stu[], int n);// sort the student by name, no need to return, so the return type is void

int main() {
	Student stu[50];// declare an array of Student type, at most 50 students
	int num = 0;
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
	sort(stu, num);// call the sort function to sort the students by name. Notice that we use the array name as the input
	for (int j = 0; j < num; j++) { // output all the information after being sorted
		printf("%s %.2f %s\n", stu[j].name, stu[j].score, stu[j].major);
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