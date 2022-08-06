
#ifndef BALANCEANDINTEREST_H
#define BALANCEANDINTEREST_H


void WithoutDeposit(double depositAmount, double interest, int years); //WithoutDeposit function definitions

class MySavings { //Class
public:
	MySavings(double depositAmount, double deposits, double interest, int years);
	void reportWithDeposits(); //Class method to generate report with monthly deposits
private:
	double m_originalDeposit;
	double m_monthlyDeposit;
	double m_interestRate;
	int m_numYears;
	int i;
	int j;
	double interestEarned;
	double interestPercent;
	double balance = m_originalDeposit;
	double balance1 = m_originalDeposit;
};
#endif