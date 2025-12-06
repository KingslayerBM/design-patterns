#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Image {
public:
    virtual ~Image() = default;
    virtual void Display() = 0;
};

class RealImage : public Image {
private:
    string filename;

public:
    RealImage(const string& file) : filename(file) {
        cout << "Завантаження зображення: " << filename << endl;
    }

    void Display() override {
        cout << "Відображення: " << filename << endl;
    }
};

class ProxyImage : public Image {
private:
    string filename;
    RealImage* realImage = nullptr;

public:
    ProxyImage(const string& file) : filename(file) {}

    ~ProxyImage() {
        delete realImage;
    }

    void Display() override {
        if (!realImage) {
            realImage = new RealImage(filename);
        }
        cout << "Через Proxy → ";
        realImage->Display();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Image* img = new ProxyImage("landscape.png");

    cout << "Зображення ще не завантажене...\n";
    img->Display();

    img->Display();

    delete img;
    return 0;
}
