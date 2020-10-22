/*
 * Amounts.h
 *
 *  Created on: Sep 29, 2020
 *      Author: Elizabeth Hodgman
 */

#ifndef AMOUNTS_H_
#define AMOUNTS_H_

using namespace std;

class Amounts {
// Public and Private variables
public:
   Amounts();
   void SetInitialAmount(double initialAmount);
   double GetInitialAmount();
   void SetMonthlyAmount(double monthlyDeposit);
   double GetMonthlyAmount();
   void SetInterestAmount(double annualInterest);
   double GetInterestAmount();
   void SetYearsAmount(int numYears);
   int GetYearsAmount();

private:
   double initialAmount;
   double monthlyDeposit;
   double annualInterest;
   int numYears;
};

#endif /* AMOUNTS_H_ */
