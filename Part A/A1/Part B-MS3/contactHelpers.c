/* -------------------------------------------
Name:Fabio Bernal
Student number: 036422103
Email: febernal@myseneca.ca
Section:JJ
Date: 2018 / 04/ 02
----------------------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>


// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}


// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
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


// getIntInRange:
int getIntInRange(int min, int max)
{
	int Value = getInt();

	while (Value < min || Value > max) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		Value = getInt();
	}
	return Value;

}

// yes:

int yes(void)
{

	char option, NL = 'x';
	int value = 0;

	while (NL != '\n') {
		scanf("%c%c", &option, &NL);
		if (NL != '\n') {
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


// menu:
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


// ContactManagerSystem:
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


// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10 chars entered)
void getTenDigitPhone(char telNum[])
{
    int needInput = 1;

    while (needInput == 1) {
        scanf("%10s", telNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(telNum) == 10)
            needInput = 0;
        else
            printf("Enter a 10-digit phone number: ");
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    return -1;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void) {




}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int value) {




}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact *contact) {




}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contact[], int size) {



}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contact[], int  size){


}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contact[], int  size) {


}



// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contact[], int  size) {



}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contact[], int  size) {


}



// sortContacts:
// Put empty function definition below: 
void sortContacts(struct Contact contact[], int  size) {


}
