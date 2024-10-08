/*
1. Виконати індивідуальне завдання за варіантом (табл. 4).

a. Створити базовий клас та визначити загальні методи show ( ), get ( ),
    set ( ) та інші, що є специфічними для даного класу.
b. Створити похідні класи, до яких додати властивості і методи.
c. Для похідних класів застосувати відкрите, захищене та закрите
    успадкування.
d. Продемонструвати можливість відновлення рівня доступу при
    успадкуванні.
e. Створити масив об’єктів базового класу та заповнити об’єктами
    похідних класів. Об’єкти похідних класів ідентифікувати конструктором.
f. Перегляд масиву об’єктів здійснити довільним способом.

V13
    Книги ->    Романи     Наукові книги       Дитячі книги.
За допомогою конструктора здійсніть ініціалізацію.
Включіть методи для відображення інформації про книгу.
*/

#include <iostream>
#include <cstring>

using namespace std;

class Book{
    private:
        int bookID;
        float price;
    protected:
        int pages, year;
    public:
        string name, author;

        Book(){
            bookID = 0; price = 0.0; pages = 0; year = 2033;
            name = "book"; author = "author";
        }
        Book(string name, string author, int year, int pages, float price, int id){
            this->name = name; this->author = author; this->year = year;
            this->pages = pages; this->price = price; bookID = id;
        }

    int getID() {return bookID; } 
    float getPrice() { return price; }
    int getYear() { return year; }
    int getPages() { return pages; }

    void setID(int id){bookID = id;}
    void setPrice(float price){ this->price = price; }
    void setYear(int year){this->year = year;}
    void setPages(int pages){ this->pages = pages; }

    void show() {
        cout << "Name: " << name << ", author: " << author
            << ", year: " << year << ", pages: " << pages
            << ", price: " << price << ", book #" << bookID << endl;
    }
};

class Novel : public Book {
    public:
    string mainCharacters;

    Novel() : Book() { mainCharacters = ""; }
    Novel(string mainCharacters, string name, string author, int year, int pages, float price, int id) :
        Book(name, author, year, pages, price, id) 
    {
        this->mainCharacters = mainCharacters;
    }
    
    void addMainCharacters(string character) {
        if (mainCharacters == "") mainCharacters += character;
        else{ mainCharacters += ", "; mainCharacters += character; } 
    }
};

class ScienceBook : protected Book {
    public:
    string topic;

    ScienceBook() : Book() { topic = "topic"; }
    ScienceBook(string topic, string name, string author, int year, int pages,
        float price, int id) : Book(name, author, year, pages, price, id)
        {
            this->topic = topic;
        }
    
};

class KidsBook : private Book {
    public:
    int age;
    // todo: відновити рівень доступу
    using Book::name; // без using теж працює, але: access declarations are deprecated in favor of using-declarations; suggestion: add the ‘using’ keyword [-Wdeprecated]gcc
    using Book::show; // для функцій () не пишем

    KidsBook() : Book(){ age = 3; }
    KidsBook(int age, string name, string author, int year, int pages, float price, int id) :
        Book(name, author, year, pages, price, id)
    {
        this->age = age;
    }
};

void l(){cout << "\n\n\n";}
int main(){
    const int N = 12;


    KidsBook k;
    k.show();
    cout << "the name is: " << k.name;

    l();
///////////////// !!! якщо хочеться щоб в масиві об'єктів були не тільки Novel,
    //         треба щоб інші два класа успадковували Book змодифікатором public,
    //        бо інакше скаже що не можна присвоїть в Book якийсь ScienceBook,
    //        бо воно спадкує базовий клас приватно 
    
    Book books[N];
    for (int i = 0; i < N; i++){
        books[i] = Novel("SF, Pudge, Io", "DefOfTheAnc", "Vova Z.", 1998 + i, 113 + i * 3, 399.99 - i / 3, i);
    }
    for (int i = 0; i < N; i++){
        books[i].show();
    }

    l();
    




    return 0;

}
