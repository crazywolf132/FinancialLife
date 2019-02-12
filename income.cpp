#include "income.h"

Income::Income(double amt, Account aT) {
    Income("", amt, aT, true);
}

Income::Income(double amt, Account aT, bool oT) {
    Income("", amt, aT, oT);
} 

Income::Income(string n, double amt, Account aT, bool oT) {
    Income(n, amt, aT, oT, "monthly");
}

Income::Income(string n, double amt, Account aT, bool oT, string rT) : name(n), amount(amt), addTo(aT), oneTime(oT), recurringType(rT) { }

void Income::calcDays( ) {

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

bool Income::enoughDays( int currentDay ) {

    calcDays();

    if (oneTime && !hasRun) {
        return true;
    } else if (oneTime && hasRun) {
        return false;
    }

    return currentDay % timesRun == 0;

}

void Income::perform( ) {

    if (oneTime) {
        hasRun = false;
    }

    addTo.addAmount(amount);
}