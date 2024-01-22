#include <iostream>
#include "F:\Учеба\2 курс\ТАиСД\Новая папка\Diapason\DiapasonArray.cpp"

using namespace std;

DiapasonArray Arr1(int size);
DiapasonArray ArrRand(int size, int min, int max);

int main()
{
    srand(time(0));
    setlocale(0, "");

    Diapason D;
    int index, size, choice, max, min;
    DiapasonArray arr;

    cout << "Введите размер массива: ";
    cin >> size;

    cout << "Выберите тип заполнения массива:\n"
        "1. Вручную\n"
        "2. Рандомными числами в выбраном диапазоне\n"
        "Ваш выбор: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        arr = Arr1(size);
        break;
    case 2:
        cout << "Введите желаемый, минимально  возможный элемент: ";
        cin >> min;
        cout << "Введите желаемый, максимально возможный элемент: ";
        cin >> max;
        arr = ArrRand(size, min, max);
        break;
    default:
        return 0;
        break;
    }
    cout << "\nВаш массив:\n";
    arr.ArrayOut();

    cout << "\nВведите к какой элемент вы хотите посмотреть: ";
    cin >> index;
    D = arr.NumOut(index);
    cout << "Ваш элемент: " << D.x << " ... " << D.y;

    cout << "\n\nМаксимальный элемент в массиве: " << arr.MaxNum();
    cout << "\nСтрока массива с максимальным элементом: "
        <<  arr.Max_Element().x << " ... " << arr.Max_Element().y;
    cout << "\n\nКоличество созданных объектов класса: "
        << DiapasonArray::GetCount() << "\n";
}

DiapasonArray Arr1(int size)
{
    DiapasonArray arr(size);
    return arr;
}

DiapasonArray ArrRand(int size, int min, int max)
{
    DiapasonArray arr(size, min, max);
    return arr;
}