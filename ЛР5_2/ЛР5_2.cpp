#include <iostream>
#include <windows.h>
#include "F:\Учеба\2 курс\ТАиСД\Новая папка\Diapason\Diapason.cpp"

using namespace std;

double InputValidation(double num, string s);
int InputValidation(int num, string s);

int main(){
    setlocale(0, "");
    Diapason D, d;
    int num = 0;
    D.x = InputValidation(D.x, "Введите начало диапазона: ");
    D.y = InputValidation(D.y, "Введите конец  диапазона: ");
    num = InputValidation(num, "Введите на сколько нужно уменьшить координаты X и Y: ");
    int increase, decrease;

    cout << "\nВаш диапазон:"
        << "\n" << D.x << " ... " << D.y
        << "\n\nУнарная операция:\nДлина диапазона: " << D.size()
        << "\n\nОперации приведения типа:\nЦелая часть от X: " << D.Convert(D.x)
        << "\nКоордината Y:" << D.Convert(D.y)
        << "\n\nБинарные операции:\n1.Операция по уменьшению координаты X."
        " Новое значение координаты X = " << D.binar_operation(D, num)
        << "\n2.Операция по уменьшению координаты Y."
        " Новое значение координаты Y = " << D.binar_operation(num, D)
        << "\n3.Операция по проверке пересечения диапазонов.\n";
    D.x = D.binar_operation(D, num);
    D.y = D.binar_operation(num, D);
    d.x = InputValidation(d.x, "Введите начало диапазона 2: ");
    d.y = InputValidation(d.y, "Введите конец  диапазона 2: ");
    cout << "\nВаши диапазоны:"
        << "\n" << D.x << " ... " << D.y
        << "\n" << d.x << " ... " << d.y
        << "\nРезультат: " << D.binar_operation(D,d) << '\n';
}

double InputValidation(double num, string s){
    bool b = false;
    do {
        b = false;
        cout << s;
        if (!(cin >> num)) {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "Ошибка ввода!\n";
            b = true;
        }
    } while (b);
    return num;
}

int InputValidation(int num, string s) {
    bool b = false;
    do {
        b = false;
        cout << s;
        if (!(cin >> num)) {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "Ошибка ввода!\n";
            b = true;
        }
    } while (b);
    return num;
}