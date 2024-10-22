#include<iostream>
#include<string>

using namespace std;

// V 13 - 6 = 7; 7 - 6 = 1;
// V 1:
/*
Клас Х:
    Girl_3-14

Дані про об’єкт
    Прізвище
    Вік
    Зріст

Виведення повідомлення
    Розрахувати зріст-норма за формулою: 6*Вік+76.
    1.  Якщо зріст менше зріст-норма, то вивести «Ваш зріст менше норми».
    2.  Якщо зріст відхилення зросту від зросту норми не перевищує 3-3,5 см,
        то вивести «Ваш зріст відповідає фізіологічним особливостям».
    3.  Якщо зріст відхилення зросту від зросту норми перевищує 3-3,5 см,
        то вивести «Ваш зріст вище норми».
*/

class Girl_3to14{
    string name;
    int age, height;

    friend void calculate(Girl_3to14&);
    friend void printInfo(Girl_3to14&);
    public:
    Girl_3to14(){
        name = "Default";
        age = 0; height = 0;
    }
    Girl_3to14(const string& Name, int Age, int Height){
        name = Name;
        age = Age; height = Height;
    }
    ~Girl_3to14(){
        cout << "destructed\n";
    }
    void calculate(){
        int normH = 6*age+76;
        if (height < (normH - 3.5)){
            cout << "Your height is less than normal\n";
        } else if (height > (normH + 3.5))
        {
            cout << "Your height is above normal\n";
        } else {
            cout << "Your height corresponds to your physiological characteristics\n";
        }
    }
};

void calculate(Girl_3to14& obj){
    int normH = 6*obj.age+76;
    if (obj.height < (normH - 3.5)){
        cout << "Your height is less than normal\n";
    } else if (obj.height > (normH + 3.5)){
        cout << "Your height is above normal\n";
    } else {
        cout << "Your height corresponds to your physiological characteristics\n";
    }
}

void printInfo(Girl_3to14& obj){
    cout << obj.name << ", " << obj.age << ". h = " << obj.height << ".\n";
    cout << "Deviation from the norm = " << obj.height - (6*obj.age+76) << endl;
}

int main(){

    Girl_3to14 g0;
    printInfo(g0);
    calculate(g0);
    g0.calculate();

    cout << "-------------------\n\n";

    Girl_3to14 g1("Artemija", 12, 150);
    printInfo(g1);
    calculate(g1);

    cout << "-------------------\n\n";

    Girl_3to14 g2("Antonija", 5, 103);
    printInfo(g2);
    calculate(g2);

    cout << "-------------------\n\n";

    Girl_3to14 g3("Prihozhina", 9, 195);
    printInfo(g3);
    calculate(g3);

    cout << "-------------------\n\n";






    return 0;
}