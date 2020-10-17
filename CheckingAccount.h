//contents of CheckingAccount.h

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include <iostream>
#include<string>
#include "BankAccount.h"

using namespace std;

class CheckingAccount : public BankAccount{
private:
    //member variable to keep track
    //of how much is owed to the bank
    double owed;

public:
    //constructor, will call
    //constructor of parent class
    CheckingAccount(string num, double b, double air) :
        BankAccount(num, b, air)
        {
            owed = 0.0;
        }

    //accessor function
    double getAmountOwed() const{
        return owed;
    }
    
        //deposit() function
    virtual bool deposit(double d){
        //check if account is inactive
        if(d < 9999){
            //check if deposit is less than 9999
                //if yes, proceed with deposit
                BankAccount::deposit(d);
		}
        else{
        	BankAccount::deposit(d);
            //if not, print error message then return
            cout << fixed << setprecision(2);
            cout << "High risk Deposit! Checking account will be in";
            cout << " high risk after deposit!\n($";
            cout << balance << " + $" << d;
            cout << " = $" << balance + d << ")\n";
            return true;
        }
    }
    

    //withdraw() function of the checking account
    virtual bool withdraw(double w){
        //first check if withdrawal will
        //bring the balance to negative
        if(w > balance){
            //print error message
            cout << fixed << setprecision(2);
            cout << "Withdrawal failed! You attempted to check $";
            cout << w << " but current balance is $" << balance;
            cout << ".\nYou will be charged $25.00 for this.\n";

            //subtract 25 from balance
            balance -= 25.0;
            return false;
        }
        //else, simply perform withdrawal
        else{
            BankAccount::withdraw(w);
            return true;
        }
    }

    //yearlyCharge() function of checking account
    virtual ServAndOwed yearlyCharge(){
        //add fee to service charges
        serviceCharges += 5.0;

        //also add the charges per withdrawal
        serviceCharges += 0.1 * numWithdrawal;

        //add the service charges to yearly charges
        yrCharges += serviceCharges;

        //structure to return at the end, the service
        //charges and total owed to bank, because
        // they will be reset upon execution of
        //BankAccount::yearlyCharge()
        ServAndOwed temp;
        temp.servCharges = serviceCharges;

        //perform yearly processing
        //this will reset the serviceCharges variable
        BankAccount::yearlyCharge();

        //after processing,
        //check if balance is negative
        if(balance < 0){
            //update owed member variable
            //to amount owed to bank by user
            owed = 0 - balance;
            cout << "Your Account is in High Risk because of negative balance" << endl;
        }

        //store it in the structure
        temp.totalOwed = owed;

        //reset owed to 0
        owed = 0;

        //return the structure, from which can be
        //retrieved the service charges of this month
        return temp;
    }

};

#endif
