#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE_TAG {
	char str[101];
	struct NODE_TAG * prev, * next;
} node;

// UI functions
void printMenu(char currStr[]) {
	printf("\nCurrent string: %s\n", currStr);
	printf("====MENU====\n");
	printf("[1] Edit String\n");
	printf("[2] Undo\n");
	printf("[3] Redo\n");
	printf("[4] Exit\n");
	printf("=============\n");
	printf("Choice: ");
}

void printEditMenu() {
	printf("\n[1] Replace String\n");
	printf("[2] Change char at\n");
	printf("[3] Append a string\n");
	printf("[4] Back to Main Menu\n");

	printf("Choice: ");
}

// Remove trailing new line from a string
void trim(char str[]) {
	int i = strlen(str);
	if (str[i-1] == '\n') str[i-1] = '\0';
}

// Sets up linked list with dummy nodes
void initList(node ** head, node ** tail, node ** curr) {
	*head = (node *) malloc(sizeof(node));
	*tail = (node *) malloc(sizeof(node));

	(*head)->prev = NULL;
	(*head)->next = *tail;

	(*tail)->prev = *head;
	(*tail)->next = NULL;

	*curr = *head;
}

// Add a node and update curr accordingly.
void addNode(node ** curr, char str[]) {
	node * nn = (node *) malloc(sizeof(node));

	strcpy(nn->str, str);
	nn->prev = *curr;
	nn->next = (*curr)->next;

	(*curr)->next->prev = nn;
	(*curr)->next = nn;

	*curr = (*curr)->next;
}

// Delete node pointed to by del.
void deleteNode(node * del) {
	del->prev->next = del->next;
	del->next->prev = del->prev;
	free(del);
}

// Deletes nodes starting from node after start to tail.
void deleteToTail(node * start, node * tail) {
	while (start->next != tail) deleteNode(start->next);
}

// Implement menu functions from here on out. 
void changeStr(node ** curr, node * tail) {
	char str[101];

	printf("New string: ");
	fgets(str, 100, stdin);
	trim(str);

	// Remove unnecessary edits.
	if ((*curr)->next != tail) deleteToTail(*curr, tail);

	addNode(curr, str);
}

void replaceCharAt(node ** curr, node * tail) {
	int index, limit = strlen((*curr)->str) - 1;
	char newStr[101];

	strcpy(newStr, (*curr)->str);

	printf("Enter index (0-%d): ", limit);
	scanf("%d", &index);

	// User entered an invalid value.
	while (index < 0 || index > limit) {
		printf("\nNot a valid index. Try again.\n");
		printf("Enter index (0-%d): ", limit);
		scanf("%d", &index);
	}

	getchar();

	printf("Enter character: ");
	scanf("%c", &newStr[index]);

	if ((*curr)->next != tail) deleteToTail(*curr, tail);
	addNode(curr, newStr);
}

void append(node ** curr, node * tail) {
	char strAppend[101], newStr[101];

	printf("New string: ");
	fgets(strAppend, 100, stdin);
	trim(strAppend);

	strcpy(newStr, (*curr)->str);
	strcat(newStr, strAppend);

	if ((*curr)->next != tail) deleteToTail(*curr, tail);
	addNode(curr, newStr);
}

void undo(node ** curr, node * head) {
	if ((*curr)->prev == head)
		printf("Can't undo.\n");
	else *curr = (*curr)->prev;
}

void redo(node ** curr, node * tail) {
	if ((*curr)->next == tail)
		printf("Can't redo\n");
	else *curr = (*curr)->next;
}