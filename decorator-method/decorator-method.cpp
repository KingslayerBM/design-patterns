#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Coffee {
public:
    virtual ~Coffee() = default;
    virtual string GetDescription() const = 0;
    virtual double GetCost() const = 0;
};

class SimpleCoffee : public Coffee {
public:
    string GetDescription() const override {
        return " ава";
    }
    double GetCost() const override {
        return 20.0;
    }
};

class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;

public:
    CoffeeDecorator(Coffee* c) : coffee(c) {}
};

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* c) : CoffeeDecorator(c) {}

    string GetDescription() const override {
        return coffee->GetDescription() + ", молоко";
    }

    double GetCost() const override {
        return coffee->GetCost() + 5.0;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* c) : CoffeeDecorator(c) {}

    string GetDescription() const override {
        return coffee->GetDescription() + ", цукор";
    }

    double GetCost() const override {
        return coffee->GetCost() + 2.0;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Coffee* coffee = new SimpleCoffee();
    cout << coffee->GetDescription() << " Ч " << coffee->GetCost() << " грн\n";

    coffee = new MilkDecorator(coffee);
    coffee = new SugarDecorator(coffee);

    cout << coffee->GetDescription() << " Ч " << coffee->GetCost() << " грн\n";

    delete coffee;
    return 0;
}
