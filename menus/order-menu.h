#ifndef ORDER_MENU
#define ORDER_MENU

#include "../util/ui.h"

void printOrderMenu() {
	printf("1. Add order\n");
	printf("2. View fastfood menu\n");
	printf("3. Remove order\n");
	printf("4. View orders\n");
	printf("5. Cancel order\n");
	printf("6. Edit quantity\n");
	printf("7. Checkout\n");
	printf("8. Back to Main Menu\n\n");

	printf("Choice: ");
}

void orderMenu() {
	int choice;

	do {
		cls();
		header();
		printOrderMenu();
		scanf("%d", &choice);

		if (choice == 1) printf("Coming soon.");
		else if (choice != 8) printf("Not a valid choice.\n");
	} while (choice != 8);
}

#endif