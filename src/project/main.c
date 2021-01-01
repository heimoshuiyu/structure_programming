#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PERSON_NAME_LENGTH 15
#define PERSON_MOBILE_LENGTH 15
#define PERSON_ROOM_LENGTH 15
#define PERSON_BIRTHDAY_LENGTH 8
#define PERSON_DATA_NUM 6
#define FILENAME_NOTEBOOK "notebook.txt"
#define FILENAME_MAIELIST "maleList.txt"
#define FILENAME_FEMAIELIST "femaleList.txt"
#define FILENAME_BYAGE "byAge.txt"
#define FILENAME_NAMELIST "nameList.txt"
#define TITLE_HINT "Name(str) Age(int) Gender(char) Mobile(str) Room(str) Birthday(str)"
#define TITLE_PERSON "-%14s %4s %6s %15s %15s %8s\n"
#define TITLE_PERSON_WITHOUT_AGE "-%14s %6s %15s %15s %8s\n"
#define TITLE_PERSON_NAME_GENDER_AGE "-%14s %6s %4s\n"
#define FORMAT_PERSON "%15s %4d %6c %15s %15s %8s\n"
#define FORMAT_PERSON_WITHOUT_AGE "%15s %6c %15s %15s %8s\n"
#define FORMAT_PERSON_NAME_GENDER_AGE "%15s %6c %4d\n"
typedef struct Person Person;
typedef struct Linklist linklist;

typedef struct Linklist {
	size_t len;
	Person *phead;
	Person *ptail;
} Linklist;

typedef struct Person {
	char name[PERSON_NAME_LENGTH];
	int age;
	char gender;
	char mobile[PERSON_MOBILE_LENGTH];
	char room[PERSON_ROOM_LENGTH];
	char birthday[PERSON_BIRTHDAY_LENGTH];
	Person *next;
	Person *last;
} Person;

void function_list();
void Quit() { exit(0); }

FILE *ShortCutOpen(const char filename[], const char flags[]);
Linklist *newLinklist();
Person *newPerson();
int updatePerson(FILE *fp, Person *person);
Person *fscanPerson(FILE *fp);
void addPerson(Linklist *linklist, Person *person);
void removePerson(Linklist *linklist, Person *person);
Person *findPersonDependOnUser(linklist *linklist);
Person *findPersonByName(Linklist *linklist, const char name[]);
Person *findPersonByMobile(Linklist *linklist, const char mobile[]);
void fprintPerson(FILE *fp, Person *person);
void fprintPersonWithoutAge(FILE *fp, Person *person);
void fprintPersonNameGenderAge(FILE *fp, Person *person);
void fprintLinklist(FILE *fp, Linklist *linklist, void (*callbackFPrintPerson)(FILE *fp, Person *person));
void fprintLinklistByGender(FILE *fp, Linklist *linklist, void (*callbackFPrintPerson)(FILE *fp, Person *person), char gender);
void sortLinklistByName(Linklist *linklist, char desc);
Linklist *readLinklistFromFilename(const char filename[]);

int main() {

	function_list();

	return 0;
}

FILE *ShortCutOpen(const char filename[], const char flags[]) {
	FILE *fp = fopen(filename, flags);
	if (!fp) {
		fprintf(stderr, "Fatal: Can not open file %s with flags %s\n", filename, flags);
		exit(2);
	}
	return fp;
}

Linklist *newLinklist() {
	Linklist *linklist = (Linklist *)calloc(1, sizeof(Linklist));
	return linklist;
}

Person *newPerson() {
	Person *person = (Person *)calloc(1, sizeof(Linklist));
	return person;
}

int updatePerson(FILE *fp, Person *person) {
	return fscanf(fp, " %s %d %c %s %s %s",
			person->name,
			&person->age,
			&person->gender,
			person->mobile,
			person->room,
			person->birthday
	);
}

