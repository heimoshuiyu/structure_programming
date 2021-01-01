#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PERSON_NAME_LENGTH 20
#define PERSON_MOBILE_LENGTH 15
#define PERSON_ROOM_LENGTH 20
#define PERSON_BIRTHDAY_LENGTH 8
#define PERSON_DATA_NUM 6
#define FILENAME_NOTEBOOK "notebook.txt"
#define FILENAME_MAIELIST "maleList.txt"
#define FILENAME_FEMAIELIST "femaleList.txt"
#define FILENAME_BYAGE "byAge.txt"
#define TITLE_HINT "Name(str) Age(int) Gender(char) Mobile(str) Room(str) Birthday(str)"

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

static size_t PersonDataSize = sizeof(Person) - sizeof(Person *) * 2;

void function_list();
void Quit() { exit(0); }

void checkPtr(void *);
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

void checkPtr(void *ptr) {
	if (ptr == NULL) {
		fprintf(stderr, "NULL pointer\n");
		exit(1);
	}
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

void fprintLinklistByGender(FILE *fp, Linklist *linklist, void (*callbackFPrintPerson)(FILE *fp, Person *person), char gender) {
	Person *person;
	for (person = linklist->phead; person; person = person->next) {
		if (person->gender == gender) {
			callbackFPrintPerson(fp, person);
		}
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

Linklist *readLinklistFromFilename(const char filename[]) {
	FILE *fp;
	Linklist *linklist;
	Person *person;
	fp = fopen(filename, "r");
	if (!fp) {
		fprintf(stderr, "Fatal: Open %s error\n", filename);
		exit(2);
	}
	linklist = newLinklist();
	while (person = fscanPerson(fp), person) {
		addPerson(linklist, person);
	}
	fclose(fp);
	return linklist;
}

void function_list() {
	int i;
	char gender;
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

		printf("\n\n\n\n");

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
				fp = fopen(FILENAME_MAIELIST, "w");
				if (!fp) {
					printf("Fatal: Can not write to %s\n", FILENAME_MAIELIST);
					exit(3);
				}
				fprintLinklistByGender(fp, linklist, fprintPerson, 'M');

				fprintLinklistByGender(stdout, linklist, fprintPersonWithoutAge, 'F');
				fp = fopen(FILENAME_FEMAIELIST, "w");
				if (!fp) {
					printf("Fatal: Can not write to %s\n", FILENAME_FEMAIELIST);
					exit(3);
				}
				fprintLinklistByGender(fp, linklist, fprintPersonWithoutAge, 'F');
				fclose(fp);
				break;
			case 6:
				sortLinklistByName(linklist, 1);
				fprintLinklist(stdout, linklist, fprintPersonWithoutAge);
				break;
			case 7:
				fprintLinklist(stdout, linklist, fprintPersonNameGenderAge);

				fp = fopen(FILENAME_BYAGE, "w");
				if (!fp) {
					printf("Fatal: Can not write to %s\n", FILENAME_BYAGE);
					exit(3);
				}
				fprintLinklistByGender(fp, linklist, fprintPerson, 'F');
				fclose(fp);
				break;
			case 8:
				Quit();
				break;
			default:
				printf("Number should between 1 -- 8!\n");
		}
	}
}
