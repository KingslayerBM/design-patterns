#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class House {
public:
    string walls;
    string roof;
    string windows;

    void Show() const {
        cout << "Компоненти будинку:\n";
        cout << " Стіни: " << walls << endl;
        cout << " Дах: " << roof << endl;
        cout << " Вікна: " << windows << endl;
    }
};

class HouseBuilder {
public:
    virtual ~HouseBuilder() = default;
    virtual void BuildWalls() = 0;
    virtual void BuildRoof() = 0;
    virtual void BuildWindows() = 0;
    virtual House* GetHouse() = 0;
};

class WoodenHouseBuilder : public HouseBuilder {
private:
    House* house;

public:
    WoodenHouseBuilder() {
        house = new House();
    }

    void BuildWalls() override {
        house->walls = "Дерев'яні стіни";
    }

    void BuildRoof() override {
        house->roof = "Дерев'яний дах";
    }

    void BuildWindows() override {
        house->windows = "Скляні вікна";
    }

    House* GetHouse() override {
        return house;
    }
};


class Director {
private:
    HouseBuilder* builder;

public:
    void SetBuilder(HouseBuilder* b) {
        builder = b;
    }

    House* BuildHouse() {
        builder->BuildWalls();
        builder->BuildRoof();
        builder->BuildWindows();
        return builder->GetHouse();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Director director;
    WoodenHouseBuilder woodenBuilder;

    director.SetBuilder(&woodenBuilder);
    House* house = director.BuildHouse();

    house->Show();

    delete house;
    return 0;
}
