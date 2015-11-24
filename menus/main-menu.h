///////////////////////////////////////////////
// main-menu.h                               //
// Handles the main menu of the application. //
///////////////////////////////////////////////

#include "../util/ui.h"

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
		printMainMenu();
		scanf("%d", &choice);

		if (choice == 1) printf("Coming soon.\n");
		else if (choice != 3) printf("Not a valid choice.\n");
	} while (choice != 3);
}