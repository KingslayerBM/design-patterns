#include <iostream>
#include <windows.h>
using namespace std;

class Beverage {
public:
    void Prepare() {
        BoilWater();
        Brew();
        PourInCup();
        AddExtras();
    }

    virtual ~Beverage() = default;

protected:
    void BoilWater() {
        cout << "Кип'ятимо воду.\n";
    }

    void PourInCup() {
        cout << "Наливаємо в чашку.\n";
    }

    virtual void Brew() = 0;
    virtual void AddExtras() = 0;
};

class Tea : public Beverage {
protected:
    void Brew() override {
        cout << "Заварюємо чай.\n";
    }

    void AddExtras() override {
        cout << "Додаємо лимон.\n";
    }
};

class Coffee : public Beverage {
protected:
    void Brew() override {
        cout << "Заварюємо каву.\n";
    }

    void AddExtras() override {
        cout << "Додаємо молоко та цукор.\n";
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Tea tea;
    Coffee coffee;

    cout << "=== Чай ===\n";
    tea.Prepare();

    cout << "\n=== Кава ===\n";
    coffee.Prepare();

    return 0;
}
