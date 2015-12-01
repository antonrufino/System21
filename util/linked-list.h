//////////////////////////////////////////////////////////////////////////
// linked-list.h                                                        //
// Contains all linked list related operations used by the application. //
//////////////////////////////////////////////////////////////////////////

#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdlib.h>
#include <string.h>
#include "util.h"

// Node structure.
typedef struct NODE_TAG {
	char name[33], code[17], category[17];
	int count;
	float price;
	struct NODE_TAG * prev;
	struct NODE_TAG * next;
} Node;

// Linked list structure
typedef struct LINKED_LIST_TAG {
	Node * head;
	Node * tail;
} LinkedList;

// Initializes a doubly linked list with dummy nodes.
void initLinkedList(LinkedList * ll) {
	ll->head = (Node *) malloc(sizeof(Node));
	ll->tail = (Node *) malloc(sizeof(Node));

	ll->head->prev = NULL;
	ll->head->next = ll->tail;

	ll->tail->prev = ll->head;
	ll->tail->next = NULL;
}

// Add a node to ll with given info.
void addNode(LinkedList ll, char name[], char code[], char category[],
	int count, float price) {
	Node * nn = (Node *) malloc(sizeof(Node));
	Node * i;

	strcpy(nn->name, name);
	strcpy(nn->code, code);
	strcpy(nn->category, category);
	nn->count = count;
	nn->price = price;

	for (i = ll.head; i->next != ll.tail && categoryToInt(category) > categoryToInt(i->next->category); i = i->next);

	nn->prev = i;
	nn->next = i->next;

	i->next->prev = nn;
	i->next = nn;
}

// Searches ll for a node with same name.
// Return value: Pointer to node with same name. Returns NULL if
// it doesn't exist.
Node * searchByName(LinkedList ll, char name[]) {
	Node * i;
	for (i = (ll.head)->next; i != ll.tail; i = i->next)
		if (streqv(i->name, name) == 1) return i;
	return NULL;
}

// Searches ll for a node with same code.
// Return value: Pointer to node with same code. Null if
// it doesn't exist.
Node * searchByCode(LinkedList ll, char code[]) {
	Node * i;
	for (i = (ll.head)->next; i != ll.tail; i = i->next)
		if (strcmp(i->code, code) == 0) return i;
	return NULL;
}

// Deletes node pointed to by del from whatever list it belongs to.
void deleteNode(Node * del) {
	del->prev->next = del->next;
	del->next->prev = del->prev;
	free(del);
}

// Delete all nodes except dummy nodes from list ll.
void deleteList(LinkedList ll) {
	while ((ll.head)->next != ll.tail)
		deleteNode((ll.head)->next);
}

// Deletes dummy nodes from list ll.
// It is advised not to call this function without first calling deleteList.
void freeDummies(LinkedList * ll) {
	free(ll->head);
	free(ll->tail);

	ll->head = NULL;
	ll->tail = NULL;
}

// Checks if a list is empyt i.e. it cointains only its dummy nodes.
int listEmpty(LinkedList ll) {
	return (ll.head)->next == ll.tail;
}

#endif