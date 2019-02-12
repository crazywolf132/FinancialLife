#include "account.h"

Account::Account(string n) : name(n) { }

Account::Account(string n, double amt) : name(n), amount(amt) { }

void Account::minusAmount(double amt) {
    amount -= amt;
}

void Account::addAmount(double amt) {
    amount += amt;
}

string Account::getName() const {
    return name;
}