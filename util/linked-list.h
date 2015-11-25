#include <stdlib.h>
#include <string.h>

typedef struct NODE {
	char name[33], code[17], category[17];
	int count;
	float price;
	struct NODE * prev;
	struct NODE * next;
} Node;

typedef struct LINKED_LIST {
	Node * head;
	Node * tail;
} LinkedList;

void initLinkedList(LinkedList * ll) {
	ll->head = (Node *) malloc(sizeof(Node));
	ll->tail = (Node *) malloc(sizeof(Node));

	ll->head->prev = NULL;
	ll->head->next = ll->tail;

	ll->tail->prev = ll->head;
	ll->tail->next = NULL;
}

void freeDummies(LinkedList * ll) {
	free(ll->head);
	free(ll->tail);

	ll->head = NULL;
	ll->tail = NULL;
}