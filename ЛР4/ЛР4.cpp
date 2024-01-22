#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;
const int MaxDays = 31;
const string FileName = "File.txt";

struct TemperatureRecord 
{
    int day;
    double temperature;
};

int InputValidation(int num, string s);
double InputValidation(double num, string s);
int PositiveInputValidation(int num, string s);
double PositiveInputValidation(double n, string s);
void fileUpdate(TemperatureRecord records[], int count);
void Menu();
void viewRecords(TemperatureRecord records[], int count);
void addRecord(TemperatureRecord records[], int& count);
void deleteRecord(TemperatureRecord records[], int& count);
void updateRecord(TemperatureRecord records[], int count);
void AverageTemperature(TemperatureRecord records[], int count);
void longestNegativeTemperature(TemperatureRecord records[], int count);

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    TemperatureRecord records[MaxDays];
    int recordCount=0, choice=0;
    ifstream FileIn(FileName);

    if (FileIn.is_open()) {
        for (int i = 0; !FileIn.eof(); i++) {
            if (i > MaxDays) {
                cout << "Ошибка. Присутствуют лишние записи." << endl;
                FileIn.close();
                return 0;
            }
            FileIn >> records[i].day;
            FileIn >> records[i].temperature;
            recordCount = records[i].day;
        }
        FileIn.close();
        cout << "Файл загружен успешно." << endl;
    }
    else {
        cout << "Ошибка открытия файла." << endl;
        FileIn.close();
        return 0;
    }

    do {
        Menu();
        choice = InputValidation(choice, "Введите ваш выбор: ");
        switch (choice) 
        {
        case 1:
            addRecord(records, recordCount);
            system("pause");
            system("cls");
            break;
        case 2:
            deleteRecord(records, recordCount);
            system("pause");
            system("cls");
            break;
        case 3:
            updateRecord(records, recordCount);
            system("pause");
            system("cls");
            break;
        case 4:
            viewRecords(records, recordCount);
            system("pause");
            system("cls");
            break;
        case 5:
            AverageTemperature(records, recordCount);
            system("pause");
            system("cls");
            break;
        case 6:
            longestNegativeTemperature(records, recordCount);
            system("pause");
            system("cls");
            break;
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);
    fileUpdate(records, recordCount);
    return 0;
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

double InputValidation(double num, string s) {
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

int PositiveInputValidation(int num, string s) {
    do {
        num = InputValidation(num, s);
        if (num < 1) {
            cout << "Ошибка. Введено отрицательно число или 0\n";
        }
    } while (num < 1);
    return num;
}

double PositiveInputValidation(double num, string s) {
    do {
        num = InputValidation(num, s);
        if (num < 1) {
            cout << "Ошибка. Введено отрицательно число или 0\n";
        }
    } while (num < 1);
    return num;
}

void fileUpdate(TemperatureRecord records[], int count) {
    ofstream FileOut(FileName);
    if (FileOut.is_open()) {
        for (int i = 0; i < count - 1; i++) {
            FileOut << records[i].day << " "
                << records[i].temperature << '\n';
        }
        FileOut << records[count - 1].day << " "
            << records[count - 1].temperature;
        FileOut.close();
        cout << "Файл обновлен успешно." << endl;
    }
    else {
        cout << "Ошибка обновления файла." << endl;
        FileOut.close();
    }
}

void Menu() {
    cout << "1. Добавить запись\n"
        << "2. Удалить запись\n"
        << "3. Корректировать запись\n"
        << "4. Просмотреть записи\n"
        << "5. Определить среднюю температуру каждой недели\n"
        << "6. Определить самый длинный отрезок с отрицательной температурой\n"
        << "0. Выйти\n";
}

void viewRecords(TemperatureRecord records[], int count) {
    if (count > 0) {

        cout << "\nТемпература за месяц:\nДень\tTемпература\n";
        for (int i = 0; i < count; i++) {
            cout << records[i].day << "\t" << records[i].temperature << "\n";
        }
    }
    else {
        cout << "\nНет записей.\n";
    }
}

void addRecord(TemperatureRecord records[], int& count) {
    int dayAdd=0;
    double tempAdd=0;
    bool b = false;
    if (count < MaxDays) {
        viewRecords(records, count);
        do {
            b = false;
            dayAdd = PositiveInputValidation(dayAdd, "\nВведите день месяца: ");

            for (int i = 0; i < MaxDays; i++) {
                if (dayAdd == records[i].day) {
                    cout << "Такой день уже есть, выберите другой.\n";
                    b = true;
                    break;
                }
                if (dayAdd > MaxDays || dayAdd < 0) {
                    cout << "Некорректная дата. Попробуйте снова.\n";
                    b = true;
                    break;
                }
            }
        } while (b);

        dayAdd -= 1;

        tempAdd = InputValidation(tempAdd, "\nВведите температуру: ");
        for (int i = count; i > dayAdd; i--) {
            records[i] = records[i - 1];
        }
        records[dayAdd].day = dayAdd+1;
        records[dayAdd].temperature = tempAdd;

        count++;
        system("cls");
        Menu();
        cout << "Запись сохранена.\n";
        viewRecords(records, count);
    }
    else {
        cout << "Ошибка. Нельзя добавить запись, достигнуто максимальное количество записей.\n";
    }
}

void deleteRecord(TemperatureRecord records[], int& count) {
    if (count > 0) {
        viewRecords(records, count);
        int dayToDel=0,indexToDel = -1;
        dayToDel = InputValidation(dayToDel, "\nВведите день для удаления : ");

        for (int i = 0; i <= count; ++i) {
            if (records[i].day == dayToDel) {
                indexToDel = i;
                break;
            }
        }

        if (indexToDel != -1) {
            for (int i = indexToDel; i < count; ++i) {
                records[i] = records[i + 1];
            }
            count--;
            system("cls");
            Menu();
            cout << "Запись удалена.\n";
            viewRecords(records, count);
        }
        else {
            cout << "\nОшибка. Запись не найдена.\n";
        }
    }
    else {
        cout << "\nОшибка. Нет записей для удаления.\n";
    }
}

void updateRecord(TemperatureRecord records[], int count) {
    if (count > 0)
    {
        viewRecords(records, count);
        int dayToUpdate = 0, indexToUpdate = -1;
        dayToUpdate = InputValidation(dayToUpdate, "\nВведите день для корректировки: ");

        for (int i = 0; i < count; ++i) {
            if (records[i].day == dayToUpdate) {
                indexToUpdate = i;
                break;
            }
        }

        if (indexToUpdate != -1) {
            records[indexToUpdate].temperature = InputValidation(records[indexToUpdate].temperature, "\nВведите новую температуру : ");
            system("cls");
            Menu();
            cout << "Запись сохранена.\n";
            viewRecords(records, count);
        }
        else {
            cout << "\nОшибка. Запись не найдена.\n";
        }
    }
    else {
        cout << "\nОшибка. Нет запией для корректировки.\n";
    }
}

void AverageTemperature(TemperatureRecord records[], int count) {
    viewRecords(records, count);
    int numWeeks = count / 7; 

    for (int week = 0; week < numWeeks; week++) {
        int weekStart = week * 7;
        int weekEnd = weekStart + 7;
        double weekSum = 0;

        for (int i = weekStart; i < weekEnd; i++) {
            weekSum += records[i].temperature;
        }
        double averageTemperature = static_cast<double>(weekSum) / 7;
        cout << "Средняя температура в неделю " << week + 1 << ": " << averageTemperature << "\n";
    }
}

void longestNegativeTemperature(TemperatureRecord records[], int count) {
    viewRecords(records, count);
    int maxLength = 0, curLength = 0;

    for (int i = 0; i < count; i++) {
        if (records[i].temperature < 0) {
            curLength++;
        }
        else {
            maxLength = max(maxLength, curLength);
            curLength = 0;
        }
    }
    maxLength = max(maxLength, curLength);
    cout << "Cамый длинный отрезок между днями с отрицательной температурой: " << maxLength << "\n";
}