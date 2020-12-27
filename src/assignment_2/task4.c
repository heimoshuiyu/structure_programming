/*
 * Author: Walter
 * Student ID: 1930006025
 * Assignment_2_task_1
 * Requirement:
 * Write a program to read student's name and score
 * then sort them by score
 */

#include <stdio.h>

/* max length of student's name */
#define NAME_LENGTH 16

/* max length of student array */
#define STUDENT_LENGTH 20

/* stop if student's score is -1 */
#define STOP_SCORE -1

/* structure of student */
typedef struct Student {
	char name[NAME_LENGTH];
	int score;
} Student;

/* read student information from standard input */
char scan_student(Student *student);

/* print student information to standard output */
void print_student(const Student *student);

/* sort student in student_list */
void sort(Student student_list[], int student_list_len);

int main() {
	Student student_list[STUDENT_LENGTH];
	int student_list_len = 0;

	/* read student information until scan_student return 0 */
	while (scan_student(&student_list[student_list_len++])) {}

	/* sort student array */
	sort(student_list, student_list_len);

	/* print student array */
	for (int i=0; i<student_list_len; i++) {
		print_student(&student_list[i]);
	}

	return 0;
}

void sort(Student student_list[], int student_list_len) {
	/* bubbol sort */
	for (int i=student_list_len-1; i>=0; i--) {
		for (int k=0; k<i; k++) {
			if (student_list[k].score < student_list[k+1].score) {
				/* swap */
				Student tmp;
				tmp = student_list[k+1];
				student_list[k+1] = student_list[k];
				student_list[k] = tmp;
			}
		}
	}
}

char scan_student(Student *student) {
	Student tmp;

	/* read student information */
	scanf("%s", tmp.name);
	scanf("%d", &tmp.score);

	/* stop of student's score is -1 */
	if (tmp.score == STOP_SCORE) {
		return 0;
	}

	/* copy student information */
	*student = tmp;

	return 1;
}

void print_student(const Student *student) {
	printf("%s %d\n", student->name, student->score);
}
