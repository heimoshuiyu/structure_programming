#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define the max length of person's name */
#define PERSON_NAME_LENGTH 15

/* define the max length of person's mobile length */
#define PERSON_MOBILE_LENGTH 15

/* define the max length of person's room length */
#define PERSON_ROOM_LENGTH 15

/* define the max length of person 's birthday length */
#define PERSON_BIRTHDAY_LENGTH 8

/* define how many attribute per person has */
#define PERSON_DATA_NUM 6

/* define file name */
#define FILENAME_NOTEBOOK "notebook.txt"
#define FILENAME_MAIELIST "maleList.txt"
#define FILENAME_FEMAIELIST "femaleList.txt"
#define FILENAME_BYAGE "byAge.txt"
#define FILENAME_NAMELIST "nameList.txt"

/* define the hint when ask user to input a person's information */
#define TITLE_HINT                                                             \
	"Name(Miku) Age(16) Gender(F/M) Mobile(1234567890) Room(T8-307-R10) "        \
	"Birthday(20070831)"

/* define the title format */
#define TITLE_PERSON "-%14s %4s %6s %15s %15s %8s\n"
#define TITLE_PERSON_WITHOUT_AGE "-%14s %6s %15s %15s %8s\n"
#define TITLE_PERSON_NAME_GENDER_AGE "-%14s %6s %4s\n"

/* define the information output format */
#define FORMAT_PERSON "%15s %4d %6c %15s %15s %8s\n"
#define FORMAT_PERSON_WITHOUT_AGE "%15s %6c %15s %15s %8s\n"
#define FORMAT_PERSON_NAME_GENDER_AGE "%15s %6c %4d\n"

typedef struct Person Person;

typedef struct Linklist linklist;

/* struct of reversed linklist */
typedef struct Linklist {
	size_t len;
	Person *phead;
	Person *ptail;
} Linklist;

/* struct of person */
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

/* method to create an empty linklist */
Linklist *newLinklist();

/* method to create an empty person */
Person *newPerson();

/* method to update a person's information from stream */
int updatePerson(FILE *fp, Person *person);

/* create and scan a new person from stream */
Person *fscanPerson(FILE *fp);

/* add person to the end of reversed linklist */
void addPerson(Linklist *linklist, Person *person);

/* remove a person from reversed linklist */
void removePerson(Linklist *linklist, Person *person);

/* find person in the linklist, ask user to select by name or by mobile, return
 * NULL if no person found */
Person *findPersonDependOnUser(linklist *linklist);

/* find person in the linklist by name */
Person *findPersonByName(Linklist *linklist, const char name[]);

/* find person in the linklist by mobile */
Person *findPersonByMobile(Linklist *linklist, const char mobile[]);

/* sort person in the linklist by name, desc=1 means ascending order, desc=-1
 * means descending order */
void sortLinklistByName(Linklist *linklist, char desc);

/* print person information to stream */
void fprintPerson(FILE *fp, Person *person);

/* print person information with age to stream */
void fprintPersonWithoutAge(FILE *fp, Person *person);

/* print person's name, gender, and age to stream */
void fprintPersonNameGenderAge(FILE *fp, Person *person);

/* print linklist to  stream, specify a print method */
void fprintLinklist(FILE *fp, Linklist *linklist,
		void (*callbackFPrintPerson)(FILE *fp, Person *person));

/* print linklist with gender, specify a print method, set gender=0 to print all
 * gender*/
void fprintLinklistByGender(FILE *fp, Linklist *linklist,
		void (*callbackFPrintPerson)(FILE *fp,
			Person *person),
		char gender);

/* create and read a linklist from file name */
Linklist *readLinklistFromFilename(const char filename[]);

/* shortcut function to open a file, exit(2) if open file failed */
FILE *ShortCutOpen(const char filename[], const char flags[]);

int main() {

	function_list();

	return 0;
}

FILE *ShortCutOpen(const char filename[], const char flags[]) {
	FILE *fp = fopen(filename, flags);
	/* check whether open successfully */
	if (!fp) {
		fprintf(stderr, "Fatal: Can not open file %s with flags %s\n", filename,
				flags);
		exit(2);
	}
	return fp;
}

