#include <iostream>
#include <windows.h>
using namespace std;

class Device {
public:
    virtual ~Device() = default;
    virtual void On() = 0;
    virtual void Off() = 0;
    virtual void SetVolume(int value) = 0;
};

class TV : public Device {
public:
    void On() override { cout << "TV увімкнено.\n"; }
    void Off() override { cout << "TV вимкнено.\n"; }
    void SetVolume(int value) override { cout << "Гучність TV: " << value << endl; }
};

class Radio : public Device {
public:
    void On() override { cout << "Radio увімкнено.\n"; }
    void Off() override { cout << "Radio вимкнено.\n"; }
    void SetVolume(int value) override { cout << "Гучність Radio: " << value << endl; }
};

class RemoteControl {
protected:
    Device* device;

public:
    RemoteControl(Device* d) : device(d) {}

    virtual void TurnOn() { device->On(); }
    virtual void TurnOff() { device->Off(); }
    virtual void Volume(int value) { device->SetVolume(value); }
};

class AdvancedRemote : public RemoteControl {
public:
    AdvancedRemote(Device* d) : RemoteControl(d) {}

    void Mute() {
        cout << "mute\n";
        device->SetVolume(0);
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Device* tv = new TV();
    Device* radio = new Radio();

    RemoteControl remote(tv);
    remote.TurnOn();
    remote.Volume(15);
    remote.TurnOff();

    cout << "-------\n";

    AdvancedRemote advancedRemote(radio);
    advancedRemote.TurnOn();
    advancedRemote.Mute();
    advancedRemote.TurnOff();

    delete tv;
    delete radio;

    return 0;
}
