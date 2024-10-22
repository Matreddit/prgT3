#include <iostream>

using namespace std;

/*Додаткове завдання:
Створити клас ДІЙСНИХ ЧИСЕЛ. Перевантажити бінарні операції +, -, *, / 
для виконання арифметичних обчислень над дійсними числами.

Операції +, - перевантажити за допомогою методів класу, 
а операції *, /, як дружні функції.

Перевантажити потокову операцію >> для введення з
клавіатури та операцію << для виведення на екран.*/

class MyDouble{
    double value;
    public:
    MyDouble() : value(0) {}

    MyDouble(double val) : value(val) {}

    MyDouble operator+(MyDouble other) {
        return MyDouble(this->value + other.value);
    }

    MyDouble operator-(MyDouble other) {
        return MyDouble(this->value - other.value);
    }

    friend MyDouble operator*(MyDouble a, MyDouble b);
    friend MyDouble operator/(MyDouble a, MyDouble b);
    friend istream& operator>>(istream& in, MyDouble& num);
    friend ostream& operator<<(ostream& out, MyDouble num);
};


MyDouble operator*(MyDouble a, MyDouble b) {
    return MyDouble(a.value * b.value);
}

MyDouble operator/(MyDouble a, MyDouble b) {
    return MyDouble(a.value / b.value);
}

istream& operator>>(istream& in, MyDouble& num) {
    in >> num.value;
    return in;
}

ostream& operator<<(ostream& out, MyDouble num) {
    out << num.value;
    return out;
}

int main() {
    MyDouble a, b;
    
    cout << "enter a: ";
    cin >> a;
    cout << "ented b: ";
    cin >> b;

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;

    return 0;
}