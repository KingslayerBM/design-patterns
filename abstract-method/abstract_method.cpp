#include <iostream>
#include <memory>
#include <windows.h>
using namespace std;

enum class OSType {
    WINDOWS,
    MACOS,
    LINUX 
};
unique_ptr<GUIFactory> createFactory(OSType osType) {
    switch (osType) {
    case OSType::WINDOWS:
        return make_unique<WindowsFactory>();
    case OSType::MACOS:
        return make_unique<MacOSFactory>();
    default:
        throw std::runtime_error("Непідтримуваний тип ОС");
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    auto factory = createFactory(OSType::MACOS);
    auto app = make_unique<Application>(std::move(factory));
    app->renderUI();

    return 0;
}