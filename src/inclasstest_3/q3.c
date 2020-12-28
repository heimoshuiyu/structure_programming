#include <stdio.h>
#include <string.h>

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
	int age;
} Student;

/* read student information from standard input */
char scan_student(Student *student);

/* print student information to standard output */
void print_student(const Student *student);

/* sort student by score in student_list */
void sort(Student student_list[], int student_list_len);

/* sort by olderest age first student in student_list */
void sort_old_first(Student student_list[], int student_list_len);

/* save student into file */
void save(const Student student_list[], int student_list_len, const char filename[]);

int main() {
	Student student_list[STUDENT_LENGTH];
	int student_list_len = 0;

	/* hint */
	printf("Input student information like this: miku 39 16\n");
	printf("Miku(name) 39(score) 16(age)\n");
	printf("Stop with student's score %d\n", STOP_SCORE);

	/* read student information until scan_student return 0 */
	while (scan_student(&student_list[student_list_len++])) {}
	student_list_len--;
	

	/* sort student array */
	sort(student_list, student_list_len);
	/* print student array */
	for (int i=0; i<student_list_len; i++) {
		print_student(&student_list[i]);
	}
	/* save */
	save(student_list, student_list_len, "byHighestScore.txt");

	/* sort student array */
	sort_old_first(student_list, student_list_len);
	/* print student array */
	for (int i=0; i<student_list_len; i++) {
		print_student(&student_list[i]);
	}
	/* save */
	save(student_list, student_list_len, "byOldestAge.txt");

	return 0;
}

void save(const Student student_list[], int student_list_len, const char filename[]) {
	FILE *fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("Open file %s error\n", filename);
		return;
	}
	for (int i=0; i<student_list_len; i++) {
		fprintf(fp, "%s\t%d\t%d\n",
				student_list[i].name,
				student_list[i].score,
				student_list[i].age);
	}
	fclose(fp);
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

void sort_old_first(Student student_list[], int student_list_len) {
	/* bubbol sort */
	for (int i=student_list_len-1; i>=0; i--) {
		for (int k=0; k<i; k++) {
			if (student_list[k].age < student_list[k+1].age) {
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
	scanf("%d", &tmp.age);

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
