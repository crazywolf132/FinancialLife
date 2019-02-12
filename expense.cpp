#include "expense.h"

Expense::Expense(double amt, Account tFrom) {
    Expense("", amt, tFrom, false);
}

Expense::Expense(string n, double amt, Account tFrom, bool oT) {
    Expense(n, amt, tFrom, oT, "monthly");
}

Expense::Expense(string n, double amt, Account tFrom, bool oT, string rType) : name(n), amount(amt), takeFrom(tFrom), oneTime(oT), recurringType(rType) { }