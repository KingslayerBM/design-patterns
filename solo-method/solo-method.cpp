#include <iostream>
#include <windows.h>
using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() {
        cout << "Створення Singleton\n";
    }

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* GetInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void ShowMessage() {
        cout << "Це екземпляр Singleton.\n";
    }
};

Singleton* Singleton::instance = nullptr;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Singleton* s1 = Singleton::GetInstance();
    Singleton* s2 = Singleton::GetInstance();

    s1->ShowMessage();

    cout << "Адреса s1: " << s1 << endl;
    cout << "Адреса s2: " << s2 << endl;

    return 0;
}
