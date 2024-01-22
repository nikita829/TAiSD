#include <iostream>
#include <windows.h>
#include <time.h>
#include "F:\Учеба\2 курс\ТАиСД\Новая папка\Diapason\Diapason.cpp"
using namespace std;

class DiapasonArray {
	static int count;
	double Max = DBL_MIN;
	int MaxEl;
public:
	int SizeArr;
	Diapason* arr;

	DiapasonArray() {
		count++;
	}

	DiapasonArray(int size) {
		count++;
		SizeArr = size;
		arr = new Diapason[SizeArr];
		for (int i = 0; i < size; i++)
		{
			cout << "Введите начало диапазона " << i + 1 << ": ";
			cin >> arr[i].x;
			cout << "Введите конец  диапазона " << i + 1 << ": ";
			cin >> arr[i].y;
		}
	}

	DiapasonArray(int size, int min, int max) {
		count++;
		SizeArr = size;
		arr = new Diapason[SizeArr];
		for (int i = 0; i < size; i++)
		{
			arr[i].x = rand() % (max - min) + min;
			arr[i].y = rand() % (max - min) + min;
		}
	}

	~DiapasonArray() {
		count--; 
	}

	Diapason Max_Element() {
		for (int i = 0; i < SizeArr; i++)
		{
			if (Max < arr[i].x) {
				Max = arr[i].x;
				MaxEl = i;
			}
			else
			{
				if (Max < arr[i].y) {
					Max = arr[i].y;
					MaxEl = i;
				}
			}
		}
		return arr[MaxEl];
	}

	double MaxNum() {
		return max(Max_Element().x, Max_Element().y);
	}

	Diapason NumOut(int i) {
		return arr[i-1];
	}

	void ArrayOut() {
		for (int i = 0; i < SizeArr; i++)
		{
			cout << arr[i].x << "\t...\t" << arr[i].y << "\n";
		}
	}

	static int GetCount() {
		return count; 
	}
};

int DiapasonArray::count = 0;