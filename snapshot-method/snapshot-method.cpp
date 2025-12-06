#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

class Memento {
private:
    string state;

public:
    Memento(const string& s) : state(s) {}
    string GetState() const { return state; }
};

class TextEditor {
private:
    string text;

public:
    void Type(const string& words) {
        text += words;
    }

    void Show() const {
        cout << "Текст: " << text << endl;
    }

    Memento Save() const {
        return Memento(text);
    }

    void Restore(const Memento& m) {
        text = m.GetState();
    }
};

class History {
private:
    vector<Memento> history;

public:
    void Push(const Memento& m) {
        history.push_back(m);
    }

    Memento Pop() {
        Memento m = history.back();
        history.pop_back();
        return m;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    TextEditor editor;
    History history;

    editor.Type("Привіт, ");
    history.Push(editor.Save());

    editor.Type("світ!");
    editor.Show();

    editor.Restore(history.Pop());
    editor.Show();

    return 0;
}
