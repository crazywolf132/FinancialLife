#include "expense.h"

Expense::Expense(double amt, Account tFrom) {
    Expense("", amt, tFrom, false);
}

Expense::Expense(double amt, Account tFrom, bool oT) {
    Expense("", amt, tFrom, oT);
}

Expense::Expense(string n, double amt, Account tFrom, bool oT) {
    Expense(n, amt, tFrom, oT, "monthly");
}

Expense::Expense(string n, double amt, Account tFrom, bool oT, string rType) : name(n), amount(amt), takeFrom(tFrom), oneTime(oT), recurringType(rType) { }

void Expense::calcDays( ) {

    if (recurringType == "biyearly") {
        timesRun = 730;
    } else if (recurringType == "yearly") {
        timesRun = 365;
    } else if (recurringType == "bimonthly") {
        timesRun = 60;
    } else if (recurringType == "monthly") {
        timesRun = 30;
    } else if (recurringType == "biweekly") {
        timesRun = 14;
    } else if (recurringType == "weekly") {
        timesRun = 7;
    } else if (recurringType == "daily") {
        timesRun = 1;
    } else {
        timesRun = 30;
    }
        
}

bool Expense::enoughDays( int currentDay ) {

    calcDays();

    if (oneTime && !hasRun) {
        return true;
    } else if (oneTime && hasRun) {
        return false;
    }

    return currentDay % timesRun == 0;

}

void Expense::perform( ) {

    if (oneTime) {
        hasRun = false;
    }

    takeFrom.minusAmount(amount);

}