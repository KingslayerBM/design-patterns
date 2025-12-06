#include <iostream>
#include <string>
using namespace std;

class Prototype {
public:
    virtual ~Prototype() = default;
    virtual Prototype* Clone() const = 0;
    virtual void Show() const = 0;
};

class Car : public Prototype {
private:
    string model;
    int year;

public:
    Car(string m, int y) : model(m), year(y) {}

    Prototype* Clone() const override {
        return new Car(*this);
    }

    void Show() const override {
        cout << "Авто: " << model << ", рік: " << year << endl;
    }
};

class Robot : public Prototype {
private:
    string name;
    int power;

public:
    Robot(string n, int p) : name(n), power(p) {}

    Prototype* Clone() const override {
        return new Robot(*this);
    }

    void Show() const override {
        cout << "Робот: " << name << ", потужність: " << power << endl;
    }
};

int main() {
    Car originalCar("BMW", 2020);
    Robot originalRobot("Atlas", 95);

    Prototype* clonedCar = originalCar.Clone();
    Prototype* clonedRobot = originalRobot.Clone();

    clonedCar->Show();
    clonedRobot->Show();

    delete clonedCar;
    delete clonedRobot;

    return 0;
}
