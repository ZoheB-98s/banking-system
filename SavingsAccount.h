//contents of SavingsAccount.h

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <iostream>
#include <iomanip>
#include <string>
#include "BankAccount.h"

using namespace std;

class SavingsAccount : public BankAccount{
private:
    //flag to hold status of account
    bool status;
    bool ACTIVE = true;
    bool INACTIVE = false;

public:
    //class constructor, will also
    //call constructor of base class
    SavingsAccount(string num, double b, double air) :
        BankAccount(num, b, air)
    {
        //check if balance is greater than 25
        //to set correct status
        if(balance >= 50){
            status = ACTIVE;
        }
        //otherwise it must be inactive
        else{
            status = INACTIVE;
        }
    }

    //accessor function
    bool getStatus() const{
        return status;
    }

    //withdraw() function of SavingsAccount
    virtual bool withdraw(double w){
        //check if status is active
        if(status == ACTIVE){
            //if yes, proceed with withdrawal
            BankAccount::withdraw(w);

            //update status if necessary
            if(balance < 50)
                status = INACTIVE;
            return true;
        }
        else{
            //otherwise, print error message then return
            cout << fixed << setprecision(2);
            cout << "Withdrawal failed! Savings account ";
            cout << "is inactive (Current balance: $";
            cout << balance << ")" << endl;
            return false;
        }
    }

    //deposit() function
    virtual bool deposit(double d){
        //check if account is inactive
        if(status == INACTIVE){
            //check if deposit will bring
            //balance over 25
            if(d + balance >= 50){
                //if yes, proceed with deposit
                BankAccount::deposit(d);
                return false;
            }
            else{
                //if not, print error message then return
                cout << fixed << setprecision(2);
                cout << "Deposit failed! Savings account will";
                cout << " be inactive after deposit!\n($";
                cout << balance << " + $" << d;
                cout << " = $" << balance + d << ")\n";
                return true;
            }

        } //first if statement ends here
        //otherwise
        else{
            //means account is still active
            //simply proceed with deposit
            BankAccount::deposit(d);
        }
        
    }

    //yearlyCharge() function
    virtual ServAndOwed yearlyCharge(){
        //first check number of withdrawals
        if(numWithdrawal > 4){
            //add the relevant charges to service charges
            serviceCharges += 1.0 * (numWithdrawal - 4);

            //add the service charges to yearly charges
            yrCharges += serviceCharges;
        }

        //structure to return at the end, the service
        //charges, because they will be reset upon
        //execution of
        //BankAccount::yearlyCharge()
        ServAndOwed temp;
        temp.servCharges = serviceCharges;
        temp.totalOwed = 0.0;

        //perform yearly processing
        BankAccount::yearlyCharge();

        //check if balance has fallen below
        //25 to update status if necessary
        if(balance < 50){
            status = INACTIVE;
        }

        //return the structure, from which can be
        //retrieved the service charges of this month
        return temp;
    }
};

#endif
