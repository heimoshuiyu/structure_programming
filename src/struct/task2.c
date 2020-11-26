#include <stdio.h>
#include <string.h>
#include <stdio.h>

/* MAX number of student in list */
#define UPPER_LIMIT 50

/* MAX length of student name */
#define NAME_LENGTH 32

/* MAX length of student major */
#define MAJOR_LENGTH 16

typedef struct Student Student;

typedef struct Student {
	char name[NAME_LENGTH];
	int score;
	char major[MAJOR_LENGTH];
} Student;

int main() {
	Student student_list[UPPER_LIMIT];
	int student_list_len = 0;

	/* ask user input number of students */
	printf("Please input the number of students (<=50): ");
	while (1) {
		scanf("%d", &student_list_len);
		getchar();
		if (student_list_len > UPPER_LIMIT) {
			printf("Warning: Please input a number which does not exceed %d\n",
					UPPER_LIMIT);
			printf("Input again: ");
			continue;
		} else {
			break;
		}
	}

	/* loop for input student information */
	printf("Please input students' information:\n");
	for (int i=0; i<student_list_len; i++) {
		/* input name */
		scanf("%s", student_list[i].name);
		getchar();
		/* input score */
		scanf("%d", &student_list[i].score);
		getchar();
		/* input major */
		scanf("%s", student_list[i].major);
		getchar();
	}

	/* sort */
	for (int s=student_list_len; s>=0; s--) {
		for (int i=0; i<s-1; i++) {
			/* ascending order by name */
			if (strcmp(student_list[i].name, student_list[i+1].name) > 0) {
				/* swap */
				Student tmp;
				memcpy(&tmp, &student_list[i], sizeof(Student));
				memcpy(&student_list[i], &student_list[i+1], sizeof(Student));
				memcpy(&student_list[i+1], &tmp, sizeof(Student));
			}
		}
	}
	
	/* show result */
	printf("The student list in ascending order by name is\n");
	for (int i=0; i<student_list_len; i++) {
		printf("%s %d %s\n",
				student_list[i].name,
				student_list[i].score,
				student_list[i].major);
	}

	return 0;
}
