#include <iostream>
#include <windows.h>
using namespace std;

class Handler {
protected:
    Handler* next = nullptr;

public:
    virtual ~Handler() = default;

    void SetNext(Handler* n) {
        next = n;
    }

    virtual void Handle(int level) {
        if (next)
            next->Handle(level);
        else
            cout << "Немає обробника для рівня " << level << endl;
    }
};

class LowLevelHandler : public Handler {
public:
    void Handle(int level) override {
        if (level <= 1)
            cout << "LowLevelHandler обробив запит рівня " << level << endl;
        else
            Handler::Handle(level);
    }
};

class MidLevelHandler : public Handler {
public:
    void Handle(int level) override {
        if (level == 2)
            cout << "MidLevelHandler обробив запит рівня " << level << endl;
        else
            Handler::Handle(level);
    }
};

class HighLevelHandler : public Handler {
public:
    void Handle(int level) override {
        if (level >= 3)
            cout << "HighLevelHandler обробив запит рівня " << level << endl;
        else
            Handler::Handle(level);
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Handler* low = new LowLevelHandler();
    Handler* mid = new MidLevelHandler();
    Handler* high = new HighLevelHandler();

    low->SetNext(mid);
    mid->SetNext(high);

    low->Handle(1);
    low->Handle(2);
    low->Handle(5);
    low->Handle(0);

    delete low;
    delete mid;
    delete high;

    return 0;
}
