#include<iostream>
using namespace std;

int b = 10000;

void displayBalance(){
    int balance = b;
    cout << "Your current balance is " << balance << endl;
}

void withdraw(){
    int balance = b;
    int withdrawAmount;
    cout << "How much would you like to withdraw?";
    cin >> withdrawAmount;
    if (withdrawAmount > balance){
        cout << "Insufficient funds" << endl;
    }
    else{
        balance -= withdrawAmount;
        cout << "Withdrawal successful" << endl;
        cout << "Your new balance is " << balance << endl;  
    }
}

void deposit(){
    int depositAmount;
    int balance = b;
    cout << "How much would you like to deposit? ";
    cin >> depositAmount;
    balance += depositAmount;
    cout << "Deposit successful" << endl;
    cout << "Your new balance is " << balance << endl;
    cout << "What would you like to do?" << endl;
}

void transfer(){
    int depositAmount;
    int transferAmount;
    string transferTo;
    string confirm;
    int balance = b;
    cout << "How much would you like to transfer? ";
    cin >> transferAmount;
    if (transferAmount > balance){
        cout << "Insufficient funds" << endl;
    }
    cout << "How would you like to transfer to? ";
    cin >> transferTo;
    cout << "are you sure you want to transfer to " << transferTo << "? (y/n)";
    cin >> confirm;
    if (confirm == "y"){
        balance -= transferAmount;
        cout << "Transfer successful" << endl;
        cout << "Your new balance is " << balance << endl;
    }
    else{
        cout << "Transfer cancelled" << endl;
    }
}

void displayChoice(){
    int choice;
    cout << "What would you like to do?" << endl ;
    cout << "1. Withdraw" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Check balance" << endl;
    cout << "4. transfer" << endl;
    cout << "5. Exit" << endl;
    cin >> choice;
    if (choice == 1) {
       withdraw();
       displayChoice();
    }
    if (choice == 2) {
       deposit();
       displayChoice();
    }
    if (choice == 3) {
        displayBalance();
        displayChoice();
   }
   if (choice == 4) {
       transfer();
       displayChoice();
   }
   if (choice == 5) {
       cout << "Thank you for using the bank of c++" << endl;
       EXIT_SUCCESS;
   } 
}

int main(){
    int numAccounts;
    string password;
    int balance;
    cout << "welcome to the bank of c++ " << endl;
    cout << "What is your account number?" << endl;
    cin >> numAccounts;
    cout << "What is your password?";
    cin >> password;
    displayChoice();
    return 0;
}