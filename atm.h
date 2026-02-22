#ifndef ATM_H
#define ATM_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class ATM
{
private:
    string username;
    string pin;
    long long balance;

public:
    ATM();
    bool login();
    void create_account();
    void check_balance();
    void deposit_money();
    void withdraw_money();
    void add_transactions(string , long long);
    void view_transactions();
    void save_data();
};

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define VIOLET "\x1b[35m"
#define BR_RED  "\033[91m"
#define BG_GREEN  "\033[92m"
#define BG_YELLOW  "\033[93m"
#define BG_BLUE    "\033[94m"
#define BG_MAGENTA "\033[95m"
#define BG_CYAN    "\033[96m"
#define BG_WHITE   "\033[97m"
#define BOLD      "\033[1m"
#define DIM       "\033[2m"
#define ITALIC    "\033[3m"
#define UNDERLINE "\033[4m"
#define BLINK     "\033[5m"
#define REVERSE   "\033[7m"
#define HIDDEN    "\033[8m"
#define RESET "\x1b[0m"

#endif
