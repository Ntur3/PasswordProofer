//Nolan Turin
//11/19/20
//This program will ask the user to enter the password that meets
//the criteria given below. If it does not the program will
//tell the user there is a error in the criteria. 

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
	const int LENGTH = 50;
	char userPass[LENGTH];
	int upperCase, lowerCase, number, specialChar;

	// Display statement telling user to enter password with criteria
	cout<< "Please enter a password that meets the following criteria: " << endl << endl;
	cout << "Must be at least twelve characters long." << endl;
	cout << "Must contain at least one upperCasecase." << endl;
	cout << "Must contain at least one lowercase letter." << endl;
	cout << "Must contain at least one digit."<< endl;
	cout << "Cannot contain any characters other than: '$', '_', '#', and '!'." << endl << endl;
		 
	do
	{		
		upperCase = 0;
		lowerCase = 0;
		number = 0;
		specialChar = 0;
		
		cout << "Enter user password: ";
		cin.getline(userPass, LENGTH);

		for (int i = 0; i < strlen(userPass); i++)
		{
			if (isupper(userPass[i]))
				upperCase++;
			if (islower(userPass[i]))
				lowerCase++;
			if(isdigit(userPass[i]))
				number++;
			if(ispunct(userPass[i]))
				{
					if((userPass[i]) == '_' || userPass[i] == '$' || userPass[i] == '!' ||
						userPass[i] == '#')
						specialChar = 2;
					else
						specialChar = 1;
				}
		}
	
		if (strlen(userPass) < 12)
			cout << "User Password does not contain at least twelve characters long." << endl;
		if (upperCase == 0)
			cout << "User Password does not contain at least one upperCasecase letter." << endl;
		if (lowerCase == 0)
			cout << "User Password does not contain at least one lowercase letter." << endl;
		if (number == 0)
			cout << "User Password does not have at least one digit." << endl;	
		if (specialChar == 1)
			cout << "User Password has an invalid special character." << endl;		
	}
	while (upperCase == 0 || lowerCase == 0 || number == 0 || specialChar == 1 || strlen(userPass) < 12);

	cout << "User Password Accepted. Your password is: " << userPass << endl;

	return 0;
}
