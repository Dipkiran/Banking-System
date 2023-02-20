#include <iostream>

using namespace std;

class accountdetails {
    long accno;
    public:
    long getAccountNumber() {
        cout<<"\n Enter Account Number:";
        cin>>accno;
        return accno;
    }
};

class account: public accountdetails {
    private:
    double balance = 0;
    public:
    void display_balance(){
        cout<<"\n Your balance is:" << balance;
        cout<<"\n" << endl;
    }
    void deposit_money(){
        double deposit_amount;
        cout<<"\n Enter the deposit amount:";
        cin>>deposit_amount;
        balance = balance + deposit_amount;
        cout<<"\n" << endl;
        cout<<deposit_amount<<" is deposited in your account. \n";
        cout<<"\n Your new balance is:" << balance;
        cout<<"\n" << endl;
    }
    void withdraw_money(){
        double withdraw;
        cout<<"\n Enter the amount to withdraw:";
        cin>>withdraw;
        if(withdraw < balance){
            balance = balance - withdraw;
            cout<<"\n" << endl;
            cout<<withdraw<<" is withdrawn from your account. \n";
            cout<<"\n Your new balance is:" << balance;
            cout<<"\n" << endl;
        } else {
            cout<<"\n Insufficient Balance.";
            cout<<"\n" << endl;
        }
    }
};

class create_new_account {
    long accno;
    string name;
    string dob;
    public:
    long create_account(){
        cout <<"\n" <<endl;
        cout << "Enter your details:" <<endl;
        cout << "1. Enter your name:"<<endl;
        cin >> name;
        cout << "2. Enter your DOB:"<<endl;
        cin >> dob;
        accno = 324659534283;
        cout << "Your account has been created. Your new account number is "<<accno;
        cout<<"\n" << endl;
        return accno;
    }
};

int main() {
    create_new_account c;
    account a;
    start:
    cout << "Choose an option[1-5]:" <<endl;
    cout << "1. Open new account."<<endl;
    cout << "2. Display balance."<<endl;
    cout << "3. Withdraw money."<<endl;
    cout << "4. Deposit money."<<endl;
    cout << "5. End."<<endl;
    string user_input;
    cin >> user_input;
    int input;
    try {
        input = stoi(user_input);
        long accno;
        if(input==1){
            accno = c.create_account();
            goto start;
        } else{
            switch(input){
                accno = a.getAccountNumber();
                case 2:
                    a.display_balance();
                    goto start;
                case 3:
                    a.withdraw_money();
                    goto start;
                case 4:
                    a.deposit_money();
                    goto start;
                case 5:
                    cout<<"You are exiting the system";
                    return 0;
                default:
                    goto start;
            }
        }
    } catch(...) {
        cout << "Enter a valid input" <<endl;
        goto start;
    }
}
