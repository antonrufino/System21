#include "rufino12.h"

int main() {
	int choice;
	node * head, * tail;
	node * curr; // Current edit. Similar to git's HEAD.
	char str[100];

	initList(&head, &tail, &curr);

	printf("Enter a string: ");
	fgets(str, 100, stdin);
	trim(str);

	addNode(&curr, str);

	do {
		printMenu(curr->str);
		scanf("%d", &choice);

		if (choice == 1) {
			printEditMenu();
			scanf("%d", &choice);
			getchar();

			if (choice == 1) {
				changeStr(&curr, tail);
			} else if (choice == 2) {
				replaceCharAt(&curr, tail);
			} else if (choice == 3) {
				append(&curr, tail);
			} else if (choice == 4) {
				choice = 0; // Prevents program from exiting.
			}
		} else if (choice == 2) {
			undo(&curr, head);
		} else if (choice == 3) {
			redo(&curr, tail);
		}
	} while (choice != 4);

	// Delete everything except dummy nodes.
	deleteToTail(head, tail);

	// Delete dummies.
	free(head);
	free(tail);

	return 0;
}

