#include<iostream>
#include<string>
using namespace std;

// BankAccount - is a blueprint for a obj containing member function and member variables.
class BankAccount{

    private:
    // instance variable - unique copy to each BankAccount obj | Non - Static members.
    string accountHolderName; 
    double balance;

    //Class variable - shared copy among all the obj | static members
    // 1. Declared inside the class.
    // 2. Def. outside the class. Error if initialized in class (except for const static members).
    // static double interestRate = 2;
    const static double interestRate = 5;
    // 3. can be accessed using class name if they are declasred public. eg: BankAccount::totalAccounts
    static double interestRate;
    static int totalAccounts;

    public:
    BankAccount(string name, double initbal){
        accountHolderName = name;
        balance = initbal;
        totalAccounts++;
    }

    // Member functions
    void deposit(double amt){
        if(amt>0){
            balance = balance + amt;
        }else{
            cout<<"Deposit amt should be greater than 0";
        }
    }

    void withdraw(double amt){
        if(amt<=balance && amt>0){
            balance = balance - amt;
        }else{
            cout<<"insufficient funds";
        }
    }

    //static member functions 
    // - not associated with any specific obj.
    // - Can only access static members.
    // - Can be called without creating obj.
    static double getInterestRate(){
        return interestRate;
    }

    // Friend Function:
    // 1. Can access public, private, protected members of class in which it is declared as friend.
    friend void displayAccountDetails(BankAccount& acc);

    // Friend class 
    // 1. Can access public, private, protected members of class in which it is declared as friend.
    // 2. friendship is not mutual. (A is friend of B than B does not become friend of A).
    // 3. friendship is not inherited. (A is friend of B than subclasses of A are not friends of B).
    friend class BankAuditor;
};

int BankAccount::totalAccounts;

void displayAccountDetails(BankAccount& ba_obj){
    cout<<"Account holder name = "<<ba_obj.accountHolderName<<endl;
    cout<<"Current Balance = "<<ba_obj.balance<<endl;
}

class BankAuditor{
    public:
    void auditAccount(BankAccount& acc){
        cout<<"Account holder name = "<<acc.accountHolderName<<endl;
        cout<<"Current Balance = "<<acc.balance<<endl;
        cout<<"Current interest rate = "<<acc.getInterestRate()<<endl;
    }
};

int main(){
    BankAccount acc1("Aayush", 1000);
    BankAccount acc2("Shaun", 2000);

    acc1.deposit(200);
    acc1.withdraw(300);

    // BankAccount::totalAccounts; inaccesible as static variable is private.

    displayAccountDetails(acc1);

    BankAuditor aud;
    aud.auditAccount(acc2);

    return 0;
}
