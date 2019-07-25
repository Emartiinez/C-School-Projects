/* -------------------------------------------
Name:fabio bernal
Student number: 036422103
Email:febernal@myseneca.ca
Section: JJ
Date: 2018 / 03 / 19
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

 

struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};
struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

struct Numbers {
	char cell[21];
	char home[21];
	char business[21];
};


struct Contacts {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// ====== Milestone 4 =======
void getName(struct Name *name);

void getAddress(struct Address *address);

void getNumber(struct Numbers *numbers);

// Get and store from standard input the values for Name
// Place your code here...


// Get and store from standard input the values for Address
// Place your code here...


// Get and store from standard input the values for Numbers
// Place your code here...

