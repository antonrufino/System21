#ifndef FOOD_MENU
#define FOOD_MENU

#include "../util.h"

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

void foodMenu() {
	int choice;

	do {
		cls();
		header();
		printFoodMenu();
		scanf("%d", &choice);

		if (choice == 1) printf("Coming soon.");
		else if (choice != 7) printf("Not a valid choice.\n");
	} while (choice != 7);
}

#endif