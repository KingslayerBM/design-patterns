#include <iostream>
#include <windows.h>
using namespace std;

class State {
public:
    virtual ~State() = default;
    virtual void Handle() = 0;
};

class StandingState : public State {
public:
    void Handle() override {
        cout << "ֳנאגוצü סעמ¿עü.\n";
    }
};

class RunningState : public State {
public:
    void Handle() override {
        cout << "ֳנאגוצü ב³זטעü.\n";
    }
};

class JumpingState : public State {
public:
    void Handle() override {
        cout << "ֳנאגוצü סענטבא÷.\n";
    }
};

class Player {
private:
    State* state;

public:
    Player(State* initial) : state(initial) {}

    void SetState(State* newState) {
        state = newState;
    }

    void Update() {
        state->Handle();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    StandingState standing;
    RunningState running;
    JumpingState jumping;

    Player player(&standing);

    player.Update();

    player.SetState(&running);
    player.Update();

    player.SetState(&jumping);
    player.Update();

    return 0;
}
