///////////////////////////////
// ffs.c                     //
// Main file of application. //
///////////////////////////////


#include "menus/main-menu.h"
#include "util/linked-list.h"
#include "util/fileio.h"

int main() {
	LinkedList food;
	LinkedList order;

	// Initialize dummy nodes.
	initLinkedList(&food);
	initLinkedList(&order);

	// Load data.
	load(food);

	// Run main menu.
	mainMenu(food, order);
	cls();

	// Save changes.
	save(food);

	// Delete middle nodes.
	deleteList(food);
	deleteList(order);

	// Delete dummy nodes.
	freeDummies(&food);
	freeDummies(&order);

	return 0;
}