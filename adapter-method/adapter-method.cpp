#include <iostream>
#include <windows.h>
using namespace std;

class Target {
public:
    virtual ~Target() = default;
    virtual void Request() const {
        cout << "Target: стандартний запит.\n";
    }
};

class Adaptee {
public:
    void SpecificRequest() const {
        cout << "Adaptee: специфічний запит.\n";
    }
};

class Adapter : public Target {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* a) : adaptee(a) {}

    void Request() const override {
        cout << "Adapter: перетворюю запит...\n";
        adaptee->SpecificRequest();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Adaptee* adaptee = new Adaptee();
    Target* adapter = new Adapter(adaptee);

    adapter->Request();

    delete adapter;
    delete adaptee;

    return 0;
}
