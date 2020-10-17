//contents of BankAccount.h

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//structure to be returned by
//yearlyCharge() function, so it
//can return both service charges
//and amount owed
struct ServAndOwed{
    double servCharges;
    double totalOwed;
};

class BankAccount{
//member variables are declared protected
//so they can be easily accessed by
//derived classes
protected:
	string accountNumber;
    double balance;
    int numDeposits;
    int numWithdrawal;
    double annualIntRate;
    double yrCharges;

    //added member to store service charges
    //of a month
    double serviceCharges;

public:
    //constructor that accepts values
    //for balance and annual interest rate
    BankAccount(string num, double b, double air){
        //check for invalid input
        if(b < 0){
            cout << "Error! Balance cannot start with";
            cout << " a negative amount!\n";
            cout << "Now terminating!\n";
            exit(EXIT_FAILURE);
        }

        if(air < 0){
            cout << "Error! Annual interest rate";
            cout << " cannot be negative!\n";
            cout << "Now terminating!\n";
            exit(EXIT_FAILURE);
        }

        //set balance and annual interest rate
        //to argument values
        balance = b;
        annualIntRate = air;
        accountNumber = num;

        //set some initial values to other
        //member variables
        numDeposits = 0;
        numWithdrawal = 0;
        yrCharges = 0.0;

        //set service charges member
        serviceCharges = 0.0;
    }

    //accessor functions
    double getBalance() const{
        return balance;
    }

    int getNumDeposits() const{
        return numDeposits;
    }

    int getNumWithdrawals() const{
        return numWithdrawal;
    }

    double getAnnualIntRate() const{
        return annualIntRate;
    }

    double getYearlyCharges() const{
        return yrCharges;
    }

    //mutator functions
    void setAnnualIntRate(double air){
        //validate input using while loop
        while(air < 0){
            cout << "Negative values for annual interest ";
            cout << "rates not accepted! Enter again: ";
            cin >> air;
        }

        //store value in member variable
        annualIntRate = air;
    }

    void setYearlyCharges(double yc){
        //validate input using while loop
        while(yc < 0){
            cout << "Negative values for yearly charges ";
            cout << "are not accepted! Enter again: ";
            cin >> yc;
        }

        //store value in member variable
        yrCharges = yc;
    }

    //mutator functions for number of deposits and withdrawals,
    //and also for the balance are not necessary, because they
    //will be controlled by the number of transactions

    //deposit() function
    virtual bool deposit(double d){
        //add the argument to the balance
        balance += d;

        //increment number of deposits
        numDeposits++;
        
        return false;
    }

    //withdraw() function
    virtual bool withdraw(double w){
        //subtract the argument from balance
         
        if(w > balance){
            //print error message
        
        cout << fixed << setprecision(2);
        cout << "Withdrawal failed! You attempted to withdraw $";
        cout << w << " but current balance is $" << balance;
        return false;
        }
        //else, simply perform withdrawal
        else{
        	//increment number of withdrawals
        	balance -= w;
        	numWithdrawal++;
        	return true;
        }
        
    }

    //calcInt() function
    //to add the accumulated interest
    //to the balance
    virtual void calcInt(){
        //add to current balance the yearly interest

        //yearly interest is yearly interest rate
        //times balance

        //yearly interest rate is annual interest
        //rate
        balance += (annualIntRate/365.0)*balance;
    }

    //yearlyCharge() function
    //this is the function that is called
    //at the end of each year, to get the
    //yearly fee and reset transactions
    //also, this function will return the
    //service charges for the year
    virtual ServAndOwed yearlyCharge(){
        //subtract yearly charges from balance
        balance -= yrCharges;

        //add yearly interest to balance
        calcInt();

        //reset number of deposits and withdrawals
        numDeposits = 0;
        numWithdrawal = 0;

        //also reset yearly charges to 0
        yrCharges = 0.0;

        //also reset service charges
        serviceCharges = 0.0;

        //a return statement
        //could return any struct ServAndOwed
        ServAndOwed temp;
        return temp;
    }
    
    //void closeAcc(){
    	//~BankAccount();//{
		//};
	//}

};

#endif
