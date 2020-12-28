#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Linklist Linklist;

typedef struct Node {
	int value;
	Node *next;
} Node;

typedef struct Linklist {
	Node *phead;
	Node *ptail;
	int len;
} Linklist;

void append(Linklist *linklist, int value);
int find(Linklist *linklist, int value);
void delete(Linklist *linklist);
void print(Linklist *linklist);

int main() {
	Linklist linklist = {0};
	Linklist new_linklist = {0};
	int len;
	int value;
	Node *pnode;
	
	/* ask user to input a length */
	printf("Enter array size: ");
	scanf("%d", &len);
	
	/* enter original array */
	printf("Enter %d array element: ", len);
	for (int i=0; i<len; i++) {
		scanf("%d", &value);
		append(&linklist, value);
	}

	/* Original array is: */
	printf("Original array is: ");
	print(&linklist);

	/* remove duplicates */
	for (pnode=linklist.phead; pnode; pnode=pnode->next) {
		/* pass if exists */
		if (find(&new_linklist, pnode->value) == -1) {
			append(&new_linklist, pnode->value);
		}
	}

	printf("New array is: ");
	print(&new_linklist);

	return 0;
}

void append(Linklist *linklist, int value) {
	if (linklist->len == 0) {
		linklist->phead = (Node *)malloc(sizeof(Node));
		if (!linklist->phead) {
			printf("Fatal: malloc failed\n");
			return;
		}
		linklist->phead->next = NULL;
		linklist->phead->value = value;
		linklist->ptail = linklist->phead;
		linklist->len = 1;
		return;
	}
	/* append a new node to the end */
	linklist->ptail->next = (Node *)malloc(sizeof(Node));
	if (!linklist->phead) {
		printf("Fatal: malloc failed\n");
		return;
	}
	linklist->ptail = linklist->ptail->next;
	linklist->ptail->value = value;
	linklist->ptail->next = NULL;
	linklist->len = linklist->len + 1;
}

int find(Linklist *linklist, int value) {
	Node *pnode = linklist->phead;
	for (int i=0; i<linklist->len; i++, pnode=pnode->next){
		if (pnode->value == value) {
			return i;
		}
	}
	return -1;
}

void delete(Linklist *linklist) {
	Node *pnode = linklist->phead;
	Node *del = linklist->phead;
	for (int i=0; i<linklist->len-1; i++) {
		del = pnode;
		pnode = pnode->next;
		free(del);
	}
	free(del);
}

void print(Linklist *linklist) {
	Node *pnode = linklist->phead;
	for (int i=0; i<linklist->len; i++) {
		printf("%d ", pnode->value);
		pnode = pnode->next;
	}
	printf("\n");
}
