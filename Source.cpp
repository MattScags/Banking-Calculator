/*
Matthew Scaglione
CS 210
07/29/2022
*/

#include <iostream>
#include <iomanip>
#include "BalanceAndInterest.h"

using namespace std;

int main() {
	double investAmount; //variables for investment amount, monthly deposits, annual interest, and number of years.
	double monthlyDeposit;
	double annualInt;
	int numYears;
	char restartProgram;

	while (true) { //Loops until user does not enter 'y' to calculate new amounts
		cout << setfill('*') << setw(36) << "" << endl; //The following prints instructions, collecting the above variables from user input.
		cout << setfill('*') << setw(12) << "" << " Data Input " << setfill('*') << setw(12) << "" << endl;
		cout << "Initial Investment Amount: $";
		cin >> investAmount;
		cout << "Monthly Deposit: $";
		cin >> monthlyDeposit;
		cout << "Annual Interest (%): ";
		cin >> annualInt;
		cout << "Number of years: ";
		cin >> numYears;
		cout << endl;

		WithoutDeposit(investAmount, annualInt, numYears); //Generates the WithoutDeposit function which prints a report without additional monthly deposits per the requirements.

		MySavings myReport = MySavings(investAmount, monthlyDeposit, annualInt, numYears); // Creates a MySavings class called myReport

		myReport.reportWithDeposits(); // Calls the reportWithDeposits method


		cout << endl << endl << "Do you want to enter new amounts? (y/n): "; //If user does not type 'y', program terminates
			cin >> restartProgram;
			cout << endl;
			if (restartProgram != 'y')
				break;
	}
	cout << "Program terminated";
}