#include<iostream>
#include<string.h>

using namespace std;



// 2
/*2. Створити клас Х, отримати дані про об’єкт і вивести їх на екран,

використовуючи дружні функції і звичайні методи класу. Методи і friend-
функції будуть виконувати аналогічні дії. В цьому і є особлива користь

даного прикладу — ви зможете побачити відмінності в оголошенні
дружніх функцій від звичайних методів класу. На основі отриманих
даних вивести користувачу певне повідомлення.*/

class X{
    char *name;
    int y;
    friend void setData(char *, int, X&);
    friend void getData(X&);
    public:
    X(){
        name = new char[20];
        strcpy(name, "Default");
        y = 0;
    }
    ~X()
    {
        delete [] name;
        cout <<"!!! X Destructor !!!"<< endl;
    }
    void method(){
        cout << "X " << name << "'s y is equal to " << y << endl; 
    }
};
void setData(char *n, int w, X& object)//визначаємо friend-функцію setData
{ 
    strcpy(object.name, n);////
    object.y = w;
}
void getData(X& object)//визначаємо friend-функцию getData
{
    cout << object.name <<"\t: "<< object.y <<" zxc"<< endl;
}




// 1

class Woman25
{ 
    private:
    char *name;//ім’я
    int weight;//вага
    friend void setData(char *, int, Woman25&);//оголошення дружніх функцій
    friend void getData(Woman25&);
    public: Woman25()//конструктор
    {
        name = new char[20];
        strcpy(name, "Норма");
        weight = 60;
    }
    ~Woman25()//деструктор
    {
        delete [] name;
        cout <<"!!! Деструктор !!!"<< endl;
    }
    // void setData(char*, int);//оголошення методів класу
    // void getData();
    void advise(); 
};

void setData(char *n, int w, Woman25& object)//визначаємо friend-функцію setData
{ 
    strcpy(object.name, n);////////////
    object.weight = w;
}
void getData(Woman25& object)//визначаємо friend-функцию getData
{
    cout << object.name <<"\t: "<< object.weight <<" кг"<< endl;
}
// void Woman25::setData(char *n, int w)//визначаємо set-метод класу
// {
//     strcpy(name, n);
//     weight = w;
// }
// void Woman25::getData()//визначаємо get-метод класу
// {
//     cout << name <<"\t: "<< weight <<" кг"<< endl;
// }


void Woman25::advise()//визначаємо метод класу Порада (advise)
{ 
    if(weight < 55) { //якщо вага менше 55 кг
        cout <<"Вам необхідно вживати менше калорій!"<< endl;
        cout <<"====================================="<< endl <<

        endl;
    }
    else if(weight >= 55 && weight <= 65) { //якщо вага в межах 55-65 кг
        cout <<"Ваша вага в нормі!"<< endl;
        cout <<"====================================="<< endl << endl;
    }
    else{ //если вес > 65 кг
        cout <<"Вам необхідно обмежити себе в їжі!"<< endl;
        cout <<"====================================="<< endl << endl;
    } 
}

int main()
{
    X x1;
    getData(x1);
    x1.method();
    
    X x2;
    setData("Masik", 1489, x2);
    getData(x2);
    x2.method();

    cout << "\n\nwomens:\n";
    
    
    // 1
    
    // setlocale(LC_ALL, "");
    Woman25 Norm; //створюємо об’єкт Norm, спрацює конструктор і weight буде = 60, name - Норма
    // Norm.getData();
    getData(Norm);
    //виклик метода класу
    cout <<"====================================="<< endl << endl;

    Woman25 Anna; //другий об’єкт

    // Anna.setData("Анна", 100);
    setData("Анна", 100, Anna);

    // Anna.getData();
    getData(Anna);
    Anna.advise();

    Woman25 Inna; //третій об’єкт
    setData("Інна", 50, Inna);
    getData(Inna);
    Inna.advise();
    // getch();
    return 0;
}