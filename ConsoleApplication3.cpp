#include <iostream>
#include <typeinfo>
using namespace std;


class Printable {
public:
    virtual void print() = NULL;
};
class Instrument {
public:
    const string KEY = "До мажор";
    virtual void play() = NULL;
};
class Guitar : public Instrument {
private:
    int stringCount = 6;
public:
    void play() override {
        printf("Igraet gitara s %i strunami\n", stringCount);
    }
};
class Drum : public Instrument {
private:
    int size = 10;
public:
    void play() override {
        printf("Igraet baraban razmerom %i cm\n", size);
    }
};
class Trumpet : public Instrument {
private:
    int diameter = 1;
public:
    void play() override {
        printf("Igraet truba razmerom %i m\n", diameter);
    }
};
class Book : public Printable {
public:
    void print() override {
        cout << "This is Book\n";
    }
    void static printBook(Printable *print[], int printLenght) {
        printLenght--;
        while (printLenght>=0)
        {
            if (typeid(*print[printLenght]) == typeid(Book))
            {
                print[printLenght]->print();
            }
            printLenght--;
        }
    }
};
class Magazine : public Printable {
public:
    void print() override {
        cout << "This is Magazine\n";
    }
    void static printMagazines(Printable* print[], int printLenght) {
        printLenght--;
        while (printLenght >= 0)
        {
            if (typeid(*print[printLenght]) == typeid(Magazine))
            {
                print[printLenght]->print();
            }
            printLenght--;
        }
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
    Magazine::printMagazines(printables,4);
    Book::printBook(printables,4);
    Guitar guitar = Guitar();
    Drum drum = Drum();
    Trumpet trumpet = Trumpet();
    Instrument* instruments[3];
    instruments[0] = &guitar;
    instruments[1] = &drum;
    instruments[2] = &trumpet;
    for (int i = 0; i < 3; i++)
    {
        instruments[i]->play();
    }
}

