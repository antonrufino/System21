#ifndef ORDER_TASKS
#define ORDER_TASKS

#include "../util/util.h"

void addOrder() {
	int numOrders;
	char query[33];

	cls();
	header();
	printf("- Add Order -\n\n");

	printf("Enter food item name or code: ");
	fgets(query, 32, stdin);
	trim(query);

	printf("\n");
	printf("Food item %s found!\n", query);
	printf("Enter number of orders for %s: ", query);
	scanf("%d", &numOrders);
	getchar();

	printf("\n");
	printf("You ordered %s with quantity of %d\n", query, numOrders);
	pause();
}

void viewFastFood() {
	char category[17];

	cls();
	header();
	printf("- View Fast Food Menu -\n\n");

	printf("Food item category: ");
	fgets(category, 16, stdin);
	trim(category);

	printf("FOOD ITEMS IN STOCK COMING SOON...\n");
	pause();
}

void removeOrder() {
	char code[17], choice;

	cls();
	header();
	printf("- Remove Order -\n\n");

	printf("Food item code: ");
	fgets(code, 16, stdin);
	trim(code);

	printf("Are you sure you want to remove %s from the orders? (y/n) ", "Burger");
	scanf("%c", &choice);
	getchar();

	printf("\n");
	if (choice == 'y')
		printf("%s removed from order.\n", "Burger");

	pause();
}

void viewOrders() {
	cls();
	header();
	printf("- View Orders -\n\n");

	printf("Order 1 \t %4.2f\n", 1000.0);
	printf("Order 2 \t %4.2f\n", 20.0);
	printf("Order 3 \t %4.2f\n", 30.0);
	printf("Total: %4.2f\n", 1050.0);
	printf("\n");

	pause();
}

void cancelOrder() {
	char choice;

	cls();
	header();
	printf("- Cancel Order -\n\n");

	printf("Are you sure you want to cancel your order? (y/n) ");
	scanf("%c", &choice);
	getchar();

	printf("\n");
	if (choice == 'y')
		printf("All orders cancelled.\n");

	pause();
}

void editQuantity() {
	char code[17];
	int newQty;

	cls();
	header();
	printf("- Edit Quantity -\n\n");

	printf("Food item code: ");
	fgets(code, 16, stdin);
	trim(code);

	printf("New quantity: ");
	scanf("%d", &newQty);
	getchar();

	printf("\n");
	printf("Order successfully updated.\n");
	pause();
}

#endif