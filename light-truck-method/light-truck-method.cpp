#include <iostream>
#include <string>
#include <unordered_map>
#include <windows.h>
using namespace std;

class TreeType {
private:
    string name;
    string color;
    string texture;

public:
    TreeType(const string& n, const string& c, const string& t)
        : name(n), color(c), texture(t) {
    }

    void Draw(int x, int y) const {
        cout << "Малюю дерево [" << name << ", " << color
            << ", " << texture << "] у точці (" << x << ", " << y << ")\n";
    }
};

class TreeFactory {
private:
    unordered_map<string, TreeType*> treeTypes;

public:
    ~TreeFactory() {
        for (auto& p : treeTypes) delete p.second;
    }

    TreeType* GetTreeType(const string& name, const string& color, const string& texture) {
        string key = name + color + texture;

        if (treeTypes.find(key) == treeTypes.end()) {
            treeTypes[key] = new TreeType(name, color, texture);
        }

        return treeTypes[key];
    }
};

class Tree {
private:
    int x, y;
    TreeType* type;

public:
    Tree(int xPos, int yPos, TreeType* t)
        : x(xPos), y(yPos), type(t) {
    }

    void Draw() const {
        type->Draw(x, y);
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    TreeFactory factory;

    Tree* trees[5];
    trees[0] = new Tree(10, 20, factory.GetTreeType("Дуб", "Зелений", "Грубий"));
    trees[1] = new Tree(15, 25, factory.GetTreeType("Дуб", "Зелений", "Грубий"));
    trees[2] = new Tree(30, 40, factory.GetTreeType("Сосна", "Темно-зелений", "Гладкий"));
    trees[3] = new Tree(35, 45, factory.GetTreeType("Сосна", "Темно-зелений", "Гладкий"));
    trees[4] = new Tree(50, 60, factory.GetTreeType("Дуб", "Зелений", "Грубий"));

    for (int i = 0; i < 5; i++)
        trees[i]->Draw();

    for (int i = 0; i < 5; i++)
        delete trees[i];

    return 0;
}
