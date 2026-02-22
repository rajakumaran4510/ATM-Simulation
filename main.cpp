#include "atm.h"

int main()
{
    ATM atm;
    bool isLoggedIn = 0;
    int choice;
    while (1)
    {
        cout << BOLD GREEN "----------------------------------------\n";
        cout << "W E L C O M E     T O      A T M\n";
        cout << "----------------------------------------\n";
        cout << BG_CYAN "Click 1  ->  Login\n";
        cout << "Click 2  ->  Create Account\n";
        cout << "Click 3  ->  Check Balance\n";
        cout << "Click 4  ->  Deposit Money\n";
        cout << "Click 5  ->  Withrdraw Money\n";
        cout << "Click 6  ->  View Transactions\n";
        cout << "Click 7  ->  Save Data\n";
        cout << "Click 8  ->  Exit\n";
        cout << GREEN "----------------------------------------\n"
             << RESET;
        cout << VIOLET "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            isLoggedIn = atm.login();
            break;
        case 2:
            atm.create_account();
            break;
        case 3:
            if (isLoggedIn)
                atm.check_balance();
            else
                printf("\nLog in first\n\n");
            break;
        case 4:
            if (isLoggedIn)
                atm.deposit_money();
            else
                printf("\nLog in first\n\n");
            break;
        case 5:
            if (isLoggedIn)
                atm.withdraw_money();
            else
                printf("\nLog in first\n\n");
            break;
        case 6:
            if (isLoggedIn)
                atm.view_transactions();
            else
                printf("\nLog in first\n\n");
            break;
        case 7:
            atm.save_data();
            cout << "\nAll datas are saved successfully! ✅\n\n";
            exit(1);
        case 8:
            cout << "\nThank you for using ATM\n\n";
            exit(1);
        default:
            cout << "\nInvalid Choice! Try again\n\n";
        }
    }
}
