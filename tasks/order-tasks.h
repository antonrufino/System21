///////////////////////////////////////////////
// order-tasks.h                             //
// Implements tasks specified in order menu. //
///////////////////////////////////////////////

#ifndef ORDER_TASKS
#define ORDER_TASKS

#include "../util/util.h"
#include "../util/linked-list.h"

// Facilitates Add Order task
void addOrder() {
	int numOrders;
	char query[33];

	cls();
	header();
	printf("- Add Order -\n\n");

	printf("Enter food item name or code: ");
	fgets(query, 32, stdin);
	trim(query);

	// TODO: Implement search here.
	// List will first be searched by product name. If there is no product
	// given name, list will be searched by code.

	// IDEA: If existing order found, update order instead of showing error.

	printf("\n");
	printf("Food item %s found!\n", query);
	printf("Enter number of orders for %s: ", query);
	scanf("%d", &numOrders);
	getchar();

	// TODO: Implement adding of node to list with given data.
	// TODO: Update stock info

	printf("\n");
	printf("You ordered %s with quantity of %d\n", query, numOrders);
	pause();
}

// Handles viewing of food items in stock
void viewFastFood() {
	char category[17];

	cls();
	header();
	printf("- View Fast Food Menu -\n\n");

	printf("Food item category: ");
	fgets(category, 16, stdin);
	trim(category);

	// TODO: Traverse list. Print only those with matching category.
	printf("FOOD ITEMS IN STOCK COMING SOON...\n");
	pause();
}

// Asks for food item code and removes food item with matching code
// from order.
void removeOrder() {
	char code[17], choice;

	cls();
	header();
	printf("- Remove Order -\n\n");

	printf("Food item code: ");
	fgets(code, 16, stdin);
	trim(code);

	// TODO: Search for food item with given code.
	// Stop task if nothing found.

	printf("Are you sure you want to remove %s from the orders? (y/n) ", "Burger");
	scanf("%c", &choice);
	getchar();

	printf("\n");
	if (choice == 'y')
		// TODO: Remove node.
		// TODO: Update stock info.
		printf("%s removed from order.\n", "Burger");

	pause();
}

void viewOrders() {
	cls();
	header();
	printf("- View Orders -\n\n");

	// TODO: Replace this with actual data by printing nodes in order list.

	// Dummy data.
	printf("Order 1 \t %4.2f\n", 1000.0);
	printf("Order 2 \t %4.2f\n", 20.0);
	printf("Order 3 \t %4.2f\n", 30.0);
	printf("Total: %4.2f\n", 1050.0);
	printf("\n");

	pause();
}

// Handles cancelling of entire order.
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
		// TODO: Delete everything in list except dummy nodes.
		printf("All orders cancelled.\n");

	pause();
}

// Update qty of food item in order.
void editQuantity() {
	char code[17];
	int newQty;

	cls();
	header();
	printf("- Edit Quantity -\n\n");

	printf("Food item code: ");
	fgets(code, 16, stdin);
	trim(code);

	// TODO: Search by food item code.

	// If code exists then
	printf("New quantity: ");
	scanf("%d", &newQty);
	getchar();

	printf("\n");
	printf("Order successfully updated.\n");
	pause();
}

void checkout() {
	cls();
	header();
	printf("- Checkout -\n\n");

	// TODO: List traversal.

	// Dummy data once more.
	printf("Order 1 \t %4.2f\n", 1000.0);
	printf("Order 2 \t %4.2f\n", 20.0);
	printf("Order 3 \t %4.2f\n", 30.0);
	printf("Total: %4.2f\n", 1050.0);
	printf("\n");

	pause();
}

#endif