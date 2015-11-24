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

#endif