#include <iostream>
#include "account.h"

using namespace std;

class Income {
    public:
        Income( ) = default;
        Income(double amt, Account addTo);
        Income(double amt, Account addTo, bool oneTime);
        Income(string name, double amt, Account addTo, bool oneTime);
        Income(string name, double amt, Account addTo, bool oneTime, string recurringType);

        bool enoughDays( int currentDay ) const;
        void perform( );

        double getAmount() const;

      private:
        string name = "";
        double amount = 0.00;
        bool oneTime = false;
        string recurringType = "monthly";
        Account addTo = Account( );
        
        int timesRun = 0;
        bool hasRun = false;

};