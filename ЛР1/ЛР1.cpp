#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <vector>

using namespace std;

int InputValidation(int num, string s);
int PositiveInputValidation(int num, string s);

int main() 
{
    srand(time(0));
    setlocale(0, "");
    bool b = false;
    int choice1=0, choice2=0, n = 1, m = 1, NewNum = 0, DelNum = 0, ArrLenght = 0, NewSting = 0, NumString = 0;
    int* arr1 = new int[1];
    int** arr2 = new int*[1];
    vector<vector<int>>arr3;

    do
    {
        choice1 = 0;
        // Меню
        cout << "Список действий с массивами:\n"
            "1. Одномерный массив. Добавление элемента в начало массива.\n"
            "2. Двумерный массив. Удаление строки.\n"
            "3. Рваный массив. Добавление строк.\n"
            "4. Выход из программы\n";
        choice1 = InputValidation(choice1, "\nВыберите действие: ");

        switch (choice1)
        {
        case 1:
            // Одномерный массив. Добавление элемента в начало массива
            do
            {
                b = true;
                n = PositiveInputValidation(n,"\nВведите количество чисел в одномерном массиве: ");
               // n = IntInputValidation("\nВведите количество чисел в одномерном массиве: ");
                arr1 = new int[n];
                cout << "\nВыберите тип заполнения массива:\n"
                    "1. Вручную.\n"
                    "2. Рандомно.\n";
                choice2 = InputValidation(choice2, "\nВаш выбор: ");
                if (choice2==1)
                {
                    // Заполнение вручную
                    cout << "\nЗаполнение массива целыми числами:\n";
                    for (int i = 0; i < n; i++)
                    {
                        arr1[i] = InputValidation(arr1[i], "Введите элемент массива: ");
                    }

                    // Вывод одномерного массива
                    cout << "\nИзначальный массив:\n";
                    for (int i = 0; i < n; i++)
                    {
                        cout << arr1[i] << " ";
                    }
                    b = false;
                }
                else
                {
                    if (choice2 == 2)
                    {
                        // Автоматическое заполнение
                        cout << "\nПолученный одномерный массив:\n";
                        for (int i = 0; i < n; i++)
                        {
                            arr1[i] = rand() % 10;
                            cout << arr1[i] << " ";
                        }
                        b = false;
                    }
                    else
                    {
                        cout << "\nОшибка. Неверный тип заполнения.\n";
                        b = true;
                    }
                }
            } while (b);

            // Добавление в начало массива
            NewNum = InputValidation(NewNum, "\nВведите целое число для добавленяи в начало массива: ");
            n += 1;
            for (int i = n-1; i > 0; i--)
            {
                arr1[i] = arr1[i - 1];
            }
            arr1[0] = NewNum;

            // Вывод массива
            cout << "\nМассив после добавления элемента:\n";
            for (int i = 0; i < n; i++)
            {
                cout << arr1[i] << " ";
            }
            cout << "\n\n";
            break;

        case 2:
            // Двумерный массив. Удаление строки
            do
            {
                b = true;

                n = PositiveInputValidation(n,"\nВведите количество строк в массиве: ");
                m = PositiveInputValidation(m,"\nВведите количество столбцов в массиве: ");
                // Создание чистого двумерного массива
                arr2 = new int* [n];
                for (int i = 0; i < n; i++)
                {
                    arr2[i] = new int[m];
                }

                cout << "\nВыберите тип заполнения массива:\n"
                    "1. Вручную.\n"
                    "2. Рандомно.\n";
                choice2 = InputValidation(choice2, "\nВаш выбор: ");
                switch (choice2)
                {
                case 1:
                    // Заполнение вручную
                    cout << "\nЗаполнение массива целыми числами:\n";
                    for (int i = 0; i < n; i++)
                    {
                        cout << "Заполнение " << i + 1 << "-й строки целыми числами:\n";
                        for (int j = 0; j < m; j++)
                        {
                            arr2[i][j] = InputValidation(arr2[i][j], "Введите элемент массива: ");
                        }
                    }
                    b = false;
                    break;
                case 2:
                    // Автоматическое заполнение
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            arr2[i][j] = rand() % 10;
                        }
                    }
                    b = false;
                    break;
                default:
                    cout << "\nОшибка. Неверный тип заполнения.\n";
                    b = true;
                    break;
                }
            } while (b);

            // Вывод двумерного массива
            cout << "\nИзначальный массив:\n";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << arr2[i][j] << " ";
                }
                cout << "\n";
            }

            // Удаление строки
            do
            { 
                b = false;
                DelNum = PositiveInputValidation(DelNum,"\nВыберите строку для удаления: ");
                if (DelNum > n)
                {
                    cout << "\nОшибка. Некорректная строка\n";
                    b = true;
                }
            } while (b);

            for (int i = DelNum - 1; i < n-1; i++)
            {
                arr2[i] = arr2[i + 1];
            }
            n -= 1;

            // Вывод обновленного двумерного массива
            cout << "\nОбновленный двумерный массив:\n";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << arr2[i][j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
            break;

        case 3:
            // Рваный массив. Добавление строк
            cout << "Создание рваного массива: \n";
            n = PositiveInputValidation(n,"\nВведите количество строк: ");
            arr3.resize(n);
            for (int i = 0; i < n; i++)
            {
                m = PositiveInputValidation(m,"Введите сколько элементов должно быть в строке: ");
                arr3[i].resize(m);
            }
            arr3.resize(n, vector<int>(m));
            do
            {
                b = true;
                cout << "\nВыберите тип заполнения массива:\n"
                    "1. Вручную.\n"
                    "2. Рандомно.\n";
                choice2 = InputValidation(choice2, "\nВаш выбор: ");
                switch (choice2)
                {
                case 1:
                    cout << "\nЗаполнение массива целыми числами:\n";
                    for (int i = 0; i < arr3.size(); i++)
                    {
                        cout << "Заполнение " << i + 1 << "-й строки целыми числами"
                            ", которая состоит из " << arr3[i].size() <<" элементов:\n";
                        for (int j = 0; j < arr3[i].size(); j++)
                        {
                            arr3[i][j] = InputValidation(arr3[i][j], "Введите элемент строки: ");
                        }
                    }
                    b = false;
                    break;
                case 2:
                    // Заполнение массива рандомными числами 
                    for (int i = 0; i < arr3.size(); i++)
                    {
                        for (int j = 0; j < arr3[i].size(); j++)
                        {
                            arr3[i][j] = rand() % 11 - 5;
                        }
                    }
                    b = false;
                    break;
                default:
                    cout << "\nОшибка. Неверный тип заполнения.\n";
                    b = true;
                    break;
                }
            } while (b);

            // Вывод рваного массива
            cout << "\nИзначальный массив:\n";
            for (int i = 0; i < arr3.size(); i++)
            {
                for (int j = 0; j < arr3[i].size(); j++)
                {
                    cout << arr3[i][j] << " ";
                }
                cout << "\n";
            }

            // Добавление строк

            NewSting = PositiveInputValidation(NewSting,"\nВведите сколько вы хотите добавить строк: ");
            NumString = PositiveInputValidation(NumString,"Введите с какой строки вы хотите добавить новые строки: ");
            NumString -= 1;
            for (int i = 0; i < NewSting; i++, NumString++)
            {
                n = PositiveInputValidation(n,"Введите количество элементов в новой строке: ");
                arr3.insert(arr3.begin() + NumString, vector<int>(n));
                for (int j = 0; j < arr3[NumString].size(); j++)
                {
                    arr3[NumString][j] = InputValidation(arr3[NumString][j], "Введите элемент в новой строке: ");
                }
            }

            // Вывод рваного массива
            cout << "\nНовый массив:\n";
            for (int i = 0; i < arr3.size(); i++)
            {
                for (int j = 0; j < arr3[i].size(); j++)
                {
                    cout << arr3[i][j] << " ";
                }
                cout << "\n";
            }
            break;

        case 4:
            break;
        default:
            cout << "Ошибка. Неверное действие.\n";
            break;
        }
    } while (choice1!=4);
    return 0;
}

int InputValidation(int num, string s)
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

int PositiveInputValidation(int num, string s)
{
    do {
        num = InputValidation(num, s);
        if (num < 1)
        {
            cout << "Ошибка. Введено отрицательно число или 0\n";
        }
    } while (num < 1);
    return num;
}