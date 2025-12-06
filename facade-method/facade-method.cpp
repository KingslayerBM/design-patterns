#include <iostream>
#include <windows.h>
using namespace std;

class DVDPlayer {
public:
    void On() { cout << "DVD увімкнено.\n"; }
    void Play() { cout << "Відтворення DVD...\n"; }
    void Off() { cout << "DVD вимкнено.\n"; }
};

class Amplifier {
public:
    void On() { cout << "Підсилювач увімкнено.\n"; }
    void SetVolume(int v) { cout << "Гучність встановлено: " << v << endl; }
    void Off() { cout << "Підсилювач вимкнено.\n"; }
};

class Projector {
public:
    void On() { cout << "Проектор увімкнено.\n"; }
    void Off() { cout << "Проектор вимкнено.\n"; }
};

class HomeTheaterFacade {
private:
    DVDPlayer* dvd;
    Amplifier* amp;
    Projector* projector;

public:
    HomeTheaterFacade(DVDPlayer* d, Amplifier* a, Projector* p)
        : dvd(d), amp(a), projector(p) {
    }

    void WatchMovie() {
        cout << "Підготовка до перегляду фільму...\n";
        projector->On();
        amp->On();
        amp->SetVolume(15);
        dvd->On();
        dvd->Play();
    }

    void EndMovie() {
        cout << "Завершення перегляду...\n";
        dvd->Off();
        amp->Off();
        projector->Off();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DVDPlayer dvd;
    Amplifier amp;
    Projector projector;

    HomeTheaterFacade facade(&dvd, &amp, &projector);

    facade.WatchMovie();
    cout << "-----\n";
    facade.EndMovie();

    return 0;
}
