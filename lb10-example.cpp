#include<iostream>
#include <cstring>

using namespace std;

template<typename T>
void printArray(const T *array, int count){
    for (int ix = 0; ix < count; ix++)
        cout << array[ix] << " ";
    cout << endl;
}

int main() {

// розміри масивів
    const int iSize = 10,
    dSize = 7,
    fSize = 10,
    cSize = 5;
    // масиви різних типів даних
    int iArray[iSize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double dArray[dSize] = {1.2345, 2.234, 3.57, 4.67876, 5.346, 6.1545, 7.7682};
    float fArray[fSize] = {1.34, 2.37, 3.23, 4.8, 5.879, 6.345, 73.434, 8.82, 9.33, 10.4};
    char cArray[cSize] = "MARS";
    cout << "\t\t Шаблон функції виведення масиву на екран\n\n";
    // виклик шаблонної функції printArray для типу int
    cout << "\nМассив типа int:\n";
    printArray(iArray, iSize);


    // виклик шаблонної функції printArray для типу double
    cout << "\nМассив типа double:\n";
    printArray(dArray, dSize);
    // виклик шаблонної функції printArray для типу float
    cout << "\nМассив типа float:\n";
    printArray(fArray, fSize);
    // виклик шаблонної функції printArray для типу char
    cout << "\nМассив типа char:\n";
    printArray(cArray, cSize);


    return 0;
}
