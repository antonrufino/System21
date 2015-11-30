#ifndef FOOD_MENU
#define FOOD_MENU

#include "../util/util.h"
#include "../tasks/food-tasks.h"

void printFoodMenu() {
	printf("1. Add Food Item\n");
	printf("2. Remove Food Item\n");
	printf("3. Update Food Price\n");
	printf("4. Update Food Item Count\n");
	printf("5. Update Food Category\n");
	printf("6. View Food Items\n");
	printf("7. Back to Main Menu\n\n");

	printf("Choice: ");
}

void foodMenu(LinkedList food) {
	int choice;

	do {
		cls();
		header();
		printFoodMenu();
		scanf("%d", &choice);
		getchar();

		if (choice == 1) addFoodItem(food);
		else if (choice == 2) removeFoodItem(food);
		else if (choice == 3) updateFoodPrice(food);
		else if (choice == 4) updateFoodCount(food);
		else if (choice == 5) updateFoodCategory(food);
		else if (choice == 6) viewFoodItems(food, 0);
		else if (choice != 7) printf("Not a valid choice.\n");
	} while (choice != 7);
}

#endif