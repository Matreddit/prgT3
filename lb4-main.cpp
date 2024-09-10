#include<iostream>
#include<cstring>

using namespace std;




/*  3. Виконати індивідуальне завдання за варіантом (табл. 3).
a. Розробити діаграму класів реалізації успадкування
(https://app.diagrams.net/ або будь-яким іншим способом).
b. Написати код програми, задавши самостійно атрибути класу (від
двох до чотирьох). Об’єкти похідних класів ініціалізувати довільними даними,
використовуючи конструктори з параметрами, вивести на екран атрибути усіх
об’єктів довільним способом.
c. Продемонструвати роботу з конструктором копіювання.  */
/*  V13:
Форма:
Точка, Круг, Циліндр    */

class Forma{
    public:
    int ID;
    string objName, Tag, Layer;
    Forma(){ID = 0; objName = "NewObject", Tag = "Untagged", Layer = "Default";}
    Forma(int id, string name, string tag, string layer){
        ID = id; objName = name; Tag = tag; Layer = layer;
    }
    // cpy construct:
    Forma(const Forma& other){
        ID = other.ID;
        objName = other.objName;
        Tag = other.Tag;
        Layer = other.Layer;
    }
};

class Point : public Forma{
    public:
    int x, y;
    Point() : Forma() {x = 0; y = 0;}
    Point(int x_, int y_, int id, string name, string tag, string layer) : Forma(id, name, tag, layer)
    {x = x_; y = y_;}
    // copy constructor:
    Point(const Point& other) : Forma(other) {
        x = other.x;
        y = other.y;
    }
    // щоб можна було з однієї форми кілька об'єктів оголосить
    Point(int x_, int y_, const Forma& base) : Forma(base){
        x = x_; y = y_;
    }
};

class Circle : public Forma{
    public:
    float R;
    Circle() : Forma() {R = 2.0;}
    Circle(float radius, int id, string name, string tag, string layer) : Forma(id, name, tag, layer) {R = radius;}
    // cpy constructor
    Circle(const Circle& other) : Forma(other){
        R = other.R;
    }
    // щоб можна було з однієї форми кілька об'єктів оголосить
    Circle(float radius, const Forma& base) : Forma(base){
        R = radius;
    }
};

class Cylinder : public Circle{
    public: 
    float h;
    Cylinder() : Circle() {h = 6;}
    Cylinder(float height, float radius, int id, string name, string tag, string layer) : Circle(radius, id, name, tag, layer)
    {h = height;}
    // cpy construct
    Cylinder(const Cylinder& other) : Circle(other) {
        h = other.h;
    }
    // щоб можна було з однієї форми кілька об'єктів оголосить
    Cylinder(float height, const Circle& base) : Circle(base){
        h = height;
    }
};


int main(){

    Forma f1(1, "myObj", "Untagged", "Environment");

    Circle cr1(6.3, f1);
    cout << "circle1: " << cr1.objName << " radius = " << cr1.R << endl;

    Circle crCopied = cr1;
    cout << "copied Circle: " << crCopied.objName << " radius = " << crCopied.R << endl;

    Cylinder cy1(21, crCopied);
    cout << "cylinder: " << cy1.objName << " height = " << cy1.h << " radius = " << cy1.R << endl;

    Cylinder cyCopy(cy1);
    cout << "copy of cylinder: " << cy1.objName << " height = " << cy1.h << " radius = " << cy1.R << endl;


    return 0;
}