#include <iostream>
#include "F:\Учеба\2 курс\ТАиСД\Новая папка\Diapason\Diapason.cpp"

using namespace std;

bool intersection(Diapason d1, Diapason d2);
double InputValidation(double num, string s);

int main()
{
    setlocale(0, "");
    Diapason d1, d2;
    d1.x = InputValidation(d1.x, "Введите начало диапазона 1: ");
    d1.y = InputValidation(d1.y, "Введите конец диапазона  1: ");
    d2.x = InputValidation(d2.x, "Введите начало диапазона 2: ");
    d2.y = InputValidation(d2.y, "Введите конец диапазона  2: ");
    cout << "\nВаши диапазоны:" 
        << "\n" << d1.x << " ... " << d1.y
        << "\n" << d2.x << " ... " << d2.y
        << "\n\nРезультаты проверки на совпадение диапазонов через метод: " << d1.intersection(d1, d2)
        << "\nРезультаты проверки на совпадение диапазонов через функцию: " << intersection(d1, d2)
        << "\n\nВсего было создано " << Diapason::getCounter() << " объектов класа\n";
}

bool intersection(Diapason d1, Diapason d2) {
    bool b = true;
    double x1, y1, x2, y2;
    x1 = min(d1.x, d1.y);
    y1 = max(d1.x, d1.y);
    x2 = min(d2.x, d2.y);
    y2 = max(d2.x, d2.y);
    if (x1 < x2 && y1 < x2)
    {
        b = false;
    }
    else
    {
        if (x2 < x1 && y2 < x1)
        {
            b = false;
        }
    }
    return b;
}

double InputValidation(double num, string s)
{
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