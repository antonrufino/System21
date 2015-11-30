#include "menus/main-menu.h"
#include "util/linked-list.h"
#include "util/fileio.h"

int main() {
	LinkedList food;
	LinkedList order;

	// Initialize dummy nodes.
	initLinkedList(&food);
	initLinkedList(&order);

	load(food);

	mainMenu(food, order);
	cls();

	save(food);

	// Delete middle nodes.
	deleteList(food);
	deleteList(order);

	// Delete dummy nodes.
	freeDummies(&food);
	freeDummies(&order);

	return 0;
}