Person *fscanPerson(FILE *fp) {
	Person *person = (Person *)malloc(sizeof(Person));
	person->next = NULL;
	person->last = NULL;
	if (!(updatePerson(fp, person) == PERSON_DATA_NUM)) {
		return NULL;
	}
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

Person *findPersonDependOnUser(Linklist *linklist) {
	int select;
	char name[PERSON_NAME_LENGTH];
	char mobile[PERSON_MOBILE_LENGTH];
	Person *person;
	while (1) {
		printf("Select the way to find a person:\n");
		printf("1. By name\n");
		printf("2. By mobile\n");
		printf("3. Go back\n");
		printf("Please select a number: ");
		scanf("%d", &select);
		getchar();
		if (select == 1) {
			printf("Please enter a name: ");
			scanf(" %s", name);
			person = findPersonByName(linklist, name);
			if (!person) {
				printf("Can't find person with name '%s'\n", name);
				continue;
			}
			return person;
		} else if (select == 2) {
			printf("Please enter a mobile: ");
			scanf(" %s", mobile);
			person = findPersonByMobile(linklist, mobile);
			if (!person) {
				printf("Can't find person with mobile '%s'\n", mobile);
				continue;
			}
			return person;
		} else if (select == 3) {
			return NULL;
		} else {
			printf("Please input a number between 1--3\n");
			continue;
		}
	}

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
	fprintf(fp, FORMAT_PERSON,
			person->name,
			person->age,
			person->gender,
			person->mobile,
			person->room,
			person->birthday
		);
}

void fprintPersonWithoutAge(FILE *fp, Person *person) {
	fprintf(fp, FORMAT_PERSON_WITHOUT_AGE,
			person->name,
			person->gender,
			person->mobile,
			person->room,
			person->birthday
	       );
}

void fprintPersonNameGenderAge(FILE *fp, Person *person) {
	fprintf(fp, FORMAT_PERSON_NAME_GENDER_AGE,
			person->name,
			person->gender,
			person->age
	       );
}

void fprintLinklist(FILE *fp, Linklist *linklist, void (*callbackFPrintPerson)(FILE *fp, Person *person)) {
	fprintLinklistByGender(fp, linklist, callbackFPrintPerson, 0);
}

void fprintLinklistByGender(FILE *fp, Linklist *linklist, void (*callbackFPrintPerson)(FILE *fp, Person *person), char gender) {
	Person *person;
	if (fp == stdout) {
		if (callbackFPrintPerson == fprintPerson) {
			fprintf(fp, TITLE_PERSON, "Name", "Age", "Gender", "Mobile", "Room", "Birthday");
		} else if (callbackFPrintPerson == fprintPersonWithoutAge) {
			fprintf(fp, TITLE_PERSON_WITHOUT_AGE, "Name", "Gender", "Mobile", "Room", "Birthday");
		} else if (callbackFPrintPerson == fprintPersonNameGenderAge) {
			fprintf(fp, TITLE_PERSON_NAME_GENDER_AGE, "Name", "Gender", "Age");
		} else {
			fprintf(stderr, "Warrning: Unknown title of callback function %p\n", callbackFPrintPerson);
		}
	}
	for (person = linklist->phead; person; person = person->next) {
		if (person->gender == gender || !gender) {
			callbackFPrintPerson(fp, person);
		}
	}
}

void sortLinklistByName(Linklist *linklist, char desc) {
	Person *a, *c, *d;
	Person *person;
	for (size_t i = linklist->len; i > 0; i--) {
		person = linklist->phead;
		for (
				size_t k = 0;
				k < i - 1;
				k++
		    ) {
			if (strcmp(person->name, person->next->name) * desc > 0) {
				c = person->next;
				if (linklist->phead == person) {
					linklist->phead = c;
					c->last = NULL;
				} else {
					a = person->last;
					a->next = c;
					c->last = a;
				}
				if (linklist->ptail == c) {
					linklist->ptail = person;
					person->next = NULL;
				} else {
					d = c->next;
					person->next = d;
					d->last = person;
				}
				c->next = person;
				person->last = c;
			} else {
				person = person->next;
			}
		}
	}
}

Linklist *readLinklistFromFilename(const char filename[]) {
	FILE *fp;
	Linklist *linklist;
	Person *person;
	fp = ShortCutOpen(filename, "r");
	linklist = newLinklist();
	while (person = fscanPerson(fp), person) {
		addPerson(linklist, person);
	}
	fclose(fp);
	return linklist;
}

void function_list() {
	int i;
	int desc;
	FILE *fp;

	void (*callbackFPrintPerson)(FILE *fp, Person *person);
	Person *person;
	Linklist *linklist;
	linklist = readLinklistFromFilename(FILENAME_NOTEBOOK);

	while (1) {

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
		printf("Please Input Number:");
		scanf("%d", &i);
		getchar();

		switch (i) {

			case 39:
				fprintLinklist(stdout, linklist, fprintPerson);
				break;
			case 1:
				printf("Input a person link this:\n%s\n", TITLE_HINT);
				addPerson(linklist, fscanPerson(stdin));
				break;
			case 2:
				person = findPersonDependOnUser(linklist);
				if (!person) {
					printf("You didn't find a person, nothing happend\n");
					break;
				}
				removePerson(linklist, person);
				printf("Removed\n");
				break;
			case 3:
				person = findPersonDependOnUser(linklist);
				if (!person) {
					printf("You didn't find a person, nothing happend\n");
					break;
				}
				printf("Input a person link this:\n%s\n", TITLE_HINT);
				updatePerson(stdin, person);
				break;
			case 4:
				person = findPersonDependOnUser(linklist);
				if (!person) {
					printf("You didn't find a person, nothing happend\n");
					break;
				}
				fprintPerson(stdout, person);
				break;
			case 5:
				fprintLinklistByGender(stdout, linklist, fprintPersonWithoutAge, 'M');
				fp = ShortCutOpen(FILENAME_MAIELIST, "w");
				fprintLinklistByGender(fp, linklist, fprintPerson, 'M');
				fclose(fp);

				fprintLinklistByGender(stdout, linklist, fprintPersonWithoutAge, 'F');
				fp = ShortCutOpen(FILENAME_FEMAIELIST, "w");
				fprintLinklistByGender(fp, linklist, fprintPersonWithoutAge, 'F');
				fclose(fp);
				break;
			case 6:
				printf("Select direction:\n 1: a-Z\n-1: Z-a\nPlease select (1/-1): ");
				scanf(" %d", &desc);
				getchar();
				sortLinklistByName(linklist, desc);
				fprintLinklist(stdout, linklist, fprintPersonWithoutAge);
				fp = ShortCutOpen(FILENAME_NAMELIST, "w");
				fprintLinklist(fp, linklist, fprintPerson);
				fclose(fp);
				break;
			case 7:
				fprintLinklist(stdout, linklist, fprintPersonNameGenderAge);

				fp = ShortCutOpen(FILENAME_BYAGE, "w");
				fprintLinklistByGender(fp, linklist, fprintPerson, 'F');
				fclose(fp);
				break;
			case 8:
				fp = ShortCutOpen(FILENAME_NOTEBOOK, "w");
				fprintLinklist(fp, linklist, fprintPerson);
				fclose(fp);
				Quit();
				break;
			default:
				printf("Number should between 1 -- 8!\n");
		}
	}
}
