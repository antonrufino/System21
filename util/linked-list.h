#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdlib.h>
#include <string.h>
#include "util.h"

typedef struct NODE_TAG {
	char name[33], code[17], category[17];
	int count;
	float price;
	struct NODE_TAG * prev;
	struct NODE_TAG * next;
} Node;

typedef struct LINKED_LIST_TAG {
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

void addNode(LinkedList * ll, char name[], char code[], char category[],
	int count, float price) {
	Node * nn = (Node *) malloc(sizeof(Node));
	Node * i;

	strcpy(nn->name, name);
	strcpy(nn->code, code);
	strcpy(nn->category, category);
	nn->count = count;
	nn->price = price;

	for (i = ll->head; i->next != ll->tail && categoryToInt(category) > categoryToInt(i->next->category); i = i->next);

	nn->prev = i;
	nn->next = i->next;

	i->next->prev = nn;
	i->next = nn;
}

Node * searchByName(LinkedList ll, char name[]) {
	Node * i;
	for (i = (ll.head)->next; i != ll.tail; i = i->next)
		if (strcmp(i->name, name) == 0) return i;
	return NULL;
}

Node * searchByCode(LinkedList ll, char code[]) {
	Node * i;
	for (i = (ll.head)->next; i != ll.tail; i = i->next)
		if (strcmp(i->code, code) == 0) return i;
	return NULL;
}

void deleteNode(Node * del) {
	del->prev->next = del->next;
	del->next->prev = del->prev;
	free(del);
}

void deleteList(LinkedList * ll) {
	while (ll->head->next != ll->tail)
		deleteNode(ll->head->next);
}

void freeDummies(LinkedList * ll) {
	free(ll->head);
	free(ll->tail);

	ll->head = NULL;
	ll->tail = NULL;
}

int listEmpty(LinkedList ll) {
	return (ll.head)->next == ll.tail;
}

#endif