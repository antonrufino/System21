/////////////////////////////////////////////////////////////
// food-tasks.h                                            //
// This file implements the tasks listed in the food menu. //
/////////////////////////////////////////////////////////////

#ifndef FOOD_TASKS
#define FOOD_TASKS

#include "../util/util.h"

void addFoodItem() {
	char name[33], code[17], category[17];
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
	char code[17];
	char choice;

	cls();
	header();
	printf("- Remove Food Item -\n\n");

	printf("Food item code: ");
	fgets(code, 16, stdin);
	trim(code);

	printf("Are you sure you want to remove item? (y/n) ");
	scanf("%c", &choice);
	getchar();

	if (choice == 'y') {
		printf("\n");
		printf("Food item %s successfully removed!\n", code);
		pause();
	}
}

void updateFoodPrice() {
	char code[17];
	float newPrice;

	cls();
	header();
	printf("- Update Food Price -\n\n");

	printf("Food item code: ");
	fgets(code, 16, stdin);
	trim(code);

	printf("New food price: ");
	scanf("%f", &newPrice);
	getchar();

	printf("\n");
	printf("Food item successfully updated!\n");
	pause();
}

void updateFoodCount() {
	char code[17];
	int newCount;

	cls();
	header();
	printf("- Update Food Item Count -\n\n");

	printf("Food item code: ");
	fgets(code, 16, stdin);
	trim(code);

	printf("New food item count: ");
	scanf("%d", &newCount);
	getchar();

	printf("\n");
	printf("Food item successfully updated!\n");
	pause();
}

void updateFoodCategory() {
	char code[17];
	char newCategory[17];

	cls();
	header();
	printf("- Update Food Category -\n\n");

	printf("Food item code: ");
	fgets(code, 16, stdin);
	trim(code);

	printf("New food item category: ");
	fgets(newCategory, 16, stdin);
	trim(newCategory);

	printf("\n");
	printf("Food item successfully updated!\n");
	pause();
}

void viewFoodItems() {
	char category[17];

	cls();
	header();
	printf("- View Food Items -\n\n");

	printf("Food item category: ");
	fgets(category, 16, stdin);
	trim(category);

	printf("FOOD ITEMS COMING SOON...\n");
	pause();
}

#endif