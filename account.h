#include <iostream>

using namespace std;

class Account {
    public:
        Account( ) = default;
        Account(string name);
        Account(string name, double amount);

        string getName() const;

        double getAvaliable() const;

        void minusAmount(double amt);
        void addAmount(double amt);

    private:
        string name = "";
        double amount = 0.00;

};