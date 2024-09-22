#include<iostream>
// 22.10 last programming lesson
using namespace std;
/*У кожному класі визначити дані та методи роботи з ними. Визначити дані
або методи, які перекриваються у похідних класах. Кожен клас повинен містити
конструктор ініціалізації, копіювання, деструктор, функцію для встановлення
та читання значень даних, перевантажені операції для введення і виведення
даних. Функція main() повинна ілюструвати доступ до даних та методів у
кожному класі ієрархії успадкування.*/

// base classes
class E1{
    protected:
    int mE1;
    public:
    E1(int a) { mE1 = a; cout << "E1 constructor\n"; }
    //E1(int a = 0) : mE1(a) { cout << "E1 constructor\n"; } // адекватніший варіант конструктора
    E1(const E1 &obj) { mE1 = obj.mE1; cout << "E1 copied\n"; }
    ~E1() { cout << "E1 destroyed\n"; } // virtual ?

    virtual void setM(int m) { mE1 = m; }
    virtual int getM() { return mE1; } // const?
};
class C3{
    protected:
    int mC3;
    public:
    C3(int a) { mC3 = a; cout << "C3 constructor\n"; }
    C3(const C3 &obj) { mC3 = obj.mC3; cout << "C3 copied\n"; }
    ~C3() { cout << "C3 destroyed\n"; } // virtual ?
};
// derived classes
class D1 : public E1{
    protected:
    int mD1;
    public:
    D1(int a, int b) : E1(b) { mD1 = a; cout << "D1 constructor\n"; }
    // D1(int a = 0, int b = 0) : E1(b), mD1(a) { cout << "D1 constructor\n"; } // адекватніший варіант конструктора
    D1(const D1 &obj) : E1(obj) { mD1 = obj.mD1; cout << "D1 copied\n"; }
    ~D1() {cout << "D1 destroyed\n"; }

    void setM(int m) { mD1 = m; }
    int getM() { return mD1; } // const?
};
class C1 : private D1{
    protected:
    int mC1;
    public:
    C1(int a, int b, int c) : D1(b, c) {mC1 = a; cout << "C1 constructor\n"; }
    C1(const C1& obj) : D1(obj) {mC1 = obj.mC1; cout << "C1 copied\n"; }
    ~C1() {cout << "C1 destroyed\n"; }

    void setM(int m) { mC1 = m; }
    int getM() { return mC1; } // const ?
};
class C2 : public D1{
    protected:
    int mC2;
    public:
    C2(int a, int b, int c) : D1(b, c) {mC2 = a; cout << "C2 constructor\n"; }
    C2(const C2& obj) : D1(obj) {mC2 = obj.mC2; cout << "C2 copied\n"; }
    ~C2() {cout << "C2 destroyed\n"; }

    void setM(int m) { mC2 = m; }
    int getM() { return mC2; } // const ?
};









int main(){

    return 0;
}
