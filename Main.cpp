//contents of main.cpp

#include <iostream>
#include<string>
#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;



int main()
{
	int num;
    //display the menu list
    do
    {
        cout << "\n========= Bank ACCOUNT MENU =========" << endl
            << "[1]. Work With Savings Account" << endl
            << "[2]. Work With Checking Account" << endl
            << "[3]. Exit" << endl;
        cin >> num;
        //if not valid entry
        while (num < 1 || num > 3)
        {
            cout << "Please enter a valid option";
        }
        
    switch (num){
	    case 1:
		{
		  
			cout << "SAVINGS ACCOUNT\n\n";
		    //create a savings account
		    double startingBalance;
		    double annualRate;
		    string accNum;
		    cout << "Enter account Number: ";
		    cin >> accNum;
		    bool notDigit = false;
		    for(int i = 0; i < accNum.size(); i++){
		    	if(!isdigit(accNum[i])){
		    		notDigit = true;
		    		break;
				}	
			}
			if(notDigit){
				cout << "Invalid account Number, account number must include only digits... Redirecting to menu." << endl;
				break;
			}
			string sAccNum = "S" + accNum; 
		
		    cout << "Enter starting balance of Savings Account " << sAccNum << ": $";
		    cin >> startingBalance;
		
		    cout << "\nEnter Annual Interest Rate in %: ";
		    cin >> annualRate;
		    //update interest rate to be
		    //correct value because it is in %
		    annualRate = annualRate/100;
		
		    cout << "\nCreating Savings Account with this data...";
		    SavingsAccount savAcc(sAccNum, startingBalance, annualRate);
		    cout << "Done!\n";
		
		    //set value of yearly processing charges and set it
		    double initProcessCharges;
		    cout << "Enter yearly processing charges: $";
		    cin >> initProcessCharges;
		    savAcc.setYearlyCharges(initProcessCharges);
		
		    //This can be also implemented as a menu driven program
		    //but for the sake of simplicity, we used while loops
		    //to get the withdrawals and deposits
		    double depos = 0, withdr = 0;
		    double totalDepos = 0, totalWithdr = 0;
			string depositOrWithdraw;
			while(true){
				cout << "Press d to deposit or press w to withdraw or -1 to stop" << endl;
				cin >> depositOrWithdraw;
				if(depositOrWithdraw == "d" || depositOrWithdraw == "D"){
					
				    //get all the yearly deposits
				    cout << "\nEnter the deposits one by one. When finished,";
				    cout << " enter -1:" << endl;
				
				    cin >> depos;
				
				    while(depos != -1){
				        //add deposit to total
				        totalDepos += depos;
				
				        cout << fixed << setprecision(2);
				        cout << "Performing deposit...\n";
				        savAcc.deposit(depos);
				        cout << "Done!\n";
				
				        //display data of savings account
				        cout << "\nBalance: $" << savAcc.getBalance();
				        cout << "\nNumber of deposits: " << savAcc.getNumDeposits();
				        cout << "\nNumber of withdrawals: " << savAcc.getNumWithdrawals();
				
				        cout << "\n\nEnter another deposit amount, or -1 to stop: ";
				        cin >> depos;
				    }
					
				}
				else if(depositOrWithdraw == "w" || depositOrWithdraw == "W"){
					//use the same method to take all the yearly withdrawals
				    cout << "\nEnter the withdrawals one by one. When finished,";
				    cout << " enter -1:" << endl;
				
				    cin >> withdr;
				
				    while(withdr != -1){
				        //add withdrawal to total
				        totalWithdr += withdr;
				
				        cout << fixed << setprecision(2);
				        cout << "Performing withdrawal...\n";
				        savAcc.withdraw(withdr);
				        cout << "Done!\n";
				
				        //display data of savings account
				        cout << "\nBalance: $" << savAcc.getBalance();
				        cout << "\nNumber of deposits: " << savAcc.getNumDeposits();
				        cout << "\nNumber of withdrawals: " << savAcc.getNumWithdrawals();
				
				        cout << "\n\nEnter another withdrawal amount, or -1 to stop: ";
				        cin >> withdr;
				    }
				}
				else if(depositOrWithdraw == "-1"){
					break;
				}
				else{
					cout << "Invalid Choice!!! Please choose Something between deposit or withdraw." << endl;
				}
				
			}
			
			//display statistics
		
		    cout << "\nDone! Here are the yearly statistics: ";
		    cout << "\nBeginning balance: $" << startingBalance;
		    cout << "\nNumber of deposits: " << savAcc.getNumDeposits();
		    cout << "\nTotal amount of deposits: $" << totalDepos;
		    cout << "\nNumber of withdrawals: " << savAcc.getNumWithdrawals();
		    cout << "\nTotal amount of withdrawals: $" << totalWithdr;
		    cout << "\nYearly charges: $" << initProcessCharges;
		
		    //get the service charges in a structure
		    //and perform yearly processing
		    ServAndOwed temp = savAcc.yearlyCharge();
		
		    cout << "\nService fees: $" << temp.servCharges;
		    cout << "\nTotal yearly charges: $" << initProcessCharges + temp.servCharges;
		
		    //display ending balance
		    cout << "\nEnding balance: $" << savAcc.getBalance();
			
		}
	        break;
	    
	    case 2:
	    {
			
			cout << "\n\n\nCHECKING ACCOUNT\n\n";
			double startingBalance;
		    double annualRate;
		    
		    string accNum;
		    cout << "Enter account Number: ";
		    cin >> accNum;
		    
		    bool notDigit = false;
		    for(int i = 0; i < accNum.size(); i++){
		    	if(!isdigit(accNum[i])){
		    		notDigit = true;
		    		break;
				}	
			}
			if(notDigit){
				cout << "Invalid account Number, account number must include only digits... Redirecting to menu." << endl;
				break;
			}
		    
		    
			string cAccNum = "C" + accNum; 
		
		    cout << "Enter starting balance of Checking Account " << cAccNum << ": $";
		    cin >> startingBalance;
		
		
		    cout << "\nEnter Annual Interest Rate in %: ";
		    cin >> annualRate;
		    //update interest rate to be
		    //correct value because it is in %
		    annualRate = annualRate/100;
		
		    //create a checking account object
		    cout << "\nCreating Checking Account with this data...";
		    CheckingAccount checkAcc(cAccNum, startingBalance, annualRate);
		    cout << "Done!\n";
			double initProcessCharges;
		    //set value of yearly processing charges and set it
		    cout << "Enter yearly processing charges: $";
		    cin >> initProcessCharges;
		    checkAcc.setYearlyCharges(initProcessCharges);
		
		    //remember, you can only withdraw from this
		    //checking account
		    double depos = 0, withdr = 0;
		    double totalDepos = 0, totalWithdr = 0;
		    
		    string depositOrWithdraw;
			while(true){
				cout << "Press d to deposit or press w to withdraw or -1 to stop" << endl;
				cin >> depositOrWithdraw;
				if(depositOrWithdraw == "d" || depositOrWithdraw == "D"){
					
				    //get all the yearly deposits
				    cout << "\nEnter the deposits one by one. When finished,";
				    cout << " enter -1:" << endl;
				
				    cin >> depos;
				
				    while(depos != -1){
				        //add deposit to total
				        totalDepos += depos;
				
				        cout << fixed << setprecision(2);
				        cout << "Performing deposit...\n";
				        bool flag = checkAcc.deposit(depos);
				        cout << "Done!\n";
				        //cout << flag << endl;
						if(flag)
							cout << "Your Checking Account " << cAccNum << "*"<< " is in High Risk!!!!!!!!!!!!!!" << endl;
						
				        //display data of savings account
				        cout << "\nBalance: $" << checkAcc.getBalance();
				        cout << "\nNumber of deposits: " << checkAcc.getNumDeposits();
				        cout << "\nNumber of withdrawals: " << checkAcc.getNumWithdrawals();
				
				        cout << "\n\nEnter another deposit amount, or -1 to stop: ";
				        cin >> depos;
				    }
					
				}
				else if(depositOrWithdraw == "w" || depositOrWithdraw == "W"){
					//use the same method to take all the yearly withdrawals
				    cout << "\nEnter the withdrawals one by one. When finished,";
				    cout << " enter -1:" << endl;
				
				    cin >> withdr;
				
				    while(withdr != -1){
				        //add withdrawal to total
				        totalWithdr += withdr;
				
				        cout << fixed << setprecision(2);
				        cout << "Performing withdrawal...\n";
				        checkAcc.withdraw(withdr);
				        cout << "Done!\n";
				
				        //display data of savings account
				        cout << "\nBalance: $" << checkAcc.getBalance();
				        cout << "\nNumber of deposits: " << checkAcc.getNumDeposits();
				        cout << "\nNumber of withdrawals: " << checkAcc.getNumWithdrawals();
				
				        cout << "\n\nEnter another withdrawal amount, or -1 to stop: ";
				        cin >> withdr;
				    }
				}
				else if(depositOrWithdraw == "-1"){
					break;
				}
				else{
					cout << "Invalid Choice!!! Please choose Something between deposit or withdraw." << endl;
				}
				
			}
			//display statistics
		    cout << "Done! Here are the yearly statistics: ";
		    cout << "\nBeginning balance: $" << startingBalance;
		    cout << "\nNumber of withdrawals: $" << checkAcc.getNumWithdrawals();
		    cout << "\nTotal amount of withdrawals: $" << totalWithdr;
		    cout << "\nInitial yearly charges: $" << initProcessCharges;
		
		    //get the service charges and owed amount
		    //in the structure and perform yearly processing
		    ServAndOwed temp = checkAcc.yearlyCharge();
		
		    cout << "\nService fees: $" << temp.servCharges;
		    cout << "\nTotal yearly charges: $" << initProcessCharges + temp.servCharges;
		    cout << "\nEnding balance: $" << checkAcc.getBalance();
		    cout << "\nClient owes to bank: $" << checkAcc.getAmountOwed();
		    cout << endl;
		}
	        break;
	}

    } while (num != 3);
    
    
    //return 0 to mark successful termination
    return 0;
}
