/* -------------------------------------------
Name:Fabio Bernal
Student number: 036422103
Email: febernal@myseneca.ca
Section:JJ
Date:2018 / 03 / 26
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include  "contactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt function definition goes here:
int getInt(void)
{
	char NL = 'x';
	int Value;

	while (NL != '\n')
	{
		scanf(" %d%c", &Value, &NL);
		if (NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	}return Value;
}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
	int Value = getInt();

	while (Value < min || Value > max) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		Value = getInt();
	}
	return Value;

}

// yes function definition goes here:

int yes(void)
{

	char option, NL = 'x';
	int value = 0;

	while (NL != '\n') {
		scanf("%c%c", &option, &NL);
		if (NL != '\n'){
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else {
			if (option == 'Y' || option == 'y') {
				value = 1;
			}
			else if (option == 'N' || option == 'n') {
				value = 0;
			}
			else {
				printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
				NL = 'x';
			}
		}
		

	}
	return value;

}

// menu function definition goes here:
int menu(void)
{
	int option;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");

	option = getIntInRange(0, 6);
	//printf("\n");
	return option;
}


// ContactManagerSystem function definition goes here:
void ContactManagerSystem(void) {
	int flag = 0;
	int selection;

	do {
		selection = menu();
		printf("\n");
		switch (selection)
		{
		case 1:
			printf("<<< Feature 1 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 2:
			printf("<<< Feature 2 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 3:
			printf("<<< Feature 3 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 4:
			printf("<<< Feature 4 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 5:
			printf("<<< Feature 5 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 6:
			printf("<<< Feature 6 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			flag = yes();
			printf("\n");
			break;
		default:
			break;
		}
		
	} while (flag != 1);

	printf("Contact Management System: terminated\n");
}
		


















// Testing Different METHODS

//do {
//	scanf("%c%c", &option, &NL);
//	if (NL != '\n') {
//		clearKeyboard();
//		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
//		}
//		if ((option == 'Y' || option == 'y') && (NL == '\n')) {
//		
//			value = 1;
//		}
//		else if ((option == 'N' || option == 'n') && (NL == '\n')) {
//			
//			value = 0;
//		}
//	//}
//	else {
//		clearKeyboard();
//		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
//	}
//
//} while (NL!='\n');
//return value;