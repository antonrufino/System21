///////////////////////////////////////////////
// main-menu.h                               //
// Handles the main menu of the application. //
///////////////////////////////////////////////

#ifndef MAIN_MENU
#define MAIN_MENU

#include "../util/util.h"
#include "../util/linked-list.h"

#include "food-menu.h"
#include "order-menu.h"

// Prints menu.
void printMainMenu() {
	printf("1. Update Fast food Menu\n");
	printf("2. Take Order\n");
	printf("3. Exit\n\n");

	printf("Choice: ");
}

// Gets input from user and transfers to control to the appropriate submenu.
void mainMenu(LinkedList food, LinkedList order) {
	int choice;

	do {
		cls();
		header();
		printMainMenu();
		scanf("%d", &choice);
		getchar();

		if (choice == 1) foodMenu(food, order);
		else if (choice == 2) orderMenu(order, food);
		else if (choice != 3) {
			printf("Not a valid choice.\n");
			pause();
		}
	} while (choice != 3);
}

#endif