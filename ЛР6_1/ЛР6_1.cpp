#include <iostream>

using namespace std;

class Автомобиль;
class Поезд;
class Экспресс;

class ТранспортноеСредство
{
protected:
	int MaxSpeed;
	int Year;
public:
	ТранспортноеСредство() {}
	ТранспортноеСредство(int MaxSpeed, int Year){
		this->MaxSpeed = MaxSpeed;
		this->Year = Year;
	}
	~ТранспортноеСредство() {}

	virtual void OutInfo() { 
		cout << "Максимальная скорость: " << MaxSpeed << "\n"
			<< " Год выпуска: " << Year << "\n\n";
	}
};

class Автомобиль: public ТранспортноеСредство
{
private:
	string Model;
public:
	Автомобиль(int MaxSpeed, int Year, string Model) :ТранспортноеСредство(MaxSpeed, Year) {
		this->MaxSpeed = MaxSpeed;
		this->Year = Year;
		this->Model = Model;
	}
	void OutInfo() override { 
		cout << "Максимальная скорость: " << MaxSpeed << "\n"
			<< " Год выпуска: " << Year << "\n"
			<< " Модель автомобиля: "<< Model << "\n\n";
	}
};

class Поезд: public ТранспортноеСредство
{
private:
	int num;
public:
	Поезд(int MaxSpeed, int Year, int num) :ТранспортноеСредство(MaxSpeed, Year) {
		this->MaxSpeed = MaxSpeed;
		this->Year = Year;
		this->num = num;
	}
	void OutInfo() override {
		cout << "Максимальная скорость: " << MaxSpeed << "\n"
			<< " Год выпуска: " << Year << "\n"
			<< " Номер маршрута поезда: " << num << "\n\n";
	}
};

class Экспресс : public ТранспортноеСредство
{
private:
	int length;
public:
	Экспресс(int MaxSpeed, int Year, int length) :ТранспортноеСредство(MaxSpeed, Year) {
		this->MaxSpeed = MaxSpeed;
		this->Year = Year;
		this->length = length;
	}
	void OutInfo() override { 
		cout << "Максимальная скорость: " << MaxSpeed << "\n"
			<< " Год выпуска: " << Year << "\n"
			<< " Длина экспресса (в метрах): " << length << "\n\n";
	}
};

int main()
{
	setlocale(0, "");
	const int n = 3;
	Автомобиль car(280, 2015, "BMW M5");
	Поезд train(160, 2010, 41);
	Экспресс express(420, 2021, 140);
	ТранспортноеСредство* arr[n];
	arr[0] = &car;
	arr[1] = &train;
	arr[2] = &express;
	for (int i = 0; i < n; i++)
	{
		arr[i]->OutInfo();
	}
}
