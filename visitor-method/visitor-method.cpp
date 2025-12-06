#include <iostream>
#include <windows.h>
using namespace std;

class Circle;
class Rectangle;

class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void Visit(Circle* element) = 0;
    virtual void Visit(Rectangle* element) = 0;
};

class Element {
public:
    virtual ~Element() = default;
    virtual void Accept(Visitor* visitor) = 0;
};

class Circle : public Element {
public:
    void Accept(Visitor* visitor) override {
        visitor->Visit(this);
    }
};

class Rectangle : public Element {
public:
    void Accept(Visitor* visitor) override {
        visitor->Visit(this);
    }
};

class DrawVisitor : public Visitor {
public:
    void Visit(Circle* element) override {
        cout << "Малюємо коло.\n";
    }

    void Visit(Rectangle* element) override {
        cout << "Малюємо прямокутник.\n";
    }
};

class AreaVisitor : public Visitor {
public:
    void Visit(Circle* element) override {
        cout << "Обчислюємо площу кола.\n";
    }

    void Visit(Rectangle* element) override {
        cout << "Обчислюємо площу прямокутника.\n";
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Element* elements[] = { new Circle(), new Rectangle() };

    DrawVisitor draw;
    AreaVisitor area;

    cout << "=== Малювання ===\n";
    for (auto e : elements)
        e->Accept(&draw);

    cout << "\n=== Обчислення площ ===\n";
    for (auto e : elements)
        e->Accept(&area);

    delete elements[0];
    delete elements[1];

    return 0;
}