Linklist *newLinklist() {
	/* create a new linklist, set memory to 0 */
	Linklist *linklist = (Linklist *)calloc(1, sizeof(Linklist));
	if (!linklist) {
		fprintf(stderr, "Fatal: calloc Linklist failed\n");
		exit(1);
	}
	return linklist;
}

Person *newPerson() {
	/* create a new person, set memory to 0 */
	Person *person = (Person *)calloc(1, sizeof(Linklist));
	if (!person) {
		fprintf(stderr, "Fatal: calloc Person failed\n");
		exit(1);
	}
	return person;
}

int updatePerson(FILE *fp, Person *person) {
	/* scan string from fp to person, return the number of scanned data */
	return fscanf(fp, " %s %d %c %s %s %s", person->name, &person->age,
			&person->gender, person->mobile, person->room,
			person->birthday);
}

Person *fscanPerson(FILE *fp) {
	/* allocate memory */
	Person *person = (Person *)malloc(sizeof(Person));
	/* make sure next and last pointer set to NULL */
	person->next = NULL;
	person->last = NULL;
	/* scan person from fp, ensure that the number of scanned data is equal to the
	 * number of person's data */
	if (!(updatePerson(fp, person) == PERSON_DATA_NUM)) {
		return NULL;
	}
	return person;
}

void addPerson(Linklist *linklist, Person *person) {
	/* Special cases: linklist is empty */
	if (linklist->len == 0) {
		linklist->phead = person;
		linklist->ptail = person;
		linklist->len = 1;
		return;
	}
	/* link person */
	linklist->ptail->next = person;
	person->last = linklist->ptail;
	/* move tail to new person */
	linklist->ptail = person;
	/* add counter */
	linklist->len++;
}

void removePerson(Linklist *linklist, Person *person) {
	/* Special cases: linklist has only one person */
	if (linklist->len == 1) {
		/* set linklist to empty */
		memset(linklist, 0, sizeof(Linklist));
		return;
	}

	/* check whether person is point at the last one */
	if (person->last) {
		person->last->next = person->next;
	} else {
		linklist->phead = person->next;
		person->next->last = NULL;
	}

	/* check whether person is point at the first one */
	if (person->next) {
		person->next->last = person->last;
	} else {
		linklist->ptail = person->last;
		person->last->next = NULL;
	}

	linklist->len--;
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

		/* call getchar once to clear buffer area */
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
			/* return NULL if user did not find a person */
			return NULL;
		} else {
			printf("Please input a number between 1--3\n");
			continue;
		}
	}
}

Person *findPersonByName(Linklist *linklist, const char name[]) {
	Person *person;
	/* loop in linklist */
	for (person = linklist->phead; person; person = person->next) {
		if (strcmp(person->name, name) == 0) {
			return person;
		}
	}
	/* if person not found, return NULL */
	return NULL;
}

Person *findPersonByMobile(Linklist *linklist, const char mobile[]) {
	Person *person;
	/* loop in linklist */
	for (person = linklist->phead; person; person = person->next) {
		if (strcmp(person->mobile, mobile) == 0) {
			return person;
		}
	}
	/* if person not found, return NULL */
	return NULL;
}

void fprintPerson(FILE *fp, Person *person) {
	/* print person to stream */
	fprintf(fp, FORMAT_PERSON, person->name, person->age, person->gender,
			person->mobile, person->room, person->birthday);
}

void fprintPersonWithoutAge(FILE *fp, Person *person) {
	/* print person to stream */
	fprintf(fp, FORMAT_PERSON_WITHOUT_AGE, person->name, person->gender,
			person->mobile, person->room, person->birthday);
}

void fprintPersonNameGenderAge(FILE *fp, Person *person) {
	/* print person to stream */
	fprintf(fp, FORMAT_PERSON_NAME_GENDER_AGE, person->name, person->gender,
			person->age);
}

