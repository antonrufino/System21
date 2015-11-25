#include "menus/main-menu.h"
#include "util/linked-list.h"

int main() {
	LinkedList food;
	LinkedList order;

	// Initialize dummy nodes.
	initLinkedList(&food);
	initLinkedList(&order);
	// TODO: Load data from file.

	mainMenu(&food, &order);
	cls();

	// TODO: Save data to file.
	// TODO: Delete nodes in linked list.

	// Delete middle nodes.
	deleteList(&food);
	deleteList(&order);

	// Delete dummy nodes.
	freeDummies(&food);
	freeDummies(&order);

	return 0;
}