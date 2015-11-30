#ifndef FILEIO
#define FILEIO

#include "util.h"
#include "linked-list.h"

void save(LinkedList list) {
	FILE * fp = fopen("data.txt", "w");
	Node * i;

	if (fp == NULL) {
		printf("Save file cannot be opened.\n");
		return;
	}

	for (i = (list.head)->next; i != list.tail; i = i->next) {
		fprintf(fp, "%s\n", i->name);
		fprintf(fp, "%s\n", i->code);
		fprintf(fp, "%s\n", i->category);
		fprintf(fp, "%d\n", i->count);
		fprintf(fp, "%f\n", i->price);
	}

	fclose(fp);

	printf("Food data saved.\n");
}

void load(LinkedList list) {
	FILE * fp = fopen("data.txt", "r");
	char name[33], code[17], category[17];
	int count;
	float price;

	if (fp == NULL) {
		printf("Save file does not exist. One will be created upon exiting the program.\n");
		return;
	}

	while (!feof(fp)) {
		fgets(name, 32, fp);
		trim(name);

		fgets(code, 16, fp);
		trim(code);

		fgets(category, 16, fp);
		trim(category);

		fscanf(fp, "%d", &count);
		fgetc(fp);

		fscanf(fp, "%f", &price);
		fgetc(fp);

		addNode(list, name, code, category, count, price);
	}
	deleteNode((list.tail)->prev);

	fclose(fp);

	printf("Food data loaded.\n");
}

#endif