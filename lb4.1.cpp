#include<iostream>

using namespace std;

class FirstClass // базовий клас
{
    protected:
        int value;
    public:
        FirstClass() { value = 0; }
        FirstClass( int input ) { value = input; }
        void show_value(){ cout << value << endl; }
};


class SecondClass : public FirstClass { // похідний клас
public:
    SecondClass() : FirstClass () {} // конструктор класу SecondClass викликає конструктор класу FirstClass
    SecondClass(int inputS) : FirstClass (inputS) {} // inputS передається в конструктор з параметром класу FirstClass
    
    void ValueSqr () { value *= value; } // підносить value до квадрату. Без специфікатора доступу protected ця функція не могла б змінити значення value
};


int main(){

    FirstClass F_object(10); // об’єкт базового класу
    cout << "value F_object = ";
    F_object.show_value();
    SecondClass S_object(11); // об’єкт похідного класу
    cout << "value S_object = ";
    S_object.show_value(); // виклик методу базового класу
    S_object.ValueSqr(); // підносимо value до квадрату
    cout << "квадрат value S_object = ";
    S_object.show_value();
    cout << endl;



    return 0;
}