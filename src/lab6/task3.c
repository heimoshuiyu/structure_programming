#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *next;
} Node;


int main() {

	int input;

	/* declare first node of link list */
	Node n = {0, NULL};
	Node *p = &n;
	
	/* read number from user input */
	while (scanf("%d", &input), input != -1) {

		/* assign value */
		p->value = input;

		/* create next node */
		p->next = malloc(sizeof(Node));

		/* move pointer to next node */
		p = p->next;

		/* make sure NULL at the end */
		p->next = NULL;

	}

	/* reset pointer to begining */
	p = &n;

	int sorted = 0;
	while (!(sorted)) {
		/* assume as sorted */
		sorted = 1;
		for (int tmp; p->next->next; p=p->next) {
			if (p->value > p->next->value) {
				/* mark as not sorted */
				sorted = 0;
				/* swap value */
				tmp = p->value;
				p->value = p->next->value;
				p->next->value = tmp;
			}
		}
		/* reset pointer to begining */
		p = &n;
	}

	/* reset pointer to begining */
	p = &n;

	for (; p->next; p = p->next) printf("%d ", p->value);


	return 0;
}
