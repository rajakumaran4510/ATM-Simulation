#include "atm.h"

ATM::ATM()
{
    balance = 0;
}

void ATM::create_account()
{
    ofstream file("users.txt", ios::app);
    string newuser, newpin;
    long long initial_balance;
    cout << VIOLET "\nEnter New Username: ";
    cin >> newuser;
    cout << "Enter New PIN: ";
    cin >> newpin;
    cout << GREEN "\nEnter Initial Deposit: ";
    cin >> initial_balance;

    if (initial_balance < 0)
    {
        cout << RED "\nInvalid amount! ❌\n\n";
        return;
    }
    file << newuser << " " << newpin << " " << initial_balance << endl;
    file.close();
    cout << GREEN "\nAccount Created Successfully! ✅\n";
}
bool ATM::login()
{
    int attempts = 3;
    while (attempts > 0)
    {
        cout << VIOLET "\nEnter Username: ";
        cin >> username;
        cout << "Enter PIN: ";
        cin >> pin;
        ifstream file("users.txt");
        if (!file)
        {
            cout << RED << "Error opening file! ❌\n";
            return 0;
        }
        string user, pass;
        long long bal;
        bool flag = 0;
        while (file >> user >> pass >> bal)
        {
            if (user == username && pass == pin)
            {
                balance = bal;
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            cout << GREEN "\nLog In Successfull! ✅\n\n";
            return 1;
        }
        else
        {
            attempts--;
            cout << RED << "\nLogin Failed! ❌ Attempts left: " << attempts << "\n\n";
        }
    }
    cout << RED << "\nToo many failed attempts! ❌ Access denied.\n\n";
    return 0;
}

void ATM::add_transactions(string type, long long amount)
{
    ofstream file("transactions.txt", ios::app);
    file << username << " " << type << " " << amount << " " << "Balance: " << balance << endl;
    cout << "\n";
    file.close();
}

void ATM::check_balance()
{
    string enteredpin;
    int attempts = 3;
    while (attempts--)
    {
        cout << VIOLET << "\nEnter the pin to check your balance (" << attempts + 1 << " attempts left): ";
        cin >> enteredpin;
        if (enteredpin == pin)
        {
            cout << GREEN "\nYour balance : ₹ " << balance << endl
                 << endl;
            break;
        }
        else
            cout << RED "\nIncorrect Pin! Try again ❌\n"
                 << endl;
    }
    if (attempts < 0)
    {
        cout << RED << "Too many wrong attempts! ❌\n"
             << endl;
    }
}

void ATM::deposit_money()
{
    long long amount;
    cout << VIOLET "\nEnter the amount to deposit: ";
    cin >> amount;
    if (amount > 0)
    {
        balance += amount;
        save_data();
        add_transactions("DEPOSIT", amount);
        cout << GREEN "\nDeposit Successfull! ✅\n\n";
    }
    else
    {
        cout << RED "\nInvalid amount! ❌\n\n";
    }
}

void ATM::withdraw_money()
{
    long long amount;
    string enteredpin;
    int attempts = 3;
    while (attempts--)
    {
        cout << VIOLET << "\nEnter the pin to Withdraw amount (" << attempts + 1 << " attempts left): ";
        cin >> enteredpin;
        if (enteredpin == pin)
        {
            cout << VIOLET "\nEnter the amount to Withdraw: ";
            cin >> amount;
            if (amount > 0 && amount <= balance)
            {
                balance -= amount;
                save_data();
                add_transactions("WITHDRAW", amount);
                cout << GREEN "\nWithdraw Successfull! ✅\n\n";
                return;
            }
            else if (amount < 0)
            {
                cout << RED "\nAmount should be greater than Zero! \n\n";
            }
            else
                cout << RED "\nInsufficient Balance! ❌\n\n";
        }
        else
        {
            cout << RED "\nIncorrect Pin! ❌\n";
        }
    }
    if (attempts < 0)
    {
        cout << RED << "\nToo many wrong attempts! ❌\n"
             << endl;
    }
}

void ATM::view_transactions()
{
    ifstream file("transactions.txt");

    if (!file)
    {
        cout << RED << "\nNo transaction history found! ❌\n\n";
        return;
    }
    string line;
    cout <<"-----------------------------------";
    cout << GREEN "\n    Transaction History    \n" RESET;
    cout << YELLOW "-----------------------------------\n";

    while (getline(file, line))
    {
        if (line.find(username) == 0)
        {
            cout << line << endl;
        }
    }
    cout <<"-----------------------------------\n";
    file.close();
}

void ATM::save_data()
{
    ifstream file("users.txt");
    ofstream temp("temp.txt");

    if (!file || !temp)
    {
        cout << RED "File error while saving data! ❌\n";
        return;
    }

    string user, pass;
    long long bal;

    while (file >> user >> pass >> bal)
    {
        if (user == username && pass == pin)
        {
            temp << username << " " << pin << " " << balance << endl;
        }
        else
        {
            temp << user << " " << pass << " " << bal << endl;
        }
    }

    file.close();
    temp.close();

    remove("users.txt");
    rename("temp.txt", "users.txt");
}
