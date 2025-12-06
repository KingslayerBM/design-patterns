#include <iostream>
#include <string>
#include <memory>

enum class TransportType {
    TRUCK,
    SHIP,
    PLANE
};

class Transport {
public:
    virtual ~Transport() = default;
    virtual std::string deliver(const std::string& destination) const = 0;
    virtual std::string getInfo() const = 0;
};

class Truck : public Transport {
    double capacity;
public:
    explicit Truck(double cap) : capacity(cap) {}

    std::string deliver(const std::string& destination) const override {
        return "Вантажівка доставляє вантаж по дорозі в " + destination;
    }

    std::string getInfo() const override {
        return "Вантажівк, грузопідйомність: " + std::to_string(capacity) + " тон";
    }
};

class Ship : public Transport {
    double displacement;
public:
    explicit Ship(double disp) : displacement(disp) {}

    std::string deliver(const std::string& destination) const override {
        return "Корабель доставляє вантаж морем в " + destination;
    }

    std::string getInfo() const override {
        return "Корабель, водозаміщення: " + std::to_string(displacement) + " тон";
    }
};

class Plane : public Transport {
    int maxAltitude;
public:
    explicit Plane(int altitude) : maxAltitude(altitude) {}

    std::string deliver(const std::string& destination) const override {
        return "Літак доставляє вантаж повітрям  в " + destination;
    }

    std::string getInfo() const override {
        return "Літак, максимальна висота: " + std::to_string(maxAltitude) + " м";
    }
};

class Logistics {
public:
    virtual ~Logistics() = default;
    virtual std::unique_ptr<Transport> createTransport() const = 0;

    std::string planDelivery(const std::string& destination) const {
        auto transport = createTransport();

        std::string result = "Планування доставки в " + destination + "\n";
        result += "Транспорт: " + transport->getInfo() + "\n";
        result += "Статус: " + transport->deliver(destination);

        return result;
    }
};

class RoadLogistics : public Logistics {
public:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Truck>(20.0);
    }
};

class SeaLogistics : public Logistics {
public:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Ship>(50000.0);
    }
};

class AirLogistics : public Logistics {
public:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Plane>(12000);
    }
};

class LogisticsFactory {
public:
    static std::unique_ptr<Logistics> createLogistics(TransportType type) {
        switch (type) {
        case TransportType::TRUCK:
            return std::make_unique<RoadLogistics>();
        case TransportType::SHIP:
            return std::make_unique<SeaLogistics>();
        case TransportType::PLANE:
            return std::make_unique<AirLogistics>();
        default:
            return nullptr;
        }
    }
};

int main() {
    auto roadLogistics = LogisticsFactory::createLogistics(TransportType::TRUCK);
    std::cout << roadLogistics->planDelivery("Київ") << "\n\n";

    auto seaLogistics = LogisticsFactory::createLogistics(TransportType::SHIP);
    std::cout << seaLogistics->planDelivery("Одеса") << "\n\n";

    auto airLogistics = LogisticsFactory::createLogistics(TransportType::PLANE);
    std::cout << airLogistics->planDelivery("Лондон") << "\n";

    return 0;
}