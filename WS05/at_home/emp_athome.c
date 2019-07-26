/*
Name: Fabio Bernal
Student number: 036422103
Email: febernal@myseneca.ca
Workshop:05
Section:JJ
Date: 3-10-2018
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 4


struct Employee {
	int id;
	int age;
	double salary;
};

int main(void) {
	struct Employee emp[SIZE] = { { 0 } };
	
	int option = 0;
	int i = 0;
	int validEmp = 0;
	int newID;
	int flag;
	

	printf("---=== EMPLOYEE DATA ===---\n\n");


	do {

		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
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
				if (emp[i].id > 0)
				{
					printf("%6d%9d%11.2lf", emp[i].id, emp[i].age, emp[i].salary);
					printf("\n");
				}
			}
			printf("\n");
			break;
		case 2:
			printf("Adding Employee\n");
			printf("===============\n");
			if (validEmp < SIZE)
			{
				flag = 0;
				for (i = 0; i < SIZE && flag == 0; i++) 
				{
					if (emp[i].id == 0)
					{ 
				
				printf("Enter Employee ID: ");
				scanf("%d", &emp[i].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[i].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[i].salary);
				validEmp++;
				flag = 1;
				//printf("\n");
					}
				}
			}
			else
				printf("ERROR!!! Maximum Number of Employees Reached\n");
			printf("\n");
			break;

		case 3: 
			newID = 0;
			flag = 0;
			
			printf("Update Employee Salary\n");
			printf("======================\n");
			
			do
			{
				printf("Enter Employee ID: ");
				scanf("%d", &newID);
		
				for (i = 0; i < SIZE && flag == 0; i++)
				{
					if (newID ==emp[i].id)
					{
						printf("The current salary is %.2lf\n", emp[i].salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &emp[i].salary);
						printf("\n");
						flag = 1;
					}
				}
				
			} while (flag == 0);
				break;
		case 4:																//safe empty state 
			
			newID = 0;
			flag = 0;

			printf("Remove Employee\n");
			printf("===============\n");
				do
			{
				printf("Enter Employee ID: ");
				scanf("%d", &newID);
				for (i = 0; i < SIZE && flag == 0; i++)
				{
					if (newID == emp[i].id)
					{
						printf("Employee %d will be removed\n\n", emp[i].id);
						emp[i].id = 0; 
						validEmp--;
						flag = 1;
					}
				}
			} while (flag == 0);
				break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);


	return 0;
}



