#include<iostream>
#include<string>

using namespace std;

/*Реалізувати множинне успадкування. В базових класах методи,
що виводять на екран інформацію про об’єкт, необхідно зробити віртуальними
та продемонструвати їх роботу. Перевизначити у кожному зі створених класів
функцію name так, щоб вона виводила на екран дійсне ім’я класу об’єкту,
для якого вона викликається. Для кожного з класів створеної ієрархії
створити по одному об’єкту і для кожного з них викликати функцію name.  

Клас, який необхідно побудувати
    Базові класи
        Члени дані та методи базових класів
                    V13 -> 3
СПА-салон:
    Послуги:
        Назва послуги;
        вартість послуги;
        отримати знижку на послугу для постійного клієнта (15 %);
    Попередній запис:
        Прізвище;
        ім’я;
        вік;
        стать;
        дата надання послуги;
        виведення інформації про властивості об’єкта на екран;
*/

class Posluha{
    protected:
    string posluhaName;
    float price;

    public:
    Posluha(const string & name = "", float cost = 0.0) : posluhaName(name), price(cost) {}
    void getDiscount(){ price *= 0.85; }

    virtual void name() { cout << "Posluha\n"; }
    virtual void printInfo() {
        cout << "Posluha \"" << posluhaName << "\" costs " << price << endl;
    }
};

class PrevZapys{
    protected:
    string secondName, firstname, gender, date;
    int age;

    public:
    PrevZapys(const string &sname = "Zelenskyy", const string &fname = "Vova", int age_ = 8, const string &gender_ = "frau", const string &date_ = "15.05.2024")
        : secondName(sname), firstname(fname), gender(gender_), date(date_), age(age_) {}
    
    virtual void name() { cout << "PrevZapys\n"; }
    virtual void printInfo() {
        cout << "PrevZapys: " << secondName << " " << firstname << ", " << age << ". Date: " << date << endl;
    }
};

class SpaSalon : public Posluha, public PrevZapys {
    public:
    SpaSalon(const string &PoslName, float cost, const string &sname, const string &fname, int age_, const string &gender_, const string &date_)
        : Posluha(PoslName, cost), PrevZapys(sname, fname, age_, gender_, date_) {}

    void name() override { cout << "SpaSalon\n"; }
    void printInfo() override {
        cout << "Spa Salon:\n";
        Posluha::printInfo();
        PrevZapys::printInfo();
    }
};

int main(){

    Posluha posl("Trumping", 699.99);
    posl.name();
    posl.printInfo();
    cout << "\n";

    PrevZapys zapys("Arestovich", "Oleksii", 49, "male", "5.11.2024");
    zapys.name();
    zapys.printInfo();
    cout << "\n";

    SpaSalon salon("Karasing", 300.0, "Romanenko", "Yurii", 54, "male", "26.12.2024");
    salon.name();
    salon.printInfo();
    cout << "\n";



    return 0;
}

