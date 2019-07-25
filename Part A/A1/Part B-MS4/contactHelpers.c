///* -------------------------------------------
//Name:Fabio Bernal
//Student number: 036422103
//Email: febernal@myseneca.ca
//Section:JJ
//Date: 2018 / 04/ 02
//----------------------------------------------
//Assignment: 2
//Milestone:  4
//---------------------------------------------- */
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"
#include "contacts.h"

#define MAXCONTACTS 5


// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n');
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
	int value = getInt();

	while (value < min || value > max) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		value = getInt();
	}
	return value;
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
	return option;
}


// ContactManagerSystem:
void ContactManagerSystem(void) {
	int flag = 0;
	int selection;
	struct Contact contact[MAXCONTACTS] =
	{
		{
			{ "Rick",{ '\0' }, "Grimes" },
			{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
			{ "4161112222", "4162223333", "4163334444" }
		},
		{
			{ "Maggie", "R.", "Greene" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9051112222", "9052223333", "9053334444" }
		},
		{
			{ "Morgan", "A.", "Jones" },
			{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
			{ "7051112222", "7052223333", "7053334444" }
		},
		{
			{ "Sasha",{ '\0' }, "Williams" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9052223333", "9052223333", "9054445555" }
		}
	};

	do {
		selection = menu();
		printf("\n");
		switch (selection)
		{
		case 1:

			displayContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:

			addContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 3:

			updateContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:

			deleteContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 5:

			searchContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 6:

			sortContacts(contact, MAXCONTACTS);
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

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10[0123456789]s", telNum);
		clearKeyboard();

		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}


// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i;
	int flag = 0;
	int value = -1;

	for (i = 0; i < size && flag == 0; i++) {
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
		{
			value = i;
			flag = 1;
		}
	}
	return value;
}

// displayContactHeader
void displayContactHeader(void) {

	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");

}


// displayContactFooter
void displayContactFooter(int value) {

	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", value);

}

// displayContact:
void displayContact(const struct Contact *contact) {

	// Name
	if (strcmp(contact->name.middleInitial, "") == 0)
		printf(" %s %s\n",
			contact->name.firstName,
			contact->name.lastName);

	else
		printf(" %s %s %s\n",
			contact->name.firstName,
			contact->name.middleInitial,
			contact->name.lastName);

	//numbers 
	printf("    C: %-10s   H: %-10s   B: %-10s\n",
			contact->numbers.cell,
			contact->numbers.home,
			contact->numbers.business);

	//address 
	if (contact->address.apartmentNumber == 0)
		printf("       %d %s, %s, %s\n",
			contact->address.streetNumber,
			contact->address.street,
			contact->address.city,
			contact->address.postalCode);
	else
		printf("       %d %s, Apt# %d, %s, %s\n",
			contact->address.streetNumber,
			contact->address.street,
			contact->address.apartmentNumber,
			contact->address.city,
			contact->address.postalCode);
}


// displayContacts:
void displayContacts(const struct Contact contact[], int size) {

	int sum = 0, i;

	displayContactHeader();

	for (i = 0; i < size; i++)
	{
		if (strlen(contact[i].numbers.cell) > 0)
		{
			sum += 1;
			displayContact(&contact[i]);
		}
	}
	displayContactFooter(sum);
}

// searchContacts:
void searchContacts(const struct Contact contact[], int  size) {

	char value[11];
	int index;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(value);
	index = findContactIndex(contact, size, value);
	if (index > -1) {
		printf("\n");
		displayContact(&contact[index]);
		printf("\n");
	}
	else
		printf("*** Contact NOT FOUND ***\n");

}


// addContact:
void addContact(struct Contact contact[], int  size) {
	int i, temp = -1;
	int flag = 0;

	for (i = 0; i < size && flag == 0; i++) {
		if (strlen(contact[i].numbers.cell) == 0)
		{
			temp = i;
			flag = 1;
		}
	}
	if (temp > -1) {
		getContact(&contact[temp]);
		printf("--- New contact added! ---\n");
	}
	else
	{
		printf("*** ERROR: The contact list is full! ***\n");
	}

}
	
// updateContact:
void updateContact(struct Contact contact[], int  size) {

	char value[11];
	int temp;
	
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(value);
	temp = findContactIndex(contact, size, value);

	if (temp > -1)
	{
		printf("\nContact found:\n");
		displayContact(&contact[temp]);
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		if (yes() == 1)
			getName(&contact[temp].name);

		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1)
			getAddress(&contact[temp].address);

		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1)
			getNumbers(&contact[temp].numbers);
		printf("--- Contact Updated! ---\n");
	}
	else
		printf("*** Contact NOT FOUND ***\n");


}

// deleteContact:
void deleteContact(struct Contact contact[], int  size) {

	char value[11];
	int temp;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(value);
	temp = findContactIndex(contact, size, value);
	if (temp == -1)
		printf("*** Contact NOT FOUND ***\n");
	else
	{
		printf("\nContact found:\n");
		displayContact(&contact[temp]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		if (yes() == 1)
		{
			contact[temp].numbers.cell[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
	}

}

// sortContacts:
void sortContacts(struct Contact contact[], int  size) {

	int i, j;
	struct Contact temp;

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (strcmp(contact[i].numbers.cell, contact[j].numbers.cell) > 0)
			{
				temp = contact[i];
				contact[i] = contact[j];
				contact[j] = temp;
			}
		}
	}
	printf("--- Contacts sorted! ---\n");
}
