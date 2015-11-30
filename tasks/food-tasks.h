/////////////////////////////////////////////////////////////
// food-tasks.h                                            //
// This file implements the tasks listed in the food menu. //
/////////////////////////////////////////////////////////////

// NOTE: In this file, a parameter named order refers to LinkedList containing
// data regarding available food.

#ifndef FOOD_TASKS
#define FOOD_TASKS

#include "../util/util.h"
#include "../util/linked-list.h"

// Add new food item to fast food menu.
void addFoodItem(LinkedList food) {
	char name[33], code[17];
	int count, category;
	float price;

	cls();
	header();
	printf("- Add Food Item -\n\n");

	getString("Food item name: ", 32, name);

	// Make sure name is unique.
	if (searchByName(food, name) != NULL) {
		printf("\n");
		printf("Food item with same name already exists.\n");
		pause();

		return;
	}

	getString("Food item code: ", 16, code);

	// Make sure code is unique.
	if (searchByCode(food, code) != NULL) {
		printf("\n");
		printf("Food item with same code already exists.\n");
		pause();

		return;
	}

	getInt("Food item count: ", &count);
	getFloat("Food item price: ", &price);
	getCategory("Food item category:", &category, 0);

	// Add order to list.
	addNode(food, name, code, intToCategory(category), count, price);

	printf("\n");
	printf("New food item successfully added!\n");
	pause();
}

// Removes food item from list.
void removeFoodItem(LinkedList food) {
	char code[17];
	char choice;
	Node * del;

	cls();
	header();
	printf("- Remove Food Item -\n\n");

	// Make sure list is not empty before proceeding.
	if (listEmpty(food)) {
		printf("No food in stock.\n");
		pause();
		return;
	}

	getString("Food item code: ", 16, code);

	// Check if item being deleted exists.
	del = searchByCode(food, code);
	if (del != NULL) {
		// Check if user is sure.
		getYesOrNo("Are you sure you want to remove item?", &choice);

		// If yes, delete order.
		if (choice == 'y') {
			deleteNode(del);

			printf("\n");
			printf("Food item %s successfully removed!\n", code);
		}
	} else { // Food item to be deleted does not exist.
		printf("\n");
		printf("Food item not found.\n");
	}
	pause();
}

// Changes price of food item.
void updateFoodPrice(LinkedList food) {
	char code[17];
	float newPrice;
	Node * foodItem;

	cls();
	header();
	printf("- Update Food Price -\n\n");

	// Make sure list is not empty.
	if (listEmpty(food)) {
		printf("No food in stock.\n");
		pause();
		return;
	}

	getString("Food item code: ", 16, code);

	// Make sure food item to be modified exists.
	foodItem = searchByCode(food, code);
	if (foodItem != NULL) { // Food item exists.
		printf("Food item %s found!\n", code);

		printf("\n");
		getFloat("New price: ", &newPrice);

		foodItem->price = newPrice; // Modify price.
		printf("Food item %s sucessfully updated!\n", code);
	} else { // Food item does not exist.
		printf("\n");
		printf("Food item not found.\n");
	}

	pause();
}

// Changes count of food item. Similar to updateFoodPrice.
void updateFoodCount(LinkedList food) {
	char code[17];
	int newCount;
	Node * foodItem;

	cls();
	header();
	printf("- Update Food Count -\n\n");

	if (listEmpty(food)) {
		printf("No food in stock.\n");
		pause();
		return;
	}

	getString("Food item code: ", 16, code);

	foodItem = searchByCode(food, code);
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

// Change category of food item.
void updateFoodCategory(LinkedList food) {
	char code[17];
	int newCategory;
	Node * foodItem;

	cls();
	header();
	printf("- Update Food Category -\n\n");

	if (listEmpty(food)) {
		printf("No food in stock.\n");
		pause();
		return;
	}

	getString("Food item code: ", 16, code);

	foodItem = searchByCode(food, code);

	if (foodItem != NULL) {
		getCategory("New food category: ", &newCategory, 0);

		// Make sure new category is not the same as old category.
		if (strcmp(foodItem->category, intToCategory(newCategory)) != 0) {
			// Category of food item is "changed" by first adding a new food
			// item with the same data but with the new category. The food
			// item with the old category is then deleted.
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

// Views food items. Lets user view only a single category.
//
// Extra paramerter
// inStock: Set to 1 if only food that is in stock (count > 0) should be shown.
// Set to 0 otherwise.
// order: List of orders. Used only for view fast food items in order submenu.
void viewFoodItems(LinkedList food, LinkedList order, int inStock) {
	int category, count;
	Node * i, * orderItem;

	if (!inStock) {
		cls();
		header();
		printf("- View Food Items -\n\n");
	}

	if (!listEmpty(food)) {
		getCategory("Food item category (Enter 0 to view all):", &category, 1);

		printf("\n");
		printf("CODE\tNAME\tPRICE\tQTY\tCATEGORY\n");
		for (i = (food.head)->next; i != food.tail; i = i->next) {
			count = i->count;
			if (inStock) {
				orderItem = searchByCode(order, i->code);
				if (orderItem != NULL) {
					count -= orderItem->count;
				}
			}

			if ((categoryToInt(i->category) == category || category == 0) && (count > 0 || !inStock))
				printf("%s\t%s\t%.2f\t%d\t%s\n", i->code, i->name, i->price, count, i->category);
		}
	} else {
		printf("No food in stock.");
	}
	printf("\n");
	pause();
}

#endif