#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

class Mediator {
public:
    virtual ~Mediator() = default;
    virtual void Send(const string& message, const string& sender) = 0;
};

class User {
private:
    string name;
    Mediator* mediator;

public:
    User(const string& n, Mediator* m) : name(n), mediator(m) {}

    string GetName() const { return name; }

    void Send(const string& msg) {
        mediator->Send(msg, name);
    }

    void Receive(const string& msg, const string& from) {
        cout << name << " отримав від " << from << ": " << msg << endl;
    }
};

class ChatMediator : public Mediator {
private:
    vector<User*> users;

public:
    void AddUser(User* user) {
        users.push_back(user);
    }

    void Send(const string& message, const string& sender) override {
        for (auto user : users) {
            if (user->GetName() != sender)
                user->Receive(message, sender);
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ChatMediator chat;

    User* alice = new User("Аліса", &chat);
    User* bob = new User("Боб", &chat);
    User* carl = new User("Карл", &chat);

    chat.AddUser(alice);
    chat.AddUser(bob);
    chat.AddUser(carl);

    alice->Send("Привіт усім!");
    bob->Send("Вітаю, Алісо!");

    delete alice;
    delete bob;
    delete carl;

    return 0;
}
