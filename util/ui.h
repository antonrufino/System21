//////////////////////////////////////////////////////////////////////////
// ui.h                                                                 //
// Functions for handling tasks common to all parts of the application. //
//////////////////////////////////////////////////////////////////////////

#ifndef UI
#define UI

#include <stdio.h>
#include <stdlib.h>

void cls() {system("clear");}
void header() {
	printf(" ____            _                   ____  _ \n");
	printf("/ ___| _   _ ___| |_ ___ _ __ ___   |___ \\/ |\n");
	printf("\\___ \\| | | / __| __/ _ \\ '_ ` _ \\    __) | |\n");
	printf(" ___) | |_| \\__ \\ ||  __/ | | | | |  / __/| |\n");
	printf("|____/ \\__, |___/\\__\\___|_| |_| |_| |_____|_|\n");
	printf("       |___/                                 \n");
	printf("\n");
}

#endif