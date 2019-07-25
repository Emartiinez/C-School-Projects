/* -------------------------------------------
Name:fabio bernal
Student number: 036422103
Email:febernal@myseneca.ca
Section: JJ
Date: 2018 / 03 / 19
----------------------------------------------
Assignment: 1
Milestone:  4
------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "contacts.h"


int main(void){

struct Contacts contact = { '\0' };
struct Name *PtrName = &contact.name;
struct Address *PtrAddress = &contact.address;
struct Numbers *PtrNumber = &contact.numbers;
char option;

  
    // Display the title
printf("Contact Management System\n");
printf("-------------------------\n");


getName(PtrName);
getAddress(PtrAddress);
getNumber(PtrNumber);



// Display Contact summary details
printf("\n");
printf("Contact Details\n");
printf("---------------\n");
printf("Name Details\n");
printf("First name: %s\n", PtrName->firstName);
printf("Middle initial(s): %s", PtrName->middleInitial);
printf("\n");
printf("Last name: %s\n\n", PtrName->lastName);

//address details
printf("Address Details\n");
printf("Street number: %d\n", PtrAddress->streetNumber);
printf("Street name: %s\n", PtrAddress->street);
printf("Apartment: ");
if (PtrAddress->apartmentNumber > 0)
{
	printf("%d", PtrAddress->apartmentNumber);
}
printf("\n");
printf("Postal code: %s\n", PtrAddress->postalCode);
printf("City: %s\n\n", PtrAddress->city);

//phone numbers
printf("Phone Numbers:\n");
printf("Cell phone number: %s\n", PtrNumber->cell);
printf("Home phone number: %s\n", PtrNumber->home);
printf("Business phone number: %s\n\n", PtrNumber->business);

printf("Structure test for Contact using functions done!\n");
    
    return 0;
}

/*  SAMPLE OUTPUT:

Contact Management System
-------------------------
Please enter the contact's first name: Wilma
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Dino
Please enter the contact's last name: Flintstone
Please enter the contact's street number: 100
Please enter the contact's street name: Bedrock
Do you want to enter an apartment number? (y or n): y
Please enter the contact's apartment number: 14
Please enter the contact's postal code: Z8Z 7R7
Please enter the contact's city: Markham
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 647-505-5555
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 905-222-3333
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-491-5050

Contact Details
---------------
Name Details
First name: Wilma
Middle initial(s): Dino
Last name: Flintstone

Address Details
Street number: 100
Street name: Bedrock
Apartment: 14
Postal code: Z8Z 7R7
City: Markham

Phone Numbers:
Cell phone number: 647-505-5555
Home phone number: 905-222-3333
Business phone number: 416-491-5050

Structure test for Contact using functions done!
*/