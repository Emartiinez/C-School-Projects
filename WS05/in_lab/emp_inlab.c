/*
Name: Fabio Bernal
Student number: 036422103
Email: febernal@myseneca.ca
Workshop:05 
Section:JJ
Date: 3-05-2018
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define SIZE 2

		
struct Employee {
	int id; 
	int age;
	double salary; 
};


int main(void) {

	int option = 0;
	int i = 0;
	int validEmp = 0;
	
	printf("---=== EMPLOYEE DATA ===---\n\n");

	struct Employee emp[SIZE]={ {0,0,0.0} };

	do {
		
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d",&option);
		printf("\n");
		
		switch (option) {
		case 0:	
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;
		case 1:	 
			
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			
			for (i = 0; i < SIZE; i++)
			{
				printf("%6d%9d%11.2lf", emp[i].id, emp[i].age, emp[i].salary);
				printf("\n");
			}
			printf("\n");
				break;
		case 2:	

			printf("Adding Employee\n");
			printf("===============\n");

		
			if (validEmp < SIZE)
			{
				
	
					printf("Enter Employee ID: ");
					scanf("%d", &emp[validEmp].id);
					printf("Enter Employee Age: ");
					scanf("%d", &emp[validEmp].age);
					printf("Enter Employee Salary: ");
					scanf("%lf", &emp[validEmp].salary);
					validEmp++;
					
					
				
			}
				else 
					printf("ERROR!!! Maximum Number of Employees Reached\n");
			printf("\n");
			
			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);


	return 0; 
}

