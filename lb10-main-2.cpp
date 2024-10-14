#include<iostream>
#include<string>

using namespace std;

/*
    Варіанти завдань підвищеного рівня
1. Пошук шаблону в рядку Напишіть шаблонну функцію, яка приймає
    рядок та шаблон рядка, і визначає, чи містить рядок відповідний підрядок
    за заданим шаблоном. Ваша функція повинна підтримувати шаблони, які
    містять спеціальні символи (*, ? тощо) для відповідності різним
    символам. (це типу ніфіга не шаблонна функція, а дефолтна функція 
    типу свій недоDuckDuckGo написати)
        * означає будь яка кількість будь чого
        ? означає будь-який один символ
    Світлана Олександрівна казала що можна одне з двох робить.
2. Шаблонна матрична операція Напишіть шаблонну функцію для
    виконання операцій додавання, віднімання або множення між двома
    матрицями будь-якого типу. Забезпечте перевірку на сумісність операцій,
    тобто виконайте перевірку розмірів матриць.
*/

// 1
// це якась фігня, першого завдання нема
bool isPtrnInStr(const string &str, const string &pattern){
    int i;
    if( i = str.find(pattern) != std::string::npos) {return true; cout << i << " index;\n";}
    else return false;
}

// 2
template<class T>
void addMatrix(T **matrix1, T **matrix2, int rows1, int cols1, int rows2, int cols2){
    if (rows1 != rows2 || cols1 != cols2) return;

    for (int i = 0; i < rows1; i++){
        for (int j = 0; j < cols1; j++){
            matrix1[i][j] += matrix2[i][j];
        }
    }
}

template<class T>
T** multiplyMatrix(T **matrix1, T **matrix2, int rows1, int cols1, int rows2, int cols2){
    if (cols1 != rows2) return nullptr;

    T** result = new T*[rows1];
    for (int i = 0; i < rows1; i++) {
        result[i] = new T[cols2];
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

int main(){

    int rows = 3, cols = 3;

    float** intMatrix1 = new float*[rows];
    for (int i = 0; i < rows; ++i) {
        intMatrix1[i] = new float[cols];
    }
    float** intMatrix2 = new float*[rows];
    for (int i = 0; i < rows; ++i) {
        intMatrix2[i] = new float[cols];
    }


    for (int i = 0, ii = 1; i < rows; i++){
        for (int j= 0; j < cols; j++){
            intMatrix1[i][j] = ii; ii++;
        }
    }
    float ii = 1.1;
    for (int i = 0; i < rows; i++){
        for (int j= 0; j < cols; j++){
            intMatrix2[i][j] = ii; ii += 1.1;
        }
    }

    float **result = multiplyMatrix(intMatrix1, intMatrix2, rows,cols,rows,cols);
    
    addMatrix(intMatrix1,intMatrix2,rows,cols,rows,cols);
    
    cout << "multiplied:\n"; 
    for (int i = 0; i < rows; i++){
        for (int j= 0; j < cols; j++){
            cout << result[i][j] << "--\n";
        }
    }

    cout << "added:\n"; 
    for (int i = 0; i < rows; i++){
        for (int j= 0; j < cols; j++){
            cout << intMatrix1[i][j] << "--\n";
        }
    }



    for (int i = 0; i < rows; ++i) {
        delete[] intMatrix1[i];
        delete[] intMatrix2[i];
        delete[] result[i];
    }
    delete[] intMatrix1;
    delete[] intMatrix2;
    delete[] result;


    cout << "\n\n";
    string str = "Hello *zxc*Classzxc";
    string pattern= "*zxc*";
    if(isPtrnInStr(str, pattern)) cout << "ja\n";
    else cout << "nein\n";

    return 0;
}