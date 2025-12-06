#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

class Component {
public:
    virtual ~Component() = default;
    virtual void Operation() const = 0;
};

class Leaf : public Component {
private:
    string name;

public:
    Leaf(const string& n) : name(n) {}

    void Operation() const override {
        cout << "Листок: " << name << endl;
    }
};

class Composite : public Component {
private:
    vector<Component*> children;
    string name;

public:
    Composite(const string& n) : name(n) {}

    void Add(Component* c) {
        children.push_back(c);
    }

    void Remove(Component* c) {
        children.erase(remove(children.begin(), children.end(), c), children.end());
    }

    void Operation() const override {
        cout << "Компонувальник: " << name << endl;
        for (auto child : children) {
            child->Operation();
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Leaf* leaf1 = new Leaf("Лист A");
    Leaf* leaf2 = new Leaf("Лист B");
    Leaf* leaf3 = new Leaf("Лист C");

    Composite* branch1 = new Composite("Гілка 1");
    branch1->Add(leaf1);
    branch1->Add(leaf2);

    Composite* root = new Composite("Корінь");
    root->Add(branch1);
    root->Add(leaf3);

    root->Operation();

    delete leaf1;
    delete leaf2;
    delete leaf3;
    delete branch1;
    delete root;

    return 0;
}
