#include <iostream>
#include <windows.h>
using namespace std;

class Command {
public:
    virtual ~Command() = default;
    virtual void Execute() = 0;
};

class Light {
public:
    void On() {
        cout << "Лампу увімкнено.\n";
    }

    void Off() {
        cout << "Лампу вимкнено.\n";
    }
};

class LightOnCommand : public Command {
private:
    Light* light;

public:
    LightOnCommand(Light* l) : light(l) {}

    void Execute() override {
        light->On();
    }
};

class LightOffCommand : public Command {
private:
    Light* light;

public:
    LightOffCommand(Light* l) : light(l) {}

    void Execute() override {
        light->Off();
    }
};

class RemoteControl {
private:
    Command* command;

public:
    void SetCommand(Command* c) {
        command = c;
    }

    void PressButton() {
        if (command)
            command->Execute();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Light lamp;

    Command* lightOn = new LightOnCommand(&lamp);
    Command* lightOff = new LightOffCommand(&lamp);

    RemoteControl remote;

    remote.SetCommand(lightOn);
    remote.PressButton();

    remote.SetCommand(lightOff);
    remote.PressButton();

    delete lightOn;
    delete lightOff;

    return 0;
}
