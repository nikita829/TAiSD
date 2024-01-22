#include <iostream>
#include <windows.h>

class Diapason {
	static int counter;
public:
    // 1 задание
    Diapason() {
        counter++; // увеличиваем счетчик при каждом создании объекта
    }
    ~Diapason() {
        counter--; // уменьшаем счетчик при каждом удалении объекта
    }
    static int getCounter() {
        return counter; // метод для получения текущего значения счетчика
    }
	double x;
	double y;
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
    // 2 задание
    double size() {
        double Max = max(x, y);
        double Min = min(x, y);
        if (Max<0){
            Max = abs(Max);
            Min = abs(Min);
            std::swap(Max, Min);
        }
        return Max - Min;
    }
    int Convert(double x) {
        return (int)x;  // неявное приведение типа double к int (целая часть)
    }
    double Convert(int y) {
        return (double)y;  // явное приведение типа int к double
    }
    double binar_operation(Diapason D, int num) {
        D.x -= num;
        return D.x;
    }
    double binar_operation(int num, Diapason D) {
        for (int i = 0; i < num; i++)
        {
            D.y--;
        }
        return D.y;
    }
    bool binar_operation(Diapason D, Diapason d) {
        return (intersection(D, d));
    }
};

int Diapason::counter = 0;