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
    E1(int e1) { mE1 = e1; cout << "E1 constructor\n"; }
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
    C3(int c3) { mC3 = c3; cout << "C3 constructor\n"; }
    C3(const C3 &obj) { mC3 = obj.mC3; cout << "C3 copied\n"; }
    ~C3() { cout << "C3 destroyed\n"; } // virtual ?

    virtual void setM(int m) { mC3 = m; }
    virtual int getM() { return mC3; } // const?
};

// derived from E1
class D1 : public E1{
    protected:
    int mD1;
    public:
    D1(int d1, int e1) : E1(e1) { mD1 = d1; cout << "D1 constructor\n"; }
    // D1(int a = 0, int b = 0) : E1(b), mD1(a) { cout << "D1 constructor\n"; } // адекватніший варіант конструктора
    D1(const D1 &obj) : E1(obj) { mD1 = obj.mD1; cout << "D1 copied\n"; }
    ~D1() { cout << "D1 destroyed\n"; }

    void setM(int m) { mD1 = m; }
    int getM() { return mD1; } // const?
};

// derived from D1
class C1 : private D1{
    protected:
    int mC1;
    public:
    C1(int c1, int d1, int e1) : D1(d1, e1) {mC1 = c1; cout << "C1 constructor\n"; }
    C1(const C1& obj) : D1(obj) {mC1 = obj.mC1; cout << "C1 copied\n"; }
    ~C1() {cout << "C1 destroyed\n"; }

    void setM(int m) { mC1 = m; }
    int getM() { return mC1; } // const ?
};

class C2 : public D1{
    protected:
    int mC2;
    public:
    C2(int c2, int d1, int e1) : D1(d1, e1) {mC2 = c2; cout << "C2 constructor\n"; }
    C2(const C2& obj) : D1(obj) {mC2 = obj.mC2; cout << "C2 copied\n"; }
    ~C2() {cout << "C2 destroyed\n"; }

    void setM(int m) { mC2 = m; }
    int getM() { return mC2; } // const ?
};

// derived from C2
class B1 : protected C1, private C2{
    protected:
    int mB1;
    public:
    B1(int b1, int c1, int c2, int d1, int e1) : C1(c1, d1, e1), C2(c2, d1, e1) { mB1 = b1; cout << "B1 constructor\n"; }
    B1(const B1 &obj) : C1(obj), C2(obj) { mB1 = obj.mB1; cout << "B1 copied\n"; }
    ~B1() { cout << "B1 destroyed\n"; }

    void setM(int m) { mB1 = m; }
    int getM() { return mB1; } // const ?
};

class B2 : public C1, public C2, protected C3 {
    protected:
    int mB2;
    public:
    B2(int b2, int c1, int c2, int c3, int d1, int e1) : C1(c1, d1, e1), C2(c2, d1, e1), C3(c3)
    { mB2 = b2; cout << "B2 constructor\n"; }
    B2(const B2 &obj) : C1(obj), C2(obj), C3(obj) { mB2 = obj.mB2; cout << "B2 copied\n"; }
    ~B2() { cout << "B2 destroyed\n"; }

    void setM(int m) { mB2 = m; }
    int getM() { return mB2; } // const ?
};

class B3 : protected C2, private C3{
    protected:
    int mB3;
    public:
    B3(int b3, int c2, int c3, int d1, int e1) : C2(c2, d1, e1), C3(c3) {mB3 = b3; cout << "B3 constructor\n"; }
    B3(const B3 &obj) : C2(obj), C3(obj) { mB3 = obj.mB3; cout << "B3 copied\n"; }
    ~B3() { cout << "B3 destroyed\n"; }

    void setM(int m) { mB3 = m; }
    int getM() { return mB3; } // const ?
};

// derived from B2
class A2 : public B1, private B2, public B3{
    protected:
    int mA2;
    public:
    A2(int a2, int b1, int b2, int b3, int c1, int c2, int c3, int d1, int e1) :  // 9
        B1(b1, c1, c2, d1, e1), B2(b2, c1, c2, c3, d1, e1), B3(b3, c2, c3, d1, e1)
    { mA2 =  a2; cout << "A2 constructor\n"; }
    A2(const A2 &obj) : B1(obj), B2(obj), B3(obj) { mA2 = obj.mA2; cout << "A2 copied\n"; }
    ~A2() { cout << "A2 destroyed\n"; }

    void setM(int m) { mA2 = m; }
    int getM() { return mA2; } // const ?
};

class A3 : public B2, protected B3{
    protected:
    int mA3;
    public:
    A3(int a3, int b2, int b3, int c1, int c2, int c3, int d1, int e1) : // 8
        B2(b2, c1, c2, c3, d1, e1), B3(b3, c2, c3, d1, e1)
    { mA3 = a3; cout << "A3 constructor\n"; }
    A3(const A3 &obj) : B2(obj), B3(obj) { mA3 = obj.mA3; cout << "A3 copied\n"; }
    ~A3() { cout << "A3 destroyed\n"; }

    void setM(int m) { mA3 = m; }
    int getM() { return mA3; } // const ?
};








int main(){

    return 0;
}
