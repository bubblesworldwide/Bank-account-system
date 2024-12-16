// Updated bank account system 16 december 2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

//creating a class
class Account
{
    //declaration of private data members
private:
    string accountName;
    int accountNumber;
    float accountBalance;
    char gender;
    string idNum;
    static int totalNumAccounts;

    //declaration of public methods
public:
    Account(); //default constructor
    void setAccount(string, float, char, string); //setter
    string getAccountName();
    int getAccountNumber();
    float getAccountBalance();
    void depositAmount(int);
    void withdrawAmount(int);
    string getGender();
    string getIdNum();
    void updateStaticMember(int);
    int getTotalAccounts();
    bool operator==(string); //compare by ID number
    bool operator==(char);   //compare by first character of the name
};

//default constructor
Account::Account()
{
    //initialize default values
    accountName = " ";
    accountNumber = 0;
    accountBalance = 0.0f;
    idNum = " ";
    gender = ' ';
}

//static members
int Account::totalNumAccounts = 0;

//setter
void Account::setAccount(string anm, float acb, char gen, string id)
{
    //validate name
    if (anm.size() > 0)
    {
        //store account name
        accountName = anm;
    }
    else
    {
        accountName = " ";
    }

    //generate account number and store it
    accountNumber = 10000000 + rand() % (90000000 - 10000000 + 1);

    //store account balance
    accountBalance = acb;

    //store id number
    idNum = id;

    //store gender
    gender = gen;

    totalNumAccounts++;
}

//getters
string Account::getAccountName()
{
    return accountName;
}
int Account::getAccountNumber()
{
    return accountNumber;
}
float Account::getAccountBalance()
{
    return accountBalance;
}
int Account::getTotalAccounts()
{
    return totalNumAccounts;
}
string Account::getGender()
{
    //declaration of variables
    string gn = "Female";

    //introduction to if statement
    if (toupper(gender) == 'M')
    {
        //store gender
        gn = "Male";
    }

    return gn;
}
string Account::getIdNum()
{
    return idNum;
}

//methods
void Account::depositAmount(int dep)
{
    //declaration of variables
    const int charge = 6;


        // Check if the deposit amount is valid
        if (dep <= 0)
        {
            cout << "Invalid deposit amount. Please enter a positive value.\n";
            return;
        }

        //update account balance
        accountBalance = accountBalance + dep - charge;

        // Provide feedback to the user
        cout << "Deposit successful! Your new balance is: " << accountBalance << endl;

}
void Account::withdrawAmount(int wit)
{
    //declaration of variables
    const int charge = 10;

        //check if the withdrawal amount is valid
        if (wit <= 0)
        {
            cout << "Invalid withdrawal amount. Please enter a positive value.\n";
            return;
        }

        //check if the amount to withdraw is not greater than the account balance
        if (wit + charge > accountBalance)
        {
            cout << "Funds unavailable. Your current balance is: " << accountBalance << endl;
        }
        else
        {
            //withdraw and update balance
            accountBalance = accountBalance - wit - charge;
            cout << "Withdrawal successful! A charge of " << charge << " has been applied.\n";
            cout << "Your new balance is: " << accountBalance << endl;
        }
    

}
void Account::updateStaticMember(int cnt)
{
    //call setter
    totalNumAccounts = totalNumAccounts + cnt;
}

//overloaded operators
bool Account::operator==(string id)
{
    //declaration of variables
    bool test = false;

    //introduction to if statement
    if (idNum == id)
    {
        //store test
        test = true;
    }

    return test;
}
bool Account::operator==(char n)
{
    //declaration of variables
    bool test = false;

    //introduction to if statement
    if (toupper(accountName[0]) == toupper(n))
    {
        //store test
        test = true;
    }

    return test;
}

//Function prototypes
void setAccount(Account ac[], int siz, int& count); // Fixed to pass count by reference
void updateStaticMember(Account ac[], int);
void displayAccountDetails(Account ac[], int);
void viewAccount(Account ac[], int);
void updateAccount(Account ac[], int);

//declaration of constant variables
const int SIZE = 10;

