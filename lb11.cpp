#include<iostream>

using namespace std;
/*
Завдання

Спроектувати шаблон для класу, створеного відповідно до свого
варіанту. В основній програмі створити відповідні структури простих
(наприклад, список чисел або рядків) і складних даних (наприклад, список
об’єктів іншого класу) і продемонструвати роботу з ними.

Варіанти завдань

13. Послідовні кільцеві структури даних (стеки, черги)*

Базовий клас (кільцева структура даних):
Конструктори: за замовчуванням, з параметрами та копіювання.
Деструктор.
Функції:

● виведення всіх елементів на екран;
● інформація про максимальну кількість елементів.

Похідний клас: черга.
Функції:

● додавання елемента в чергу;
● інформація про поточну кількість елементів в черзі;
● видалення елемента (заданої кількості елементів) з черги.
*/



template<class T>
class Node{
    public:
    T data;
    Node* next;
    Node() : data(T()), next(nullptr) {}
    Node(T newData) : data(newData),next(nullptr) {}
};

template<class T>
class Stack{
    Node<T>* head;
    
    public:
    Stack() : head(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    bool isEmpty() { return (head == nullptr); }

    void push(T newData){
        Node<T> *newNode = new Node<T>(newData);
        if(!newNode) { cout << "\nStack Overflow"; return; }
        newNode->next = head;
        head = newNode;
    }
    void pop(){
        if(isEmpty()) { cout <<"nStack Underflow"; }
        else{
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    T peek(){
        if(!isEmpty()){
            return head->data;
        } else {
            cout << "\nStack is empty";
            return T();
        }
    }

    //zxczxczxc
    void del(int num = 1){
        for (size_t i = 0; i < num; i++){
            if(!isEmpty()){
                pop();
            }
        }
    }
    int len(){
        if(isEmpty()){ return 0; }
        Node<T>* temp = head;
        int i = 0;
        while (temp){
            i++;
            temp = temp->next;
        }
        return i;
    }
};

int main(){


    Stack<string> st;
    for (size_t i = 0; i < 20; i++)
    {
        st.push("hello" + to_string(i));
    }

    while (!st.isEmpty())
    {
        cout << st.peek() << endl;
        st.pop();
    }
    
    
    // st.push(2);
    // st.push(3);
    // st.push(4);
    // st.push(5);
    // for (size_t i = 0; i < 20; i++){
    //     st.push(i + 100);
    // }
    

    // cout << "len is " << st.len() << endl;

    // while (!st.isEmpty())
    // {
    //     if(st.peek() == 4) {st.del();}
    //     if(st.peek() == 111) {st.del(6);}

    //     cout << st.peek()  << ", len is " << st.len() << endl;
    //     st.pop();
    // }
    

    return 0;
}