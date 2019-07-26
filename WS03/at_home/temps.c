// Name:Fabio Bernal
// Student Number: 036422103
// Email:febernal@myseneca.ca
// Section:JJ
// Workshop:03




#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUMS 4

int main(void) {



	int highVal, lowVal, i;
	int high = -42, low = 42, hday = -1, lday = -1;
	float highTmp = 0, lowTmp = 0, avg;



	printf("---=== IPC Temperature Analyzer ===---\n");


	for (i = 0; i < NUMS; i++) {
		printf("Enter the high value for day %d: ", i + 1);
		scanf(" %d", &highVal);
		printf("\n");

		printf("Enter the low value for day %d: ", i + 1);
		scanf("%d", &lowVal);
		printf("\n");

		while (highVal > 40 || lowVal < -40 || highVal < lowVal) {
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");
			printf("Enter the high value for day %d: ", i + 1);
			scanf(" %d", &highVal);
			printf("\n");

			printf("Enter the low value for day %d: ", i + 1);
			scanf("%d", &lowVal);
			printf("\n");

		}
		highTmp = highTmp + highVal;
		lowTmp = lowTmp + lowVal;

		if (highVal > high)
		{
			high = highVal;
			hday = i + 1;
		}
		if (lowVal < low) {

			low = lowVal;
			lday = i + 1;
		}
	}
	avg = (highTmp + lowTmp) /2;


	printf("The average (mean) temperature was: %.2f\n", avg);
	printf("The highest temperature was %d, on day %d\n", high, hday);
	printf("The lowest temperature was %d, on day %d\n", low, lday);

	return 0;
}
