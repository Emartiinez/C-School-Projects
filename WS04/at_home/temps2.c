//--------------------------------------------------
// Name: Fabio Bernal      
// Student Number: 036422103 
// Email: febernal@myseneca.ca         
// Section: JJ     
// Workshop:04  
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN 3
#define MAX 10

int main(void)
{

	int day;
	int i;
	int high[10];
	int low[10];
	int Hsum = 0, Lsum = 0;
	float avg = 0;
	int done = 0;


	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &day);
	printf("\n");

	while (day < MIN || day > MAX)
	{
		printf("\n");
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &day);
		printf("\n");
	}

	for (i = 0; i < day; i++)
	{
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);
	}

	printf("\nDay  Hi  Low\n");

	for (i = 0; i<day; i++)
		printf("%d    %d    %d\n", i + 1, high[i], low[i]);


	int highestVal = high[0];
	int lowestVal = low[0];
	int Hday = 1, Lday = 1;
	int newVal = 0;


	for (i = 0; i < day; i++)
	{
		if (high[i] > highestVal)
		{
			highestVal = high[i];
			Hday = i + 1;
		}

		if (low[i] < lowestVal)
		{
			lowestVal = low[i];
			Lday = i + 1;
		}
	}
	printf("\n");
	printf("The highest temperature was %d, on day %d\n", highestVal, Hday);
	printf("The lowest temperature was %d, on day %d\n", lowestVal, Lday);
	printf("\n");

	do {

		printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", day);
		scanf("%d", &newVal);


		if (newVal == -1)
		{
			done = 1;
		}
		else {

			while (newVal < 1 || newVal > 4)
			{
				printf("\n");
				printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", day);
				scanf("%d", &newVal);
			}


			for (i = 0; i < newVal; i++)
			{
				Hsum = Hsum + high[i];
				Lsum = Lsum + low[i];
			}
			avg = (Hsum + Lsum) / ((float)newVal * 2);
			printf("\n");
			printf("The average temperature up to day %d is: %.2f\n", newVal, avg);
			printf("\n");

			Hsum = 0, Lsum = 0;
		}
	} while (done == 0);


	printf("\n");
	printf("Goodbye!\n");
	return 0;
}