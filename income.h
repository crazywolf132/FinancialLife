#include <iostream>
#include "account.h"

using namespace std;

class Income {
    public:
        Income( ) = default;
        Income(double amt, Account addTo);
        Income(string name, double amt, Account addTo, bool oneTime);
        Income(string name, double amt, Account addTo, bool oneTime, string recurringType);

    private:
        string name = "";
        double amount = 0.00;
        bool oneTime = false;
        string recurringType = "monthly";
        Account addTo = Account( );

};