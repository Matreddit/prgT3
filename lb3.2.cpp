// #include<iostream>
#include <stdio.h>

using namespace std;
class Date{
    public:
    int month, day, year;
    Date(int dy, int mn, int yr){// *********** конструктор класу
    /*члени дані month, day, year будуть приймати значення, що передадуть в
конструктор як у функцію при його використанні*/
        day = dy; mn = month; yr = year;
    }

    int getMonth() const;
    /*Функція getMonth() оголошена з атрибутом const, тобто можна дані тільки
    передавати, не змінюючи їх, функція SetMonth() дозволяє змінювати дані
    всередині функції: види функцій визначені поза класом */
    void setMonth(int mn);
    int getDay();
    void setDay(int dy);
    int getYear();
    void setYear(int yr);


    ~Date(){
        // це деконструктор
    }
}; /*   це фігурна дужка з semicolon.
        за відсутності одного з цих символів компілтор видасть помилку.
        тут перед крапкою з комою можна оголосити глобальний об'єкт цього класу. */

/*створення функцій (поза класом, тому необхідно вказувати ім’я класу, для
якого ці функції створюються)*/
int Date::getMonth() const {
    return month; //Функція нічого не змінює
}
void Date::setMonth(int mn){
    month=mn; } //Функция змінює член дані класу
int Date::getDay(){
    return Date::day;
}
void Date::setDay(int dy){
    day=dy;
}
int Date::getYear(){
    return Date::year; }
void Date::setYear(int yr){
    Date::year=yr;
}

int main() // Робота зі створеним класом
{
    /*За допомогою конструктора в екземплярі класу (екземпляр з ім’ям MyDate)
    встановлюються задані користувачем значення:*/
    Date Mydate(15,5,2016);
    int d,m,y;d=Mydate.getDay(); //d=15
    m=Mydate.getMonth(); //m=5
    y=Mydate.getYear(); //y=2016
    printf("d=%d, m=%d, y=%d\n",d,m,y);
    Date BirthDate(1,12,1938);
    /*Змінити значення місяця на значення 10 в екземплярі Mydate*/
    Mydate.setMonth(10);
    m=Mydate.getMonth(); // m=10
    printf("d=%d, m=%d, y=%d\n",d,m,y);
    /*Змінити значення місяця на значення 9 об’єкту BirthDate*/
    BirthDate.setMonth(9);
    m=BirthDate.getMonth(); // m=9
    printf("d=%d, m=%d, y=%d\n",d,m,y);
    return 0;
}