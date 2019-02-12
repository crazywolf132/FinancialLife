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
        Finance( int d );
        Finance( vector< Account > accs);
        Finance( vector< Expense > exp, vector< Income > inc, map< string, Account> accs );

        void start();
        void addAccount( Account acct );
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
        double totalIncome = 0.00;
        double totalExpenses = 0.00;

        int days = 0;

        int currentDay = 0;

};