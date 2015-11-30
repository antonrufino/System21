///////////////////////////////////////////////
// order-tasks.h                             //
// Implements tasks specified in order menu. //
///////////////////////////////////////////////

#ifndef ORDER_TASKS
#define ORDER_TASKS

#include "../util/util.h"
#include "../util/linked-list.h"
#include "food-tasks.h"

void addOrder(LinkedList order, LinkedList food);
void viewFastFood(LinkedList food);
void removeOrder();
void viewOrders(LinkedList order);
void cancelOrder(LinkedList order);
void editQuantity(LinkedList order, LinkedList food, Node * orderItem);
void checkout();

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

	if (orderItem != NULL) {
		getYesOrNo("Order for same item already exists. Change number of orders for existing item?", &choice);

		if (choice == 'y') {
			editQuantity(order, food, orderItem);
		} else {
			pause();
		}

		return;
	}

	// List will first be searched by product name. If there is no product
	// given name, list will be searched by code.
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

	if (numOrders > foodItem->count) {
		printf("Not enough of %s in stock.\n", foodItem->name);
		pause();

		return;
	}

	addNode(order, foodItem->name, foodItem->code, foodItem->category, numOrders, foodItem->price);

	printf("\n");
	printf("You ordered %s with quantity of %d\n", foodItem->name, numOrders);
	pause();
}

// Handles viewing of food items in stock
void viewFastFood(LinkedList food) {
	cls();
	header();
	printf("- View Fast Food Menu -\n\n");

	viewFoodItems(food, 1);
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

void viewOrders(LinkedList order) {
	float totalCost = 0.0, cost;
	Node * i;

	cls();
	header();
	printf("- View Orders -\n\n");

	if (listEmpty(order)) {
		printf("Nothing has been ordered.\n");
		pause();

		return;
	}

	printf("Name\tCode\tPrice\tQty\tCost\n");
	for (i = (order.head)->next; i != order.tail; i = i->next) {
		cost = i->price * i->count;
		printf("%s\t%s\t%4.2f\t%d\t%4.2f\n", i->name, i->code, i->price, i->count, cost);
		totalCost += cost;
	}
	printf("Total cost: %4.2f\n", totalCost);

	printf("\n");
	pause();
}

// Handles cancelling of entire order.
void cancelOrder(LinkedList order) {
	char choice;

	cls();
	header();
	printf("- Cancel Order -\n\n");

	getYesOrNo("Are you sure you want to cancel your order?", &choice);

	printf("\n");
	if (choice == 'y') {
		deleteList(order);
		printf("All orders cancelled.\n");
	}
	pause();
}

// Update qty of food item in order.
void editQuantity(LinkedList order, LinkedList food, Node * orderItem) {
	char code[17];
	int newQty;
	Node * foodItem;

	if (orderItem == NULL) {
		cls();
		header();
		printf("- Edit Quantity -\n\n");

		getString("Food item code: ", 16, code);
		orderItem = searchByCode(order, code);

		if (orderItem == NULL) {
			printf("\n");
			printf("Item has not been ordered.\n");
			pause();

			return;
		}
	}

	// If code exists then
	getInt("New quantity: ", &newQty);
	foodItem = searchByCode(food, orderItem->code);

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

void checkout() {
	cls();
	header();
	printf("- Checkout -\n\n");

	// TODO: List traversal.

	// Dummy data once more.

	printf("Name\tCode\tPrice\tQty\tCost\n");
	printf("Order 1 \t %4.2f\n", 1000.0);
	printf("Order 2 \t %4.2f\n", 20.0);
	printf("Order 3 \t %4.2f\n", 30.0);
	printf("Total: %4.2f\n", 1050.0);
	printf("\n");

	pause();
}

#endif