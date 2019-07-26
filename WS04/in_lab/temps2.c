//--------------------------------------------------
// Name: Fabio Bernal      
// Student Number: 036422103 
// Email: febernal@myseneca.ca         
// Section: JJ     
// Workshop:04  
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int day;
	int i;
	int Days[] = { 1,2,3,4,5,6,7,8,9,10 };
	int high[10];
	int low[10];
	

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &day);
	printf("\n");

	while (day < 3 || day > 10)
	{
		printf("\n");
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &day);
		printf("\n");
	}
	
	for (i = 0; i < day; i++)
	{
		printf("Day %d - High: ", Days[i]);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", Days[i]);
		scanf("%d", &low[i]);
	}
	
	printf("\nDay  Hi  Low\n");
	
	for(i=0; i<day; i++)
		printf("%d    %d    %d\n", Days[i], high[i], low[i]);
	

	int highestVal = high[0];
	int lowVal = low[0];

	for (i = 1; i < day; i++)
		printf("The highest temperature was %d, on Day %d", high[i], day);

	return 0;
}


