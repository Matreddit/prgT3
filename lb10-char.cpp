#include<iostream>
#include<cstring>

using namespace std;

// цей файл тобі не треба

template <class T> T Max(T &a, T &b) {
    cout << "[template max used]";
    return (a > b) ? a : b;
}

char * Max (char *x, char *y){
    cout << "[char* max used]";
    return (strcmp(x,y) > 0 ? x : y);
}
int main() {

    char *a = "Тато", *b = "Мама";
    cout << "bigger is " << Max(a,b) << endl; 


    return 0;
}
