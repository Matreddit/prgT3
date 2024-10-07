#include<iostream>

using namespace std;
class Shape{
    public:
    virtual double area() const = 0;
};

class Square: public Shape{
    public:
    Square(double a = 1): _a(a) { }
    virtual double area() const { return _a * _a; }
    private:
    double _a;
};
class Circle: public Shape {
    public:
    Circle(double r = 1): _r(r) { }
    virtual double area() const { return 3.14159265358 * _r * _r; }
    private:
    double _r;
};

int main(){
    Shape *shapes[5];
    shapes[0] = new Circle (3);
    shapes[1] = new Square (2);
    shapes[2] = new Square (2.5);
    shapes[3] = new Circle (5);
    shapes[4] = new Circle (10);

    for (int i = 0; i < 5; ++i)
        std::cout << shapes[i]->area() << std::endl;

    for (int i = 0; i < 5; ++i)
        delete shapes[i];

    return 0;
}