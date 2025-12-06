#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

class Observer {
public:
    virtual ~Observer() = default;
    virtual void Update(float temperature) = 0;
};

class Subject {
public:
    virtual ~Subject() = default;
    virtual void Attach(Observer* o) = 0;
    virtual void Detach(Observer* o) = 0;
    virtual void Notify() = 0;
};

class WeatherStation : public Subject {
private:
    float temperature = 0.0f;
    vector<Observer*> observers;

public:
    void Attach(Observer* o) override {
        observers.push_back(o);
    }

    void Detach(Observer* o) override {
        observers.erase(remove(observers.begin(), observers.end(), o), observers.end());
    }

    void SetTemperature(float t) {
        temperature = t;
        Notify();
    }

    void Notify() override {
        for (auto obs : observers) {
            obs->Update(temperature);
        }
    }
};

class PhoneDisplay : public Observer {
public:
    void Update(float temperature) override {
        cout << "Телефон: температура " << temperature << "°C\n";
    }
};

class WindowDisplay : public Observer {
public:
    void Update(float temperature) override {
        cout << "Віконний дисплей: температура " << temperature << "°C\n";
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    WeatherStation station;

    PhoneDisplay phone;
    WindowDisplay window;

    station.Attach(&phone);
    station.Attach(&window);

    station.SetTemperature(23.5f);
    station.SetTemperature(18.2f);

    station.Detach(&phone);

    station.SetTemperature(12.0f);

    return 0;
}
