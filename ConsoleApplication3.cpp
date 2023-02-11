#include <iostream>
using namespace std;


class Printable {
public:
    virtual void print(){

    }
};
class Instrument {
public:
    virtual void play() {

    }
};
class Book : public Printable {
public:
    Book() {

    }
    void print() override {
        cout << "This is Book\n";
    }
    void static printBook(Printable *print[], int printLenght) {
        while (printLenght>0)
        {
            cout << print[printLenght-1];
            printLenght--;
        }
    }
};
class Magazine : public Printable {
public:
    void print() override {
        cout << "This is Magazine\n";
    }
    void static printMagazine() {

    }
};

int main()
{
    Printable* printables[4];
    Book firstBook = Book();
    Magazine firstMagazine = Magazine();
    Book secondBook = Book();
    Magazine secondMagazine = Magazine();
    printables[0] = &firstBook;
    printables[1] = &firstMagazine;
    printables[2] = &secondBook;
    printables[3] = &secondMagazine;
    for (int i = 0; i < 4; i++)
    {
        printables[i]->print();
    }
}