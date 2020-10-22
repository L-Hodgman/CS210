/*
 * Investments.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: Elizabeth Hodgman
 */
#include <iomanip>
#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Amounts.h"

// Method to display menu at start of program
void displayMenu(){
	cout << "*******************************" << endl;
	cout << "**********Data Input***********" << endl;
	cout << "Initial Investment Amount:" << endl;
	cout << "Monthly Deposit:" << endl;
	cout << "Annual Interest:" << endl;
	cout << "Number of years:" << endl;
	cout << "Press Enter to continue..." << endl;
}

// Method to display edit menu
void editMenu(){
	cout << "*******************************************" << endl;
	cout << "****************Edit Input*****************" << endl;
	cout << "Press '1' to edit initial investment amount" << endl;
	cout << "Press '2' to edit monthly deposit amount" << endl;
	cout << "Press '3' to edit annual interest rate" << endl;
	cout << "Press '4' to edit number of years" << endl;
	cout << "Press '0' to exit edit" << endl;
}

int main(){
	double initialAmount;
	double monthlyDeposit;
	double annualInterest;
	double interestAmount;
	double yearTotalInterest;
	double accountTotal;
	int numYears;

	// Object
	Amounts userAmounts;

	// Displays menu at start of program
	displayMenu();

	// If user hits enter key - starts program
	if(getchar()){
		// Asks user to input initial investment amount
		// While loop takes input and checks if input is a positive number - not a negative number & not a letter
		system("CLS"); // Screen clear
		cout << "Please enter initial investment amount" << endl;
		while((!(cin >> initialAmount)) || (initialAmount < 0.0)){
			system("CLS");
			cout << "Error: Please enter positive numbers only for initial investment amount" << endl;
			cout << "Please enter initial investment amount" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			// Breaks loop if initial amount is over 0.0
			if(initialAmount > 0.0){
				break;
			}
		}
		// Sets input amount to SetInitialAmount
		userAmounts.SetInitialAmount(initialAmount);

		// Asks user to input monthly deposit amount
		// While loop takes input and checks if input is a positive number - not a negative number & not a letter
		system("CLS"); // Screen clear
		cout << "Please enter the amount you plan to deposit each month" << endl;
		while((!(cin >> monthlyDeposit)) || (monthlyDeposit < 0.0)){
			system("CLS");
			cout << "Error: Please enter positive numbers only for monthly deposit amount" << endl;
			cout << "Please enter the amount you plan to deposit each month" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			// Breaks loop in monthly deposit amount is over 0.0
			if(monthlyDeposit > 0.0){
				break;
			}
		}
		// Sets input amount to SetMonthlyAmount
		userAmounts.SetMonthlyAmount(monthlyDeposit);

		// Asks user to input annual interest rate
		// While loop takes input and checks if input is a positive number - not a negative number & not a letter
		system("CLS"); // Screen clear
		cout << "Please enter the annual interest rate" << endl;
		while((!(cin >> annualInterest)) || (annualInterest < 0.0)){
			system("CLS");
			cout << "Error: Please enter positive numbers only for annual interest rate" << endl;
			cout << "Please enter the annual interest rate" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			// Breaks loop if annual interest rate is over 0.0
			if(annualInterest > 0.0){
			break;
			}
		}
		// Sets input amount to SetInterestAmount
		userAmounts.SetInterestAmount(annualInterest);

		// Asks user to input number of years investment will grow
		// While loop takes input and checks if input is a positive number - not a negative number & not a letter
		system("CLS"); // Clear screen
		cout << "Please enter the number of years the investment will grow" << endl;
		while((!(cin >> numYears)) || (numYears < 0.0)){
			system("CLS");
			cout << "Error: Please enter positive numbers only for amount of years" << endl;
			cout << "Please enter the number of years the investment will grow" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			// Breaks loop if number of years is over 0
			if(numYears > 0){
				break;
			}
		}
		// Sets input amount to SetYearsAmount
		userAmounts.SetYearsAmount(numYears);
		system("CLS"); // Clears screen of all previous outputs

		while(true){
			cout << "*******************************" << endl;
			cout << "**********Data Input***********" << endl;
			// Outputs initial investment amount as $0.00
			cout << "Initial Investment Amount: $" << fixed << setprecision(2) << userAmounts.GetInitialAmount() << endl;
			// Outputs monthly deposit amount as $0.00
			cout << "Monthly Deposit: $" << fixed << setprecision(2) << userAmounts.GetMonthlyAmount() << endl;
			// Outputs annual interest amount as %0.0
			cout << "Annual Interest: %" << fixed << setprecision(1) << userAmounts.GetInterestAmount() << endl;
			// Outputs number of years as 0
			cout << "Number of years: " << userAmounts.GetYearsAmount() << endl << endl;
			// Asks user if amounts are correct
			// If Y then will continue to calculations
			// If N then will let user edit amounts
			cout << "If amounts are correct press 'Y' to continue" << endl;
			cout << "To edit an amount press 'N'" << endl;
			cin.ignore();
			char userKey;
			cin >> userKey;

			// While loop if user does not enter Y or N
			while((userKey != 'n') && (userKey != 'N') && (userKey != 'y') && (userKey != 'Y')){
				system("CLS"); // Refreshes screen to show amounts and invalid input error
				cout << "*******************************" << endl;
				cout << "**********Data Input***********" << endl;
				cout << "Initial Investment Amount: $" << fixed << setprecision(2) << userAmounts.GetInitialAmount() << endl;
				cout << "Monthly Deposit: $" << fixed << setprecision(2) << userAmounts.GetMonthlyAmount() << endl;
				cout << "Annual Interest: %" << fixed << setprecision(1) << userAmounts.GetInterestAmount() << endl;
				cout << "Number of years: " << userAmounts.GetYearsAmount() << endl << endl;
				cout << "Error: Invalid input" << endl;
				cout << "If amounts are correct press 'Y' to continue" << endl;
				cout << "To edit an amount press 'N'" << endl;
				cin.ignore();
				cin >> userKey;
			}

			// If user enters 'N' or 'n' starts edit process
			if((userKey == 'n') || (userKey == 'N')){
				system("CLS"); // Refresh screen
				// User edit choices - display edit menu
				editMenu();

				char userChoice;
				cin >> userChoice;
				// Switch loop for userChoice
				switch(userChoice){
					// Input 1 - edits initial investment amount
					case '1':
						system("CLS");
						cout << "Enter new initial investment amount" << endl;
						// While loop takes input and makes sure it is a positive number
						while((!(cin >> initialAmount)) || (initialAmount < 0.0)){
							system("CLS");
							cout << "Error: Please enter positive numbers only for initial investment amount" << endl;
							cout << "Enter new initial investment amount" << endl;
							cin.clear();
							cin.ignore(100, '\n');
							if(initialAmount > 0.0){
								break;
							}
						}
						// Sets new amount
						userAmounts.SetInitialAmount(initialAmount);
						break;

					// Input 2 - edits monthly deposit amount
					case '2':
						system("CLS");
						cout << "Enter new monthly deposit amount" << endl;
						// While loop takes input and makes sure it is a positive number
						while((!(cin >> monthlyDeposit)) || (monthlyDeposit < 0.0)){
							system("CLS");
							cout << "Error: Please enter positive numbers only for monthly deposit amount" << endl;
							cout << "Enter new monthly deposit amount" << endl;
							cin.clear();
							cin.ignore(100, '\n');
							if(monthlyDeposit > 0.0){
								break;
							}
						}
						// Sets new amount
						userAmounts.SetMonthlyAmount(monthlyDeposit);
						break;

					// Input 3 - edits annual interest rate amount
					case '3':
						system("CLS");
						cout << "Enter new annual interest rate" << endl;
						// While loop takes input and makes sure it is a positive number
						while((!(cin >> annualInterest)) || (annualInterest < 0.0)){
							system("CLS");
							cout << "Error: Please enter positive numbers only for annual interest rate" << endl;
							cout << "Enter new annual interest rate" << endl;
							cin.clear();
							cin.ignore(100, '\n');
							if(annualInterest > 0.0){
								break;
							}
						}
						// Sets new amount
						userAmounts.SetInterestAmount(annualInterest);
						break;

					// Input 4 - edits amount of years
					case '4':
						system("CLS");
						cout << "Enter new amount of years" << endl;
						// While loop takes input and makes sure it is a positive number
						while((!(cin >> numYears)) || (numYears < 0.0)){
							system("CLS");
							cout << "Error: Please enter positive numbers only for amount of years" << endl;
							cout << "Enter new amount of years" << endl;
							cin.clear();
							cin.ignore(100, '\n');
							if(numYears > 0){
								break;
							}
						}
						// Sets new amount
						userAmounts.SetYearsAmount(numYears);
						break;
						// Input 0 - brings user back to amounts
					case '0':
						system("CLS"); // Clear screen
						continue;
					default:
						// If user presses anything other than 1,2,3,4,0 - Will bring user back to amounts
						system("CLS"); // Clears screen of all previous outputs
						cout << "Invalid input to edit - Please press 'N' to try again" << endl;
						break;
				}
			}
			// If user presses 'y' or 'Y' - continues program to calculations
			else if((userKey == 'y') || (userKey == 'Y')){
				system("CLS");
				// Sets beginning accountTotal to initial investment amount
				accountTotal = initialAmount;

				// Data without monthly deposits
				cout << "     Balance and Interest Without Additional Monthly Deposits    " << endl;
				cout << "=================================================================" << endl;
				cout << "       Year       Year End Balance       Year End Earned Interest" << endl;
				cout << "-----------------------------------------------------------------" << endl;

				for (int i = 0; i < numYears; i++){
					// Calculation without monthly deposits
					interestAmount = accountTotal * ((annualInterest/100));
					accountTotal = accountTotal + interestAmount;

					// Aligns output into rows and columns evenly
					cout << "\t" << left << setw(14) << (i + 1); // i = the year
					cout << "$" << left << setw(18) << fixed << setprecision(2) << accountTotal;
					cout << right << setw(8) << "$" << fixed << setprecision(2) << interestAmount << endl;
				}
				cout << endl;
				// Reset beginning accountTotal to initial investment amount
				accountTotal = initialAmount;

				// Data with monthly deposits
				cout << "       Balance and Interest With Additional Monthly Deposits     " << endl;
				cout << "=================================================================" << endl;
				cout << "       Year       Year End Balance       Year End Earned Interest" << endl;
				cout << "-----------------------------------------------------------------" << endl;

				for (int i = 0; i < numYears; i++){
					yearTotalInterest = 0;
					for(int j = 0; j < 12; j++){
						// Calculation with monthly deposits
						interestAmount = (accountTotal + monthlyDeposit) * ((annualInterest/100)/12);
						accountTotal = accountTotal + monthlyDeposit + interestAmount;
						yearTotalInterest = yearTotalInterest + interestAmount;
					}
				    	// Aligns output into rows and columns evenly
						cout << "\t" << left << setw(14) << (i + 1); // i = the year
						cout << "$" << left << setw(18) << fixed << setprecision(2) << accountTotal;
						cout << right << setw(8) << "$" << fixed << setprecision(2) << yearTotalInterest << endl;
				}
				// Asks user if they want to try again
				cout << "Do you want to try again?" << endl;
				cout << "Enter: 'Y' for yes - 'N' for no" << endl;
				cin.ignore();
				cin >> userKey;
				// If user does not press N or Y - will loop until the right input
				while((userKey != 'n') && (userKey != 'N') && (userKey != 'y') && (userKey != 'Y')){
					system("CLS");
					cout << "Error: Invalid input" << endl;
					cout << "Do you want to try again?" << endl;
					cout << "Enter: 'Y' for yes - 'N' for no" << endl;
					cin.ignore();
					cin >> userKey;
				}
				// If user presses 'y' or 'Y' - will go back to amounts and can edit
				if((userKey == 'y') || (userKey == 'Y')){
					system("CLS"); // Clears screen
					continue;
				}
				// If user press 'n' or 'N' - exits program
				else if((userKey == 'n') || (userKey == 'N')){
					system("CLS"); // Clears screen
					cout << "Goodbye";
					exit(1);
				}
			}
		}
	}
	return 0;
}



