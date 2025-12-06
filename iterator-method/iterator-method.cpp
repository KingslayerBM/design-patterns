#include <iostream>
#include <windows.h>
using namespace std;

class Iterator {
public:
    virtual ~Iterator() = default;
    virtual bool HasNext() = 0;
    virtual int Next() = 0;
};

class NumberCollection {
private:
    int* data;
    int size;

public:
    NumberCollection(int* arr, int s) : data(arr), size(s) {}

    int GetSize() const { return size; }
    int Get(int index) const { return data[index]; }

    Iterator* CreateIterator();
};

class NumberIterator : public Iterator {
private:
    const NumberCollection& collection;
    int index = 0;

public:
    NumberIterator(const NumberCollection& c) : collection(c) {}

    bool HasNext() override {
        return index < collection.GetSize();
    }

    int Next() override {
        return collection.Get(index++);
    }
};

Iterator* NumberCollection::CreateIterator() {
    return new NumberIterator(*this);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int nums[] = { 10, 20, 30, 40, 50 };
    NumberCollection collection(nums, 5);

    Iterator* it = collection.CreateIterator();

    while (it->HasNext()) {
        cout << it->Next() << endl;
    }

    delete it;
    return 0;
}
