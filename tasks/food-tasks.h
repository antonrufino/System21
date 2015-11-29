/////////////////////////////////////////////////////////////
// food-tasks.h                                            //
// This file implements the tasks listed in the food menu. //
/////////////////////////////////////////////////////////////

#ifndef FOOD_TASKS
#define FOOD_TASKS

#include "../util/util.h"
#include "../util/linked-list.h"

// Add new food item to fast food menu.
void addFoodItem(LinkedList * food) {
	char name[33], code[17];
	int count, category;
	float price;

	cls();
	header();
	printf("- Add Food Item -\n\n");

	printf("Food item name: ");
	fgets(name, 32, stdin);
	trim(name);

	// TODO: Check if food item with same name exists, i.e. search based on
	// name.

	printf("Food item code: ");
	fgets(code, 16, stdin);
	trim(code);

	// TODO: Check if food item with same code exists, i.e., search based on
	// code.

	// IDEA: If item with existing name found, update information instead of
	// showing error.

	printf("Food item count: ");
	scanf("%d", &count);
	getchar();

	printf("Food item price: ");
	scanf("%f", &price);
	getchar();

	printf("Food category:\n");
	printf("1. Appetizer\n");
	printf("2. Main course\n");
	printf("3. Drink\n");
	printf("4. Dessert\n");

	printf("\n");
	printf("Choice: ");
	scanf("%d", &category);
	getchar();

	// TODO: Place addNode function call here.
	addNode(food, name, code, intToCategory(category), count, price);
	// TODO: Update stock info.

	printf("\n");
	printf("New food item successfully added!\n");
	pause();
}

void removeFoodItem(LinkedList * food) {
	char code[17];
	char choice;
	Node * del;

	cls();
	header();
	printf("- Remove Food Item -\n\n");

	if (listEmpty(*food)) {
		printf("No food in stock.\n");
		pause();
		return;
	}

	printf("Food item code: ");
	fgets(code, 16, stdin);
	trim(code);

	del = searchByCode(*food, code);
	if (del != NULL) {
		printf("Are you sure you want to remove item? (y/n) ");
		scanf("%c", &choice);
		getchar();

		if (choice == 'y') {
			deleteNode(del);

			printf("\n");
			printf("Food item %s successfully removed!\n", code);
		}
	} else {
		printf("\n");
		printf("Food item not found.\n");
	}
	pause();
}

void updateFoodPrice(LinkedList * food) {
	char code[17];
	float newPrice;
	Node * foodItem;

	cls();
	header();
	printf("- Update Food Price -\n\n");

	if (listEmpty(*food)) {
		printf("No food in stock.\n");
		pause();
		return;
	}

	printf("Food item code: ");
	fgets(code, 16, stdin);
	trim(code);

	foodItem = searchByCode(*food, code);
	if (foodItem != NULL) {
		printf("Food item %s found!\n", code);

		printf("\n");
		printf("New food price: ");
		scanf("%f", &newPrice);
		getchar();

		foodItem->price = newPrice;
		printf("Food item %s sucessfully updated!\n", code);
	} else {
		printf("\n");
		printf("Food item not found.\n");
	}

	pause();
}

void updateFoodCount(LinkedList * food) {
	char code[17];
	int newCount;
	Node * foodItem;

	cls();
	header();
	printf("- Update Food Count -\n\n");

	if (listEmpty(*food)) {
		printf("No food in stock.\n");
		pause();
		return;
	}

	printf("Food item code: ");
	fgets(code, 16, stdin);
	trim(code);

	foodItem = searchByCode(*food, code);
	if (foodItem != NULL) {
		printf("Food item %s found!\n", code);

		printf("\n");
		printf("New food quantity: ");
		scanf("%d", &newCount);
		getchar();

		foodItem->count = newCount;
		printf("Food item %s sucessfully updated!\n", code);
	} else {
		printf("\n");
		printf("Food item not found.\n");
	}

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

	//TODO: Search by code.

	printf("New food item category: ");
	fgets(newCategory, 16, stdin);
	trim(newCategory);

	printf("\n");
	printf("Food item successfully updated!\n");
	pause();
}

void viewFoodItems(LinkedList * food) {
	char category[17];
	Node * i;

	cls();
	header();
	printf("- View Food Items -\n\n");

	if (!listEmpty(*food)) {
		printf("Food item category: ");
		fgets(category, 16, stdin);
		trim(category);

		// TODO: Print nodes with given category.
		printf("CODE\tNAME\tPRICE\tQTY\tCATEGORY\n");
		for (i = food->head->next; i != food->tail; i = i->next) {
			printf("%s\t%s\t%.2f\t%d\t%s\n", i->code, i->name, i->price, i->count, i->category);
		}
	} else {
		printf("No food in stock.");
	}
	printf("\n");
	pause();
}

#endif