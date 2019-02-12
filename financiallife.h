#include "account.h"
#include "income.h"
#include "expense.h"

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Finance {
    public:
        Finance( ) = default;

        void start();
        void addAccount( Account acct, string name );
        void addExpense( Expense exp );
        void addIncome( Income inc );

        double getTotalSpent() const;
        double getTotalNetworth() const;

    private:
        map< string, Account > accounts;
        vector< Expense > expenses;
        vector< Income > incomes;

        double totalSpent = 0.00;
        double totalNetworth = 0.00;

        int days = 0;

        int currentDay = 0;

};