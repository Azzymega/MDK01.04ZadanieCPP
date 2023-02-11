// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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
    Printable *print[4];
    Book book = Book();
    Magazine magazine = Magazine();
    print[0] = &book;
    print[1] = &magazine;
    print[0]->print();
    print[1]->print();
    *print[0] = *print[1];
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
