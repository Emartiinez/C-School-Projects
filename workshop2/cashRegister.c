/*
Name:      <Fabio Bernal>
Student#:  <036422103>
Section:   <IPC JJ>
*/

#include <stdio.h>	
#define  _CRT_SECURE_NO_WARNINGS

int main(void) {
	// These are the only variables you need to do this workshop:
	double amount, gst;
	int intBalance, loonies, quarters, dimes, nickels, pennies;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);

	gst = amount * .13; // Don’t add 0.005 yet, the next printf statement will automatically round (display only)
	printf("GST: %.2lf\n", gst); // will automatically round (display only)

	amount += gst + 0.005;  // Now add half a cent to ensure rounding occurs before it is truncated (when converted to an integer)
	intBalance = (int)(amount * 100); // convert to cents (will truncate)
	printf("Balance owing: $%.2lf\n", (double)intBalance / 100);

	// Loonies:
	loonies = intBalance / 100;    // divide by 100 cents ($1.00 = 100 cents)
	intBalance = intBalance % 100; // total cents remaining
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, (double)intBalance / 100);
	//quaters//
	quarters = intBalance / 25;
	intBalance = intBalance % 25;
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, (double)intBalance / 100);
	//Dime//
	dimes = intBalance / 10;
	intBalance = intBalance % 10;
	printf("Dimes required: %d, balance owing $%.2lf\n", dimes, (double)intBalance / 100);
	//nickels//
	nickels = intBalance / 5;
	intBalance = intBalance % 5;
	printf("Nickels required: %d, balance owing $%.2lf\n", nickels, (double)intBalance / 100);
	//pennies//
	pennies = intBalance / 1;
	intBalance = intBalance % 1;
	printf("Pennies required: %d, balance owing $%.2lf\n", pennies, (double)intBalance / 100);

	return 0;
}
// Thank you so much for the tip sir// 

