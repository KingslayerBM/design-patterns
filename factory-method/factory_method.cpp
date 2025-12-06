#include <iostream>
#include <string>
#include <memory>
#include <windows.h>
using namespace std;

enum class TransportType {
    TRUCK,
    SHIP,
    PLANE
};

class Transport {
public:
    virtual ~Transport() = default;
    virtual string deliver(const string& destination) const = 0;
    virtual string getInfo() const = 0;
};

class Truck : public Transport {
    double capacity;
public:
    explicit Truck(double cap) : capacity(cap) {}

    string deliver(const string& destination) const override {
        return "Вантажівка доставляє вантаж по дорозі в " + destination;
    }

    string getInfo() const override {
        return "Вантажівк, грузопідйомність: " + to_string(capacity) + " тон";
    }
};

class Ship : public Transport {
    double displacement;
public:
    explicit Ship(double disp) : displacement(disp) {}

    string deliver(const string& destination) const override {
        return "Корабель доставляє вантаж морем в " + destination;
    }

    string getInfo() const override {
        return "Корабель, водозаміщення: " + to_string(displacement) + " тон";
    }
};

class Plane : public Transport {
    int maxAltitude;
public:
    explicit Plane(int altitude) : maxAltitude(altitude) {}

    string deliver(const string& destination) const override {
        return "Літак доставляє вантаж повітрям  в " + destination;
    }

    string getInfo() const override {
        return "Літак, максимальна висота: " + to_string(maxAltitude) + " м";
    }
};

class Logistics {
public:
    virtual ~Logistics() = default;
    virtual unique_ptr<Transport> createTransport() const = 0;

    string planDelivery(const string& destination) const {
        auto transport = createTransport();

        string result = "Планування доставки в " + destination + "\n";
        result += "Транспорт: " + transport->getInfo() + "\n";
        result += "Статус: " + transport->deliver(destination);

        return result;
    }
};

class RoadLogistics : public Logistics {
public:
    unique_ptr<Transport> createTransport() const override {
        return make_unique<Truck>(20.0);
    }
};

class SeaLogistics : public Logistics {
public:
    unique_ptr<Transport> createTransport() const override {
        return make_unique<Ship>(50000.0);
    }
};

class AirLogistics : public Logistics {
public:
    unique_ptr<Transport> createTransport() const override {
        return make_unique<Plane>(12000);
    }
};

class LogisticsFactory {
public:
    static unique_ptr<Logistics> createLogistics(TransportType type) {
        switch (type) {
        case TransportType::TRUCK:
            return make_unique<RoadLogistics>();
        case TransportType::SHIP:
            return make_unique<SeaLogistics>();
        case TransportType::PLANE:
            return make_unique<AirLogistics>();
        default:
            return nullptr;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    auto roadLogistics = LogisticsFactory::createLogistics(TransportType::TRUCK);
    cout << roadLogistics->planDelivery("Київ") << "\n\n";

    auto seaLogistics = LogisticsFactory::createLogistics(TransportType::SHIP);
    cout << seaLogistics->planDelivery("Одеса") << "\n\n";

    auto airLogistics = LogisticsFactory::createLogistics(TransportType::PLANE);
    cout << airLogistics->planDelivery("Лондон") << "\n";

    return 0;
}