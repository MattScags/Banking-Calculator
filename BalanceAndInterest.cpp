#include "BalanceAndInterest.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


MySavings::MySavings(double depositAmount, double deposits, double interest, int years) { //constructor
	this->m_originalDeposit = depositAmount;
	this->m_monthlyDeposit = deposits;
	this->m_interestRate = interest;
	this->m_numYears = years;
}
void MySavings::reportWithDeposits() { //method to generate report with monthly deposits
	int i; //i and j variable to be used in below For loops
	int j;
	double interestEarned;//Variables used to calculate compounded interest
	double interestPercent;
	double balance = m_originalDeposit;
	double balance1 = m_originalDeposit;
	
	interestPercent = m_interestRate / 100; //Turns interest rate into decimal

	cout << "    " << "Balance and Interest With Additional Monthly Deposits" << "    " << endl; //These cout statements format a report header
	cout << setfill('=') << setw(64) << "" << endl;
	cout << "  Year        ";
	cout << "Year End Balance         ";
	cout << "Year End Earned Interest" << endl;
	cout << setfill('=') << setw(64) << "" << endl;
	cout << setfill(' ');

	for (i = 1; i <= m_numYears; ++i) { // For loop that iterates for the given number of years received by user input
		for (j = 1; j <= 12; ++j) { // Nested for loop that iterates 12 times, this is for the compounded interest that is applied to the deposit once a month for each year
			balance1 = balance1 + m_monthlyDeposit;
			balance = balance + m_monthlyDeposit;
			balance = balance + (balance * (interestPercent / 12));
			// The above calculation generate compounded interest. This part took me a while as I kept generating accrued interest rather than the new amount each month.
		}

		interestEarned = balance - balance1; // This allowed me to display interest earned per month, rather than accrued interest.
		m_originalDeposit = balance1 + interestEarned; // Interest gets added to balance1, which a variable that stores the total monthly deposits per year.

		cout << setw(3) << right << i << setw(15) << right << "$" << setw(10) << left << fixed << setprecision(2) << m_originalDeposit;
		cout << setw(25) << right << "$" << setw(10) << left << fixed << setprecision(2) << interestEarned; //Formatted rows that show year, deposit amount, and interest earned per year
		cout << endl;
		cout << endl;
		balance1 = balance1 + interestEarned; // balance1 is a placeholder variable that is used to subtract the previous year balance from current year balance, which allows me to show interest earned
	}
	cout << setfill('-') << setw(64) << "" << endl; // Seperates end of report from additional output
}


void WithoutDeposit(double depositAmount, double interest, int years) { //Function to determine interest WITHOUT monthly deposits
	int i; // Declared int i and j to be used in below For loop
	int j;
	double interestEarned; // Variable to keep track of interest earned
	double interestPercent; // Variabe that converts annual interest from user input into decimal
	double balance = depositAmount;
	double balance1 = depositAmount;

	interestPercent = interest / 100; // Converts annual interest from user input into decimal

	cout << "    " << "Balance and Interest Without Additional Monthly Deposits" << "    " << endl; //The following formats the top of the printed report
	cout << setfill('=') << setw(64) << "" << endl;
	cout << "  Year        ";
	cout << "Year End Balance         ";
	cout << "Year End Earned Interest" << endl;
	cout << setfill('=') << setw(64) << "" << endl;
	cout << setfill(' ');

	for (i = 1; i <= years; ++i) { // For loop that prints each year, year end balances, and year end interest
		for (j = 1; j <= 12; ++j) { // Nested for loop that loops 12 times (for each month in the year)
			balance = balance + (balance * (interestPercent / 12));
		}
		interestEarned = balance - balance1;
		depositAmount = balance1 + interestEarned;
		// Above is similar to the method I used to determine interest with monthly deposits, but this does not take monthly deposits into account.

		cout << setw(3) << right << i << setw(15) << right << "$" << setw(10) << left << fixed << setprecision(2) << depositAmount;
		cout << setw(25) << right << "$" << setw(10) << left << fixed << setprecision(2) << interestEarned; //Formatted output for report
		cout << endl;
		cout << endl;
		balance1 = balance1 + interestEarned;
	}
	cout << setfill('-') << setw(64) << "" << endl;
	cout << endl;
}
