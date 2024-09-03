#include<iostream>
#include<cmath>

using namespace std;

/*1. Створити клас С_Int, що імітує стандартний тип int. Єдине поле цього класу
повинно мати тип int. Створити 4 методи: встановлення значення поля, що
дорівнює 0; ініціалізація поля довільним цілим значенням; виведення
значення поля на екран; додавання двох значень цілого типу.*/
class C_int{
    int num;
    public:
    void set(){num = 0;}
    void set(int n){ num = n; }
    void show(){ cout << num << endl;}
    int add(int n2) {return num+n2;}
};

/*Варіант 10. Створіть клас Triangle з приватними полями для сторін. Додайте
метод для обчислення площі трикутника та створіть об’єкт для обчислення
площі трикутника з певними сторонами.   */

class Triangle{
    float a, b, c;
    public: 
    float calcArea(){
        float p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    Triangle() { a = 3; b = 4; c = 5; }
    Triangle(float a_, float b_, float c_){ a = a_; b = b_; c = c_; }
    void setSides(float a_, float b_, float c_) { a = a_; b = b_; c = c_; }
};

int main(){

    C_int i;
    i.set(9090);
    i.show();
    cout << "added " <<i.add(10);
//////////////////////////////////////////////////////
    cout << "\n\n";

    Triangle tr[7];
    for (size_t i = 0; i < 7; i++)
    {
        tr[i].setSides(i + 3, i + 3.1, i + 1.1);
    }
    for (size_t i = 0; i < 7; i++)
    {
        cout << "area of triangle #" << i << " is " << tr[i].calcArea() << endl;
    }
    
    
    



    return 0;
}