void fprintLinklist(FILE *fp, Linklist *linklist,
		void (*callbackFPrintPerson)(FILE *fp, Person *person)) {
	/* call fprintLinklistByGender, gender=0 means print all gender */
	fprintLinklistByGender(fp, linklist, callbackFPrintPerson, 0);
}

void fprintLinklistByGender(FILE *fp, Linklist *linklist,
		void (*callbackFPrintPerson)(FILE *fp,
			Person *person),
		char gender) {

	Person *person;

	/* if stream is standard output (screen, pipe, etc.) print with a title of the
	 * linklist */
	if (fp == stdout) {
		/* select the title depend on the callback function */
		if (callbackFPrintPerson == fprintPerson) {
			fprintf(fp, TITLE_PERSON, "Name", "Age", "Gender", "Mobile", "Room",
					"Birthday");
		} else if (callbackFPrintPerson == fprintPersonWithoutAge) {
			fprintf(fp, TITLE_PERSON_WITHOUT_AGE, "Name", "Gender", "Mobile", "Room",
					"Birthday");
		} else if (callbackFPrintPerson == fprintPersonNameGenderAge) {
			fprintf(fp, TITLE_PERSON_NAME_GENDER_AGE, "Name", "Gender", "Age");
		} else {
			/* if a callback function is unknown, give a warning */
			fprintf(stderr, "Warning: Unknown title of callback function %p\n",
					callbackFPrintPerson);
		}
	}

	/* print the person using callback function */
	for (person = linklist->phead; person; person = person->next) {
		if (person->gender == gender || !gender) {
			callbackFPrintPerson(fp, person);
		}
	}
}

void sortLinklistByName(Linklist *linklist, char desc) {
	/*
	 * Bubble sort
	 * reversed linklist struct:
	 * a <-> person <-> c <-> d
	 * after swap:
	 * a <-> c <-> person <-> d
	 * we also need to check whether person is the head or c is the tail
	 * after swap, person and d will be compared
	 */
	Person *a, *person, *c, *d;

	/* i loop from len to 1 */
	for (size_t i = linklist->len; i > 0; i--) {

		/* before loop, set person point at head */
		person = linklist->phead;

		/* k loop from 0 to i-1 */
		for (size_t k = 0; k < i - 1; k++) {
			/* compare string, times desc, desc 1 means ascending order, -1 means
			 * descending order */
			if (strcmp(person->name, person->next->name) * desc > 0) {

				/* init pointer c */
				c = person->next;

				/* check whether person is the head */
				if (linklist->phead == person) {
					/* move head */
					linklist->phead = c;
					c->last = NULL;
				} else {
					/* init pointer a */
					a = person->last;

					/* swap link */
					a->next = c;
					c->last = a;
				}

				/* check whether c is the tail */
				if (linklist->ptail == c) {
					/* move tail */
					linklist->ptail = person;
					person->next = NULL;
				} else {
					/* init pointer d */
					d = c->next;

					/* swap link */
					person->next = d;
					d->last = person;
				}

				/* swap link */
				c->next = person;
				person->last = c;
			} else {
				/* if not swapped, move pointer to the next */
				person = person->next;
			}
		}
	}
}

Linklist *readLinklistFromFilename(const char filename[]) {
	FILE *fp;
	Linklist *linklist;
	Person *person;

	/* open file */
	fp = ShortCutOpen(filename, "r");

	/* create new empty linklist */
	linklist = newLinklist();

	/* add person from file to linklist, until fscanPerson return 0, means the end
	 * of the file */
	while (person = fscanPerson(fp), person) {
		addPerson(linklist, person);
	}

	/* close file */
	fclose(fp);

	return linklist;
}

void debug(Linklist *linklist) {
	/* just for debug ... */
	printf("from head to tail\n");
	Person *person;
	printf("phead at %p\n", linklist->phead);
	for (person = linklist->phead; person; person = person->next) {
		printf("person at %p, name %s, last %p, next %p\n", person, person->name,
				person->last, person->next);
	}
	printf("ptail at %p\n", linklist->ptail);
}

