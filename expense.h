#include <iostream>
#include "account.h"

using namespace std;

class Expense {
    public:
        Expense( ) = default;
        Expense(double amt, Account takeFrom);
        Expense(double amt, Account takeFrom, bool oneTime);
        Expense(string name, double amount, Account takeFrom, bool oneTime);
        Expense(string name, double amount, Account takeFrom, bool oneTime, string recurringType);

        bool enoughDays( int currentDay ) const;
        void perform( );

        double getAmount() const;

    private:
        string name = "";
        double amount = 0.00;
        bool oneTime = false;
        string recurringType = "monthly";
        Account takeFrom = Account( );

        int timesRun = 0;
        bool hasRun = false;
};