int main()
{
    //declaration of variables
    Account ac[SIZE];
    int value = 0;
    int count = 0;

    //call function for generating random account number
    srand(time(NULL));

    //introduction to do-while loop
    do
    {
        //display menu to user
        cout << "==========================\n";
        cout << "Welcome to Bubbles' BANK       \n";
        cout << "==========================\n";
        cout << "1. Create a new account\n";
        cout << "2. View account balance\n";
        cout << "3. Update account details\n";
        cout << "4. Exit\n\n";
        cout << "Enter your choice : ";
        cin >> value;
        cin.ignore();

        //introduction to if statement
        if (value == 1)
        {
            //call non-member function
            setAccount(ac, SIZE, count);
        }
        else if (value == 2)
        {
            //call non-member function
            viewAccount(ac, count);
        }
        else if (value == 3)
        {
            //call non-member function
            updateAccount(ac, count);
        }
        else
        {
            //display
            cout << "Thank you for using Bubbles' BANK.\n";
            break;
        }

    } while (value != 4);

    _getch();
    return 0;
}

//non-member functions
void displayAccountDetails(Account ac[], int count)
{
    //display account details
    //introduction to for loop
    for (int j = 0; j < count; j++)
    {
        cout << "--------------------------------\n";
        cout << "Account holder's full name : " << ac[j].getAccountName() << endl;
        cout << "ID number is " << ac[j].getIdNum() << endl;
        cout << "Gender : " << ac[j].getGender() << endl;
        cout << "Account number : " << ac[j].getAccountNumber() << endl;
        cout << fixed << setprecision(3);
        cout << "Account balance : " << ac[j].getAccountBalance() << endl;
        cout << "Total number of accounts : " << ac[j].getTotalAccounts() << endl;
        cout << "--------------------------------\n";
    }
}
void updateStaticMember(Account ac[], int cnt)
{
    //call static member
    ac[cnt].updateStaticMember(cnt);
}
void setAccount(Account ac[], int siz, int& count) // Pass count by reference
{
   
    //declaration of varibales
    string anm;
    string id;
    char gen;
    float amount;

    //introduction to if statement
    if (count >= siz)
    {
        cout << "Bank capacity reached. Cannot add more accounts.\n";
        return;
    }

    //allow uset to enter values
    cout << "\nEnter account holder's full name: ";
    cin.ignore();
    getline(cin, anm);

    cout << "Enter ID number (13 digits): ";
    cin >> id;

    if (id.size() != 13)
    {
        cout << "\nInvalid ID number. Please try again.\n";
        return;
    }

    cout << "Enter gender (F/M): ";
    cin >> gen;

    if (toupper(gen) != 'F' && toupper(gen) != 'M')
    {
        cout << "\nInvalid gender. Please try again.\n";
        return;
    }

    cout << "Enter initial deposit: ";
    cin >> amount;

    if (amount < 0)
    {
        cout << "\nInvalid deposit amount. Please try again.\n";
        return;
    }

    ac[count].setAccount(anm, amount, gen, id);
    displayAccountDetails(ac, count + 1);
    count++;
}
void viewAccount(Account ac[], int count)
{
    //declaration of variables
    string idNum;

    //allow user to enter values
    cout << "\nEnter your ID number: ";
    cin >> idNum;

    //declaration of for loop
    for (int i = 0; i < count; i++)
    {
        if (ac[i] == idNum)
        {
            //display
            cout << "Account holder's full name: " << ac[i].getAccountName() << endl;
            cout << "Account balance: " << ac[i].getAccountBalance() << endl;
            return;
        }
    }

    cout << "\nAccount not found.\n";
}
void updateAccount(Account ac[], int count)
{
    //declaration of variables
    string idNum;
    int choice;
    int amt;


    //allow user to enter values
    cout << "\nEnter your ID number: ";
    cin >> idNum;

    //declaration of for loop
    for (int i = 0; i < count; i++)
    {
        //declaration of nested if statement
        if (ac[i] == idNum)
        {
            
            cout << "1. Deposit\n2. Withdraw\nChoose an option: ";
            cin >> choice;

            if (choice == 1)
            {
                cout << "Enter deposit amount: ";
                cin >> amt;
                ac[i].depositAmount(amt);
            }
            else if (choice == 2)
            {
                cout << "Enter withdrawal amount: ";
                cin >> amt;
                ac[i].withdrawAmount(amt);
            }
            else
            {
                cout << "Invalid choice.\n";
            }

            return;
        }
    }

    cout << "\nAccount not found.\n";
}
