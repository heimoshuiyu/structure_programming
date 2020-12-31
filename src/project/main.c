#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PERSON_NAME_LENGTH 20
#define PERSON_MOBILE_LENGTH 15
#define PERSON_ROOM_LENGTH 20
#define PERSON_BIRTHDAY_LENGTH 8
#define FILENAME_NOTEBOOK "notebook.txt"

typedef struct Person Person;
typedef struct Linklist linklist;

typedef struct Linklist {
	size_t len;
	Person *phead;
	Person *ptail;
} Linklist;

typedef struct Person {
	char name[PERSON_NAME_LENGTH];
	char age;
	char gender;
	char mobile[PERSON_MOBILE_LENGTH];
	char room[PERSON_ROOM_LENGTH];
	char birthday[PERSON_BIRTHDAY_LENGTH];
	Person *next;
	Person *last;
} Person;

static size_t PersonDataSize = sizeof(Person) - sizeof(Person *) * 2;

void function_list();
void Quit() { exit(0); }

void checkPtr(void *);
Linklist *newLinklist();
Person *newPerson();
Person *fscanPerson(FILE *fp);
void addPerson(Linklist *linklist, Person *person);
void removePerson(Linklist *linklist, Person *person);
Person *findPersonByName(Linklist *linklist, const char name[]);
Person *findPersonByMobile(Linklist *linklist, const char mobile[]);
void fprintPerson(FILE *fp, Person *person);
void fprintPersonWithoutAge(FILE *fp, Person *person);
void fprintPersonNameGenderAge(FILE *fp, Person *person);
void fprintLinklist(FILE *fp, Linklist *linklist, void (*callbackFPrintPerson)(FILE *fp, Person *person));
void sortLinklistByName(Linklist *linklist, char desc);

int main() {

	function_list();

	return 0;
}

void checkPtr(void *ptr) {
	if (ptr == NULL) {
		fprintf(stderr, "NULL pointer\n");
		exit(1);
	}
}

Linklist *newLinklist() {
	Linklist *linklist = calloc(1, sizeof(malloc));
	return linklist;
}

Person *newPerson() {
	Person *person = calloc(1, sizeof(malloc));
	return person;
}

Person *fscanPerson(FILE *fp) {
	if (!feof(fp)) {
		return NULL;
	}
	Person *person = malloc(sizeof(Person));
	person->next = NULL;
	person->last = NULL;
	fscanf(fp, " %s\t%c\t%c\t%s\t%s\t%s\n",
			person->name,
			&person->age,
			&person->gender,
			person->mobile,
			person->room,
			person->birthday
	);
	return person;
}

void addPerson(Linklist *linklist, Person *person) {
	if (linklist->len == 0) {
		linklist->phead = person;
		linklist->ptail = person;
		linklist->len = 1;
		return;
	}
	linklist->ptail->next = person;
	person->last = linklist->ptail;
	linklist->ptail = person;
	linklist->len++;
}

void removePerson(Linklist *linklist, Person *person) {
	if (person->last) {
		person->last->next = person->next;
	} else {
		linklist->phead = person->next;
	}
	if (person->next) {
		person->next->last = person->last;
	} else {
		linklist->ptail = person;
	}
	free(person);
}

Person *findPersonByName(Linklist *linklist, const char name[]) {
	Person *person;
	for(person = linklist->phead; person; person = person->next) {
		if (strcmp(person->name, name) == 0) {
			return person;
		}
	}
	return NULL;
}

Person *findPersonByMobile(Linklist *linklist, const char mobile[]) {
	Person *person;
	for(person = linklist->phead; person; person = person->next) {
		if (strcmp(person->mobile, mobile) == 0) {
			return person;
		}
	}
	return NULL;
}

void fprintPerson(FILE *fp, Person *person) {
	fprintf(fp, "%s\t%d\t%c\t%s\t%s\t%s\n",
			person->name,
			person->age,
			person->gender,
			person->mobile,
			person->room,
			person->birthday
		);
}

void fprintPersonWithoutAge(FILE *fp, Person *person) {
	fprintf(fp, "%s\t%c\t%s\t%s\t%s\n",
			person->name,
			person->gender,
			person->mobile,
			person->room,
			person->birthday
	       );
}

void fprintPersonNameGenderAge(FILE *fp, Person *person) {
	fprintf(fp, "%s\t%d\t\%c\n",
			person->name,
			person->age,
			person->gender
	       );
}

void fprintLinklist(FILE *fp, Linklist *linklist, void (*callbackFPrintPerson)(FILE *fp, Person *person)) {
	Person *person;
	for (person = linklist->phead; person; person = person->next) {
		callbackFPrintPerson(fp, person);
	}
}

void sortLinklistByName(Linklist *linklist, char desc) {
	Person tmp;
	Person *person;
	for (size_t i = linklist->len; i >= 0; i--) {
		for (
				size_t k = 0;
				k < i - 1;
				k++, person = person->next
		    ) {
			if (strcmp(person->name, person->next->name) * desc > 0) {
				memcpy(&tmp, person, PersonDataSize);
				memcpy(person, person->name, PersonDataSize);
				memcpy(person->next, &tmp, PersonDataSize);
			}
		}
	}
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
