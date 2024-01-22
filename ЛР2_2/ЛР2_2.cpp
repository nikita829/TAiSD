#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    string s;
	string simvol = { ".!?" };
	int SenEnd=0;
	cout << "Введите строку:\n";
	getline(cin, s);
	//s = "Массив вывести на печать. Удалить строку. Добавить строку.";

	if (s.empty())
	{
		cout << "\nСтрока пустая!\n";
		return 0;
	}
	else
	{
		SenEnd = s.find_first_of(simvol);
		s = s.substr(SenEnd + 1);

		while (s[0] == ' ')
		{
			s.erase(0, 1);
		}

		if (s.empty())
		{
			cout << "\nВ строке одно предложение. Строка осталась пуста\n";
			return 0;
		}
		else
		{
			SenEnd = s.find_last_of(simvol);
			s.erase(SenEnd, 1);

			SenEnd = s.find_last_of(simvol);
			s = s.substr(0, SenEnd + 1);
		}
	}
	if (s.empty())
	{
		cout << "\nВ строке два предложения. Строка осталась пуста\n";
	}
	else
	{
		cout << "\nСтрока после удаления первого и последнего предложения:\n\n" << s << "\n";
	}
	return 0;
}