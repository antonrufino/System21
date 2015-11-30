/////////////////////////////////////////////////
// order-menu.h                                //
// Handles presentation of order menu to user. //
/////////////////////////////////////////////////


#ifndef ORDER_MENU
#define ORDER_MENU

#include "../util/util.h"
#include "../util/linked-list.h"

#include "../tasks/order-tasks.h"

// Prints menu.
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

// Handles collection of user input and calling of appropriate function to
// handle a task.
void orderMenu(LinkedList order, LinkedList food) {
	int choice;

	do {
		cls();
		header();
		printOrderMenu();
		scanf("%d", &choice);
		getchar();

		if (choice == 1) addOrder(order, food);
		else if (choice == 2) viewFastFood(order, food);
		else if (choice == 3) removeOrder(order);
		else if (choice == 4) viewOrders(order, 1);
		else if (choice == 5) cancelOrder(order);
		else if (choice == 6) editQuantity(order, food, NULL);
		else if (choice == 7) checkout(order, food);
		else if (choice != 8) {
			printf("Not a valid choice.\n");
			pause();
		}
	} while (choice != 8);
}

#endif