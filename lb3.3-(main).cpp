#include<iostream>
#include<cstring>

using namespace std;


/*3. Виконати індивідуальне завдання за варіантом (табл. 2). Сконструювати
клас із заданим набором властивостей (варіант відповідає номеру студента у списку групи).
В клас додати методи для перегляду і зміни значень будь-якої властивості об’єкта. 
Вимоги до конструювання класу:
доступ до властивостей — закритий, до методів — відкритий. В класі необхідно
передбачити конструктор за замовчуванням, конструктор з параметрами.
a. Створити об’єкт за допомогою конструктора за замовчуванням.
b. Створити об’єкт за допомогою конструктора з параметрами.
c. Створити масив об’єктів (розмірність масиву 4 елементи).
d. Ініціалізація властивостей кожного об’єкта масиву (вихідні дані
вводяться з клавіатури).
e. Перегляд властивостей кожного об’єкту.
f. Обчислення заданого параметра для масиву об’єктів у відповідності
з варіантом завдання.*/
/*
10. 
Властивості класу:
    Марка принтера, Формат паперу, Швидкість друку, Ціна.
Параметр, який необхідно знайти: 
    Визначити найдешевший принтер.*/

class Printer{
    string modelName, paperFormat;
    float speedOfPrint, price;

    public:
    Printer(){
        modelName = "Canon-MF3010"; paperFormat = "A4";
        speedOfPrint = 1.2; price = 127.97; }
    Printer(const string& model, const string& format, float speed, float price_){
        modelName = model; paperFormat = format;
        speedOfPrint = speed; price = price_; }

    string getName(){return modelName;}
    string getFormat(){return paperFormat;}
    float getSpeed(){return speedOfPrint;}
    float getPrice(){return price;}
    void setModel(string model){modelName = model;}
    void setFormat(string format){paperFormat = format;}
    void setSpeed(float speed){speedOfPrint = speed;}
    void setPrice(float price_){price = price_;}
    
    void printInfo()
    {
        cout << "Printer " << modelName << "\nformat: " << paperFormat 
            << ", printing speed: " << speedOfPrint << ", price: " << price << endl;
    }
};

Printer findCheapest(Printer printers[], size_t size){
    Printer cheapest = printers[0];
    for (size_t i = 1; i < size; i++)
    {
        if(printers[i].getPrice() < cheapest.getPrice())
            cheapest = printers[i];
    }
    return cheapest;
    
}

int main(){
    const int N(4);

    // a
    Printer defPrinter;
    //cout << "Default printer: " << defPrinter.getName() << ", costs " << defPrinter.getPrice() << endl; 
    defPrinter.printInfo(); cout << "\n";
    // b
    Printer myPrinter("heil-print-1A4-88", "A1", 0.89, 1699.99);
    //cout << "Mein printer: " << myPrinter.getName() << ", costs " << myPrinter.getPrice() << endl; 
    myPrinter.printInfo(); cout << "\n\n";
    // c
    Printer prints[N];
    // d
    for (size_t i = 0; i < N; i++)
    {   
        string uIn;
        cout << "Enter printer model: ";    cin >> uIn;
        prints[i].setModel(uIn);
        cout << "Enter paper format: ";    cin >> uIn;
        prints[i].setFormat(uIn);
        cout << "Enter printing speed: ";    cin >> uIn;
        prints[i].setSpeed(stof(uIn));
        cout << "Enter printer price: ";    cin >> uIn;
        prints[i].setPrice(stof(uIn));
        cout << "\n";
    }
    // e
    for (size_t i = 0; i < N; i++)
    {
        prints[i].printInfo(); cout << "\n";
    }
    // f
    cout << "\nThe cheapest printer is:\n";
    findCheapest(prints, N).printInfo();
    
    


    return 0;
}