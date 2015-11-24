#ifndef FOOD_TASKS
#define FOOD_TASKS

#include "../util/util.h"

void addFoodItem() {
	char name[32], code[16], category[16];
	int count;
	float price;

	cls();
	header();
	printf("- Add Food Item -\n\n");

	printf("Food item name: ");
	fgets(name, 32, stdin);
	trim(name);

	printf("Food item code: ");
	fgets(code, 16, stdin);
	trim(code);

	printf("Food item count: ");
	scanf("%d", &count);
	getchar();

	printf("Food item price: ");
	scanf("%f", &price);
	getchar();

	printf("Food category: ");
	fgets(category, 16, stdin);
	trim(category);

	//TODO: Place addNode function call here.

	printf("\n");
	printf("New food item successfully added!\n");
	printf("Name: %s\n", name);
	printf("Code: %s\n", code);
	printf("Count: %d\n", count);
	printf("Price: %f\n", price);
	printf("Category: %s\n", category);
	printf("\n");
	pause();
}

void removeFoodItem() {
	char code[16];
	char choice;

	cls();
	header();
	printf("- Remove Food Item -\n\n");

	printf("Food item name: ");
	fgets(code, 16, stdin);
	trim(code);

	printf("\n");
	printf("Are you sure you want to remove item? (y/n) ");
	scanf("%c", &choice);

	if (choice == 'y') {
		printf("Food item %s successfully removed!\n", code);
		pause();
	}
}

#endif