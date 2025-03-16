#include<iostream>
#include<string>

using namespace std;

/*1. Створити два класи (обрати довільний із варіантів попередніх
лабораторних робіт). Один із них оголосити дружнім і, використовуючи
його методи, внести зміни в приватні елементи другого класу.*/


class Max;

class Vova{
    private:
    int money, age;
    friend void printInfo(Vova&);

    public:
    Vova() : money(0), age(15) {}
    Vova(int Money, int Age) : money(Money), age(Age) {}

    friend Max;
};

class Max{
    private:
    string lastName;
    int money;
    friend void printInfo(Max&);

    public:
    Max() : lastName("Dovzhenko"), money(0) {}
    Max(const string& LastName, int Money) : lastName(LastName), money(Money) {}

    void getMoneyFromVova(Vova& obj){
        money += obj.money;
        obj.money = 0;
    }
    
};

void printInfo(Vova& obj){
    cout << "Vova, " << obj.age << ". has " << obj.money << " hryven.\n";
}
void printInfo(Max& obj){
    cout << "Max " << obj.lastName << " has " << obj.money << " hryven.\n";
}

int main(){

    Vova v(126, 19);
    Max m;
    printInfo(v);
    printInfo(m);
    cout << "-----------\n";
    m.getMoneyFromVova(v);
    printInfo(v);
    printInfo(m);
    
    
    return 0;
}
