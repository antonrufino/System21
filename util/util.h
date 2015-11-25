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
	if (strcmp(str, "Main course") == 0) return 2;
	if (strcmp(str, "Drink") == 0) return 3;
	if (strcmp(str, "Dessert") == 0) return 4;
}

// Converts a number to a category.
const char * intToCategory(int n) {
	if (n == 1) return "Appetizer";
	if (n == 2) return "Main course";
	if (n == 3) return "Drink";
	if (n == 4) return "Dessert";
}

#endif