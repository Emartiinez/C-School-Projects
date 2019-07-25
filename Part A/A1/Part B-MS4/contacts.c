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
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include "contactHelpers.h"
//#include "contacts.h"
//
//
//// getName:
//void getName(struct Name *name)
//{
//	
//	printf("Please enter the contact's first name: ");
//	scanf(" %30[^\n]", name->firstName);
//	clearKeyboard();
//
//	printf("Do you want to enter a middle initial(s)? (y or n): ");
//	if (yes() == 1)
//	{
//		printf("Please enter the contact's middle initial(s): ");
//		scanf(" %6s", name->middleInitial);
//		clearKeyboard();
//	}
//	printf("Please enter the contact's last name: ");
//	scanf(" %35[^\n]", name->lastName);
//	clearKeyboard();
//}
//
//// getAddress:
//void getAddress(struct Address *address)
//{
//	char option;
//
//	printf("Please enter the contact's street number: ");
//	address->streetNumber = getInt();
//	printf("Please enter the contact's street name: ");
//	scanf(" %40[^\n]", address->street);
//	clearKeyboard();
//	printf("Do you want to enter an apartment number? (y or n): ");
//	option = yes();
//	if (option == 1) {
//		printf("Please enter the contact's apartment number: ");
//		address->apartmentNumber = getInt();
//		
//	}
//	else {
//		address->apartmentNumber = 0;
//	}
//	printf("Please enter the contact's postal code: ");
//	scanf(" %7[^\n]", address->postalCode);
//	clearKeyboard();
//	printf("Please enter the contact's city: ");
//	scanf(" %40[^\n]", address->city);
//	clearKeyboard();
//}
//// getNumbers:
//void getNumbers(struct Numbers *numbers)
//{
//	
//	printf("Please enter the contact's cell phone number: ");
//	getTenDigitPhone(numbers->cell);
//
//	printf("Do you want to enter a home phone number? (y or n): ");
//	if (yes()==1)
//	{
//		printf("Please enter the contact's home phone number: ");
//		getTenDigitPhone(numbers->home);
//	}
//	else 
//	{
//		numbers->home[0] = '\0';
//	}
//	printf("Do you want to enter a business phone number? (y or n): ");
//	if (yes() == 1)
//	{
//		printf("Please enter the contact's business phone number: ");
//		getTenDigitPhone(numbers->business);
//	}
//	else
//	{
//		numbers->business[0] = '\0';
//	}
//}
//
//// getContact:
//void getContact(struct Contact *contact)
//{
//	getName(&contact->name);
//	getAddress(&contact->address);
//	getNumbers(&contact->numbers);
//}







#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	int array1[20];
	int array2[30];
	int i, t, j;
	int check, Input;
	printf("Before Stuffing:");
	scanf("%d", &Input);
	printf("Enter the frame in the form of 0 and 1 :");
	for (i = 0; i<Input; i++)
		scanf("%d", &array1[i]);

	check = 1;
	t = 0;
	while (i = 0 <Input)
	{
		if (array1[i] == 1)
		{
			array2[t] = array1[i];
			for (j = i + 1; array1[j] == 1 && j<Input && check<5; j++)
			{
				t++;
				array2[t] = array1[j];
				check++;
				if (check == 5)
				{
					t++;
					array2[t] = 0;
				}
				i = j;
			}
		}
		else
		{
			array2[t] = array1[i];
		}
		i++;
		t++;
	}
	printf("After Stuffing :");
	for (i = 0; i<t; i++)
		printf("%d", array2[i]);
	getch();
}