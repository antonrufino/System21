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

	getString("Food item name: ", 32, name);
	if (searchByName(*food, name) != NULL) {
		printf("\n");
		printf("Food item with same name already exists.\n");
		pause();

		return;
	}

	getString("Food item code: ", 16, code);
	if (searchByCode(*food, code) != NULL) {
		printf("\n");
		printf("Food item with same code already exists.\n");
		pause();

		return;
	}

	getInt("Food item count: ", &count);
	getFloat("Food item price: ", &price);
	getCategory("Food item category:", &category);

	addNode(food, name, code, intToCategory(category), count, price);

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

	getString("Food item code: ", 16, code);

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

	getString("Food item code: ", 16, code);

	foodItem = searchByCode(*food, code);
	if (foodItem != NULL) {
		printf("Food item %s found!\n", code);

		printf("\n");
		getFloat("New price: ", &newPrice);

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

	getString("Food item code: ", 16, code);

	foodItem = searchByCode(*food, code);
	if (foodItem != NULL) {
		printf("Food item %s found!\n", code);

		printf("\n");
		getInt("New quantity: ", &newCount);

		foodItem->count = newCount;
		printf("Food item %s sucessfully updated!\n", code);
	} else {
		printf("\n");
		printf("Food item not found.\n");
	}

	pause();
}

void updateFoodCategory(LinkedList * food) {
	char code[17];
	int newCategory;
	Node * foodItem;

	cls();
	header();
	printf("- Update Food Category -\n\n");

	if (listEmpty(*food)) {
		printf("No food in stock.\n");
		pause();
		return;
	}

	getString("Food item code: ", 16, code);

	foodItem = searchByCode(*food, code);

	if (foodItem != NULL) {
		getCategory("New food category: ", &newCategory);

		if (strcmp(foodItem->category, intToCategory(newCategory)) != 0) {
			addNode(food, foodItem->name, foodItem->code, intToCategory(newCategory), foodItem->count, foodItem->price);
			deleteNode(foodItem);

			printf("\n");
			printf("Food item successfully updated!\n");
		} else {
			printf("\n");
			printf("Category entered is the same as current category of food item %s. Nothing changed.\n", code);
		}
	} else {
		printf("\n");
		printf("Food item not found.\n");
	}

	pause();
}

void viewFoodItems(LinkedList * food) {
	int category;
	Node * i;

	cls();
	header();
	printf("- View Food Items -\n\n");

	if (!listEmpty(*food)) {
		getCategory("Food item category (Enter 0 to view all):", &category);

		printf("\n");
		printf("CODE\tNAME\tPRICE\tQTY\tCATEGORY\n");
		for (i = food->head->next; i != food->tail; i = i->next) {
			if (categoryToInt(i->category) == category || category == 0)
				printf("%s\t%s\t%.2f\t%d\t%s\n", i->code, i->name, i->price, i->count, i->category);
		}
	} else {
		printf("No food in stock.");
	}
	printf("\n");
	pause();
}

#endif