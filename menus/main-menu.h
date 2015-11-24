///////////////////////////////////////////////
// main-menu.h                               //
// Handles the main menu of the application. //
///////////////////////////////////////////////

#ifndef MAIN_MENU
#define MAIN_MENU

#include "../util.h"
#include "food-menu.h"
#include "order-menu.h"

void printMainMenu() {
	printf("1. Update Fast food Menu\n");
	printf("2. Take Order\n");
	printf("3. Exit\n\n");

	printf("Choice: ");
}

void mainMenu() {
	int choice;

	do {
		cls();
		header();
		printMainMenu();
		scanf("%d", &choice);

		if (choice == 1) foodMenu();
		else if (choice == 2) orderMenu();
		else if (choice != 3) printf("Not a valid choice.\n");
	} while (choice != 3);
}

#endif