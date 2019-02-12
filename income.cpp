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