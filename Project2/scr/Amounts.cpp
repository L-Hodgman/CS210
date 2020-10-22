/*
 * Amounts.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: Elizabeth Hodgman
 */
#include <iostream>
using namespace std;

#include "Amounts.h"

// Constructor defaults
Amounts::Amounts(){
   this->initialAmount = 0.0;
   this->monthlyDeposit = 0.0;
   this->annualInterest = 0;
   this->numYears = 0;
}

// SetInitialAmount() & GetInitialAmount()
void Amounts::SetInitialAmount(double initialAmount){
   this->initialAmount = initialAmount;
}
double Amounts::GetInitialAmount(){
   return initialAmount;
}
// SetMonthlyAmount() & GetMonthlyAmount()
void Amounts::SetMonthlyAmount(double monthlyDeposit){
   this->monthlyDeposit = monthlyDeposit;
}
double Amounts::GetMonthlyAmount(){
   return monthlyDeposit;
}
// SetAnnualAmount() & GetAnnualAmount()
void Amounts::SetInterestAmount(double annualInterest){
   this->annualInterest = annualInterest;
}
double Amounts::GetInterestAmount(){
   return annualInterest;
}
// SetYearsAmount() & GetYearsAmount()
void Amounts::SetYearsAmount(int numYears){
   this->numYears = numYears;
}
int Amounts::GetYearsAmount(){
   return numYears;
}

