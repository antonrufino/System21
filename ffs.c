#include "menus/main-menu.h"
#include "util/linked-list.h"

int main() {
	LinkedList food;
	LinkedList order;

	initLinkedList(&food);
	initLinkedList(&order);
	// TODO: Load data from file.

	mainMenu();
	cls();

	// TODO: Save data to file.
	// TODO: Delete nodes in linked list.

	freeDummies(&food);
	freeDummies(&order);

	return 0;
}