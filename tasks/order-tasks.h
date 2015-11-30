///////////////////////////////////////////////
// order-tasks.h                             //
// Implements tasks specified in order menu. //
///////////////////////////////////////////////

// NOTE: In this file, a parameter named order refers to LinkedList containing
// data regarding customer's order while a parameter named food contains data
// about available food.

#ifndef ORDER_TASKS
#define ORDER_TASKS

#include "../util/util.h"
#include "../util/linked-list.h"
#include "food-tasks.h"

// Needed for addOrder to work.
void editQuantity(LinkedList order, LinkedList food, Node * orderItem);

// Facilitates Add Order task
void addOrder(LinkedList order, LinkedList food) {
	int numOrders;
	char query[33];
	char choice;
	Node * orderItem;
	Node * foodItem;

	cls();
	header();
	printf("- Add Order -\n\n");

	getString("Enter food item name or code: ", 32, query);

	// Check if order with existing name or code exists.
	orderItem = searchByName(order, query);
	if (orderItem == NULL) {
		orderItem = searchByCode(order, query);
	}

	// An existing order has been found. Offer user to modify existing order.
	if (orderItem != NULL) {
		getYesOrNo("Order for same item already exists. Change number of orders for existing item?", &choice);

		if (choice == 'y') {
			editQuantity(order, food, orderItem);
		} else {
			pause();
		}

		return;
	}

	// Look for matching item in fast food menu if nothing that matches query
	// has been ordered.
	foodItem = searchByName(food, query);
	if (foodItem == NULL) {
		foodItem = searchByCode(food, query);
		if (foodItem == NULL) {
			printf("Food item not found.\n");
			pause();

			return;
		}
	}

	printf("\n");
	printf("Food item %s found!\n", query);
	getInt("Enter number of orders for item: ", &numOrders);

	// Make sure there is enough food in stock for order.
	if (numOrders > foodItem->count) {
		printf("Not enough of %s in stock.\n", foodItem->name);
		pause();

		return;
	}

	// Add order to list of orders.
	addNode(order, foodItem->name, foodItem->code, foodItem->category, numOrders, foodItem->price);

	printf("\n");
	printf("You ordered %s with quantity of %d\n", foodItem->name, numOrders);
	pause();
}

// Handles viewing of food items in stock
void viewFastFood(LinkedList order, LinkedList food) {
	cls();
	header();
	printf("- View Fast Food Menu -\n\n");

	viewFoodItems(food, order, 1);
}

// Asks for food item code and removes food item with matching code
// from order.
void removeOrder(LinkedList order) {
	char query[33], choice;
	Node * orderItem;

	cls();
	header();
	printf("- Remove Order -\n\n");

	// Check if list is empty.
	if (listEmpty(order)) {
		printf("Nothing has been ordered.\n");
		pause();

		return;
	}

	getString("Enter food item name or code: ", 32, query);

	// Check if order with existing name or code exists.
	orderItem = searchByName(order, query);
	if (orderItem == NULL) {
		orderItem = searchByCode(order, query);
	}

	// If order exists, ask user if he is sure with what he's doing.
	// If yes, delete order from list.
	// Else, finish function.
	if (orderItem != NULL) {
		getYesOrNo("Are you sure you want to remove order?", &choice);

		printf("\n");
		if (choice == 'y') {
			deleteNode(orderItem);
			printf("Item successfully removed from order.\n");
		}
	} else {
		printf("This item has not been ordered.\n");
	}
	pause();
}

// View all orders.
//
// Extra parameters
// showHeader: Set to 1 if header and pause should be shown. 0 otherwise.
// Needed for checkout function.
void viewOrders(LinkedList order, int showHeader) {
	float totalCost = 0.0, cost;
	Node * i;

	// Should we be showing the header?
	if (showHeader) {
		cls();
		header();
		printf("- View Orders -\n\n");
	}

	// Make sure list is not empty before proceeding.
	if (listEmpty(order)) {
		printf("Nothing has been ordered.\n");
		pause();

		return;
	}

	// Prints all orders together with total cost.
	printf("Name\tCode\tPrice\tQty\tCost\n");
	for (i = (order.head)->next; i != order.tail; i = i->next) {
		cost = i->price * i->count;
		printf("%s\t%s\t%4.2f\t%d\t%4.2f\n", i->name, i->code, i->price, i->count, cost);
		totalCost += cost;
	}
	printf("Total cost: %4.2f\n", totalCost);

	printf("\n");

	// Should we be showing pause message?
	if (showHeader) pause();
}

// Handles cancelling of entire order.
void cancelOrder(LinkedList order) {
	char choice;

	cls();
	header();
	printf("- Cancel Order -\n\n");

	// Check if anything has been ordered.
	if (listEmpty(order)) {
		printf("Nothing has been ordered.\n");
		pause();

		return;
	}

	// Make sure user knows what he is doing.
	getYesOrNo("Are you sure you want to cancel your order?", &choice);

	// If yes, delete everything.
	printf("\n");
	if (choice == 'y') {
		deleteList(order);
		printf("All orders cancelled.\n");
	}
	pause();
}

// Update qunatity of food item in order.
//
// Extra parameters
// orderItem: The order to be modified. Added for addOrder function.
void editQuantity(LinkedList order, LinkedList food, Node * orderItem) {
	char code[17];
	int newQty;
	Node * foodItem;

	// If orderItem does not exist, ask user for order to delete.
	if (orderItem == NULL) {
		cls();
		header();
		printf("- Edit Quantity -\n\n");

		// Make sure there is an order.
		if (listEmpty(order)) {
			printf("Nothing has been ordered.\n");
			pause();

			return;
		}

		// Get code of item to delete.
		getString("Food item code: ", 16, code);
		orderItem = searchByCode(order, code);

		// Order does not exist.
		if (orderItem == NULL) {
			printf("\n");
			printf("Item has not been ordered.\n");
			pause();

			return;
		}
	}

	getInt("New quantity: ", &newQty);
	foodItem = searchByCode(food, orderItem->code);

	// Make sure there is enough food in stock for new order.
	if (newQty > foodItem->count) {
		printf("\n");
		printf("Not enough of item in stock.\n");
		printf("Order will remain unchanged.\n");
	} else {
		orderItem->count = newQty;

		printf("\n");
		printf("Order successfully updated.\n");
	}

	pause();
}

// Checkout order.
void checkout(LinkedList order, LinkedList food) {
	char choice;
	Node * i, * foodItem;

	cls();
	header();
	printf("- Checkout -\n\n");

	// Make sure there is an order to checkout.
	if (listEmpty(order)) {
		printf("Nothing has been ordered.\n");
		pause();

		return;
	}

	// View all orders together with total cost.
	// Second argument (showHeader) set to 0 to prevent the
	// current header from changing.
	viewOrders(order, 0);

	// Check if user is sure with what he is doing.
	getYesOrNo("Checkout orders? ", &choice);
	if (choice == 'y') {
		// Modify info on food stocks.
		for (i = (order.head)->next; i != order.tail; i = i->next) {
			foodItem = searchByCode(food, i->code);
			foodItem->count -= i->count;
			deleteNode(i);
		}

		printf("Orders successfully checked out.\n");
	}

	pause();
}

#endif