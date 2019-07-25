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

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+

#include "contactHelpers.h"
#include "contacts.h"


// +---------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2   |
// |        function definitions below...              |
// |                                                   |
// | *** See hint regarding the getNumbers function    |
// +---------------------------------------------------+


// getName:
void getName(struct Name *name)
{
	char option;

	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", name->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	option = yes();
	if (option == 1)
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6s", name->middleInitial);
		clearKeyboard();
	}
	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", name->lastName);
	clearKeyboard();
}



// getAddress:
void getAddress(struct Address *address)
{
	char option;

	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", address->street);
	clearKeyboard();
	printf("Do you want to enter an apartment number? (y or n): ");
	option = yes();
	if (option == 1) {
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
		clearKeyboard();
	}
	else {
		address->apartmentNumber = 0;
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address->postalCode);
	clearKeyboard();
	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", address->city);
	clearKeyboard();
}




// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable
void getNumbers(struct Numbers *numbers)
{
	char option;

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	option = yes();
	if (option == 1)
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
		
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	option = yes();
	if (option == 1)
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone (numbers->business);
		
	}
}




// getContact
void getContact(struct Contact *contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}
