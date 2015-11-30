//////////////////////////////////////////////////////////////////////////
// util.h                                                               //
// Functions for handling tasks common to all parts of the application. //
//////////////////////////////////////////////////////////////////////////

#ifndef UTIL
#define UTIL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Clears screen.
void cls() {
	system("clear");
}

// Print application name in ASCII art.
// Generated using figlet.
void header() {
	printf(" ____            _                   ____  _ \n");
	printf("/ ___| _   _ ___| |_ ___ _ __ ___   |___ \\/ |\n");
	printf("\\___ \\| | | / __| __/ _ \\ '_ ` _ \\    __) | |\n");
	printf(" ___) | |_| \\__ \\ ||  __/ | | | | |  / __/| |\n");
	printf("|____/ \\__, |___/\\__\\___|_| |_| |_| |_____|_|\n");
	printf("       |___/                                 \n");
	printf("\n");
}

// Removes trailing newline in str.
void trim(char str[]) {
	int i = strlen(str);
	if (str[i-1] == '\n') str[i-1] = '\0';
}

// Pauses execution until enter is pressed.
void pause() {
	printf("Press Enter to continue...");
	getchar();
}

// Converts a category to a number.
int categoryToInt(char str[]) {
	if (strcmp(str, "Appetizer") == 0) return 1;
	else if (strcmp(str, "Main course") == 0) return 2;
	else if (strcmp(str, "Drink") == 0) return 3;
	else if (strcmp(str, "Dessert") == 0) return 4;
	else return 0;
}

// Converts a number to a category.
char * intToCategory(int n) {
	if (n == 1) return (char *) "Appetizer";
	else if (n == 2) return (char *) "Main course";
	else if (n == 3) return (char *) "Drink";
	else if (n == 4) return (char *) "Dessert";
	else return (char *) "Other";
}

void getString(const char * prompt, int strlen, char name[]) {
	printf("%s", prompt);
	fgets(name, strlen, stdin);
	trim(name);
}

void getInt(const char * prompt, int * count) {
	printf("%s", prompt);
	scanf("%d", count);
	getchar();
}

void getFloat(const char * prompt, float * price) {
	printf("%s", prompt);
	scanf("%f", price);
	getchar();
}

void getCategory(const char * prompt, int * category) {
	printf("%s\n", prompt);
	printf("1. Appetizer\n");
	printf("2. Main course\n");
	printf("3. Drink\n");
	printf("4. Dessert\n");

	printf("\n");
	printf("Choice: ");
	scanf("%d", category);
	getchar();
}

void getYesOrNo(const char * prompt, char * choice) {
	printf("%s (y/n) ", prompt);
	scanf("%c", choice);
	getchar();
}

#endif