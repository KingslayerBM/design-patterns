#include <iostream>
#include <windows.h>
using namespace std;

class AttackStrategy {
public:
    virtual ~AttackStrategy() = default;
    virtual void Attack() = 0;
};

class SwordAttack : public AttackStrategy {
public:
    void Attack() override {
        cout << "Атака мечем!\n";
    }
};

class BowAttack : public AttackStrategy {
public:
    void Attack() override {
        cout << "Атака з лука!\n";
    }
};

class MagicAttack : public AttackStrategy {
public:
    void Attack() override {
        cout << "Магічна атака!\n";
    }
};

class Player {
private:
    AttackStrategy* strategy;

public:
    Player(AttackStrategy* s) : strategy(s) {}

    void SetStrategy(AttackStrategy* s) {
        strategy = s;
    }

    void Attack() {
        strategy->Attack();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SwordAttack sword;
    BowAttack bow;
    MagicAttack magic;

    Player player(&sword);
    player.Attack();

    player.SetStrategy(&bow);
    player.Attack();

    player.SetStrategy(&magic);
    player.Attack();

    return 0;
}
