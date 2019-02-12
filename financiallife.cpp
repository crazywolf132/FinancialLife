#include "financiallife.h"

Finance::Finance( vector< Account > accs) {
    for (auto a : accs) {
        accounts.insert(accounts.begin(), pair< string, Account >(a.getName(), a));
    }
}

Finance::Finance( int d ) : days(d) { }

Finance::Finance( vector< Expense > exp, vector< Income > inc, map< string, Account> accs ) : expenses(exp), incomes(inc), accounts(accs) { }

void Finance::start() {
    for ( int i = 1; i < days; i++) {
        
        for (auto inc : incomes) {
            if (inc.enoughDays(currentDay)) {
                inc.perform();

                totalIncome += inc.getAmount();
            }
        }

        for (auto exp : expenses) {
            if (exp.enoughDays(currentDay)) {
                exp.perform();
                
                totalExpenses += exp.getAmount();
            }
        }

        currentDay++;
    }

    cout << endl;

    for (auto acc: accounts) {
        cout << acc.first << "\t:\t$" << acc.second.getAvaliable() << endl;
        totalNetworth += acc.second.getAvaliable();
    }
    cout << endl;

    cout << "Total Income: $" << totalIncome << endl;
    cout << "Total expenses: $" << totalExpenses << endl << endl;

    cout << "Networth: $" << totalNetworth << endl;

}

void Finance::addAccount( Account acct ) {
    accounts.insert(accounts.begin(), pair< string, Account >(acct.getName(), acct));
}

void Finance::addExpense( Expense exp ) {
    expenses.push_back( exp );
}

void Finance::addIncome( Income inc ) {
    incomes.push_back( inc );
}