void function_list() {
	int i;
	int desc;
	FILE *fp;

	void (*callbackFPrintPerson)(FILE *fp, Person *person);
	Person *person;
	Linklist *linklist;

	/* at the begining, read linklist from file */
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
		printf("Please Input Number: ");
		scanf("%d", &i);
		getchar();

		switch (i) {

			/* just for debug ... */
			case 39:
				debug(linklist);
				break;
			case 1:
				/* Menu: add a new person to linklist */
				/* give user a hint, the format to enter a person */
				printf("Input a person link this:\n%s\n", TITLE_HINT);
				/* read a person's informatino from standard input (keyboard, pipe, etc.)
				*/
				addPerson(linklist, fscanPerson(stdin));
				break;
			case 2:
				/* Menu: remove a person from linklist */
				/* first, ask user to find a person */
				person = findPersonDependOnUser(linklist);
				/* if user did not find a person */
				if (!person) {
					printf("You didn't find a person, nothing happend\n");
					break;
				}
				/* remove this person from linklist */
				removePerson(linklist, person);
				break;
			case 3:
				/* Menu: update person's informatino */
				/* first, find the person */
				person = findPersonDependOnUser(linklist);
				/* if the person is not find */
				if (!person) {
					printf("You didn't find a person, nothing happend\n");
					break;
				}
				/* ask user to input a person */
				printf("Input a person link this:\n%s\n", TITLE_HINT);
				/* scan and from standard input and update to person */
				updatePerson(stdin, person);
				break;
			case 4:
				/* Menu: find and view person datails */
				/* ask use to find a person */
				person = findPersonDependOnUser(linklist);
				/* if user didnot find a person */
				if (!person) {
					printf("You didn't find a person, nothing happend\n");
					break;
				}
				/* print person's informatino to standard output */
				fprintPerson(stdout, person);
				break;
			case 5:
				/* Menu: All female / male */
				/* print linklist to standard output with gender Male */
				fprintLinklistByGender(stdout, linklist, fprintPersonWithoutAge, 'M');
				/* open file */
				fp = ShortCutOpen(FILENAME_MAIELIST, "w");
				/* print linklist to file with gender Male */
				fprintLinklistByGender(fp, linklist, fprintPerson, 'M');
				/* close file */
				fclose(fp);

				/* print linklist to standard output with gender Female */
				fprintLinklistByGender(stdout, linklist, fprintPersonWithoutAge, 'F');
				/* open file */
				fp = ShortCutOpen(FILENAME_FEMAIELIST, "w");
				/* print linklist to file with gender Female */
				fprintLinklistByGender(fp, linklist, fprintPersonWithoutAge, 'F');
				/* clsoe file */
				fclose(fp);
				break;
			case 6:
				/* Menu: List by name A-z / Z-a */
				printf("Select direction:\n 1: A-z\n-1: Z-a\nPlease select (1/-1): ");
				/* scan user's choise */
				scanf(" %d", &desc);
				getchar();
				/* sort linklist */
				sortLinklistByName(linklist, desc);
				/* print linklist to standard output, without age*/
				fprintLinklist(stdout, linklist, fprintPersonWithoutAge);
				/* open file */
				fp = ShortCutOpen(FILENAME_NAMELIST, "w");
				/* print linklist to file, with all data */
				fprintLinklist(fp, linklist, fprintPerson);
				/* close file */
				fclose(fp);
				break;
			case 7:
				/* Menu: By age */
				/* print linklist to standard output, with Name, Gender, and Age */
				fprintLinklist(stdout, linklist, fprintPersonNameGenderAge);
				/* open file */
				fp = ShortCutOpen(FILENAME_BYAGE, "w");
				/* print linklist to file, with all data */
				fprintLinklist(fp, linklist, fprintPerson);
				/* close file */
				fclose(fp);
				break;
			case 8:
				/* Menu: Quit */
				/* open file */
				fp = ShortCutOpen(FILENAME_NOTEBOOK, "w");
				/* save all linklist data to file */
				fprintLinklist(fp, linklist, fprintPerson);
				/* clsoe file */
				fclose(fp);
				/* quit with code 0 */
				Quit();
				break;
			default:
				printf("Number should between 1 -- 8!\n");
		}
	}
}
