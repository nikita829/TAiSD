#include <iostream>
#include <vector>
#include <Windows.h>
#include <time.h>

using namespace std;

int InputValidation(int num, string s);
double InputValidation(double num, string s);
int PositiveInputValidation(int num, string s);
double PositiveInputValidation(double n, string s);


int main()
{
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n=1,m=1, choice=0;
    bool b = true;
    double MaxNum = DBL_MIN;
    vector<vector<double>>arr;

    cout << "Создание массива: \n";
    n = PositiveInputValidation(n, "Введите количество строк: ");
    m = PositiveInputValidation(m, "Введите сколько элементов должно быть в строке: ");
    arr.resize(n, vector<double>(m));

    do
    {
        b = true;
        choice = InputValidation(choice, "Выберите способ заполнения массива:"
            "\n1. Вручную\n2. Рандомно\nВаш выбор: ");
        switch (choice)
        {
        case 1:
            cout << "\nЗаполнение массива.\n";
            for (int i = 0; i < n; i++)
            {
                cout << "Заполните " << i + 1 << "-ю строку массива (через пробел или по одному элементу).\n";
                for (int j = 0; j < m; j++)
                {   
                    arr[i][j] = InputValidation(arr[i][j], "");
                    if (MaxNum< arr[i][j])
                    {
                        MaxNum = arr[i][j];
                    }
                }
            }
            b = false;
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    arr[i][j] = rand() % 10;
                    if (MaxNum < arr[i][j])
                    {
                        MaxNum = arr[i][j];
                    }
                }
            }
            b = false;
            break;
        default:
            cout << "Некорректный ввод!\n";
            break;
        }
    } while (b);

    cout << "\nИзначальный массив:\n";
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (MaxNum == arr[i][j])
            {
                arr.erase(arr.begin() + i);
                i -= 1;
                break;
            }
        }
    }
    cout << "\nОбновленный массив:\n";
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int InputValidation(int num, string s)
{
    bool b = false;
    do{
        b = false;
        cout << s;
        if (!(cin >> num)){
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "Ошибка ввода!\n";
            b = true;
        }
    } while (b);
    return num;
}

double InputValidation(double num, string s)
{
    bool b = false;
    do{
        b = false;
        cout << s;
        if (!(cin >> num)){
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

double PositiveInputValidation(double num, string s)
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