#include <iostream>

using namespace std;

class Student;
class Worker;

class Human
{
protected:
	string gender;
public:
	Human() {}

	Human(string gender)
	{
		this->gender = gender;
	}
	~Human() {};

	void get() {
		cout << "Пол: " << gender << " ";
	}

};

class Student: public Human
{
protected:
	int year;
public:
	Student() {}

	Student(string gender, int year) :Human(gender){
		this->gender = gender;
		this->year = year;
	}
	~Student() { }
};

class Worker: public Human
{
protected:
	string profes;
public:
	Worker() {}

	Worker(string gender, string profes) :Human(gender) {
		this->gender = gender;
		this->profes = profes;
	}
	~Worker() {}

};

int main()
{
	setlocale(0, "");

	Human arr[2][3];
	arr[0][0] = Student("Женский", 1);
	arr[0][1] = Student("Мужской", 1);
	arr[0][2] = Student("Мужской", 2);
	arr[1][0] = Worker("Мужской", "Повар");
	arr[1][1] = Worker("Мужской", "Сварщик");
	arr[1][2] = Worker("Женский", "Сварщик");

	cout << "Введите запрос\n"
		<< "Количестов людей Мужского или Женского пола\n"
		<< "Количестов студентов на определенном курсе\n"
		<< "Количестов рабочих на определенной профессии\n"
		<< "Ваш запрос: ";

}