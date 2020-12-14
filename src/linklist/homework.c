/*
 * Author: Walter
 * Student ID: 1930006025
 * Week_12_homework
 * Today s task: Dynamic List page 6
 * - Create a function that prints out the linked list
 *   you should send the head pointer to the function
 * - Create functions that
 *   - Add more nodes to the list
 *   - Search the node using a number
 *     i.e. output the 4th person in the list
 *   - Search for a node that compares to a name in the list
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENT_NAME_LENGTH 20

typedef struct Student Student;
typedef struct Linklist Linklist;

/* print one node */
void printNode(const Student *student);

/* print the whole linklist */
void printLinklist(const Linklist *linklist);

/* print linklist from one node */
void printLinklistFromNode(const Student *student);

/* generate a new student */
Student *newStudent(int id, const char name[]);

/* add a student to the end of linklist */
Student *addLinklist(Linklist *linklist, Student *student);

/* get a student from linklist by index (started from 0) */
Student *searchLinklistByIndex(const Linklist *linklist, int index);

/* get a student from linklist by index (started from 1) */
Student *searchLinklistByCount(const Linklist *linklist, int index);

/* get a student from linklist by name */
Student *searchLinklistByName(const Linklist *linklist, const char name[]);

typedef struct Student {
	int id;
	char name[STUDENT_NAME_LENGTH];
	Student *next;
} Student;

typedef struct Linklist {
	Student *phead;
	Student *ptail;
	int len;
} Linklist;

int main() {
	Linklist linklist = {NULL};
	printf("Start...\n");
	printf("First we have a empty linedlist\n");
	printLinklist(&linklist);
	printf("Then add four students\n");
	addLinklist(&linklist, newStudent(1930006025, "Walter"));
	addLinklist(&linklist, newStudent(233, "Jack"));
	addLinklist(&linklist, newStudent(666, "Tom"));
	addLinklist(&linklist, newStudent(39, "Miku"));
	printLinklist(&linklist);
	printf("Find the 4th student\n");
	printNode(searchLinklistByCount(&linklist, 4));
	printf("Find the student with name 'Miku'\n");
	printNode(searchLinklistByName(&linklist, "Miku"));
	printf("Find the student with name 'NOTFOUND'\n");
	printNode(searchLinklistByName(&linklist, "NOTFOUND"));
	return 0;
}

/* print NULL if student is NULL */
void printNode(const Student *student) {
	if (!student) {
		printf("Student is NULL\n");
		return;
	}
	printf("ID: %d\tName: %s\n", student->id, student->name);
}

void printLinklist(const Linklist *linklist) {
	printLinklistFromNode(linklist->phead);
}

void printLinklistFromNode(const Student *student) {
	printf("###### START OF LINKLIST ######\n");
	for (; student; student=student->next) {
		printNode(student);
	}
	printf("######  END  OF LINKLIST ######\n");
}

Student *newStudent(int id, const char name[]) {
	Student *p;
	p = (Student*)malloc(sizeof(Student));
	if (!p) {
		fprintf(stderr, "Failed to malloc new student\n");
		exit(1);
	}

	/* set data */
	p->id = id;
	strcpy(p->name, name);
	p->next = NULL;

	return p;
}

Student *addLinklist(Linklist *linklist, Student *student) {
	/* first student */
	if (linklist->len == 0) {
		linklist->phead = student;
		linklist->ptail = student;
		linklist->len = 1;
		return linklist->ptail;
	}

	/* set data */
	linklist->ptail->next = student;
	linklist->ptail = student;
	linklist->len++;

	return linklist->ptail;
}

Student *searchLinklistByIndex(const Linklist *linklist, int index) {
	if (index > linklist->len) {
		fprintf(stderr, "index out of range\n");
		exit(2);
	}

	Student *p = linklist->phead;

	/* move p */
	for (int i=0; i<index; i++) {
		p = p->next;
	}

	return p;
}

Student *searchLinklistByCount(const Linklist *linklist, int index) {
	return searchLinklistByIndex(linklist, index - 1);
}

/* return NULL if student is not found */
Student *searchLinklistByName(const Linklist *linklist, const char name[]) {
	for (Student *p=linklist->phead; p; p=p->next) {
		/* compare name */
		if (strcmp(p->name, name) == 0) {
			return p;
		}
	}
	return NULL;
}
