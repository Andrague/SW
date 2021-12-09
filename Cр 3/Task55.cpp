#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <iostream> 
#include <string> 
#include <iomanip> 
#include <conio.h>  
#include <fstream>  
#include <stdlib.h> 
#include <string.h>
#include <stdio.h>
using namespace std;

struct Task1 {
    string f1 = "";
    int f2 = 0;
    double f3 = 0.0;
    int f4 = 0;
};
Task1* s;
bool is_file_exist(const char* fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

int getFileStringLength(const char* fileName) {
    int strCount = 0;
    ifstream fin;
    if (is_file_exist(fileName)) {
        fin.open(fileName);
        char c;
        while (fin.get(c)) {         // циклом посимвольно читаем
            if (c == '\n') strCount++; //учитываем конец строк - обычно игнорируется как символ
        }
        fin.close();
        return strCount;
    }
}

int main()
{

    fstream file;
    int N;
    string str = "";
    int length = 0;
    const char* fileName = "test.txt";
    ofstream fout;
    ifstream fin;

    system("chcp 1251");

    N= getFileStringLength(fileName);
    cout << "String counted :" << N << endl;
    s = new  Task1[N];

    if (is_file_exist(fileName)) {
        fin.open(fileName);
        for (int i = 0; i < N; i++) {
            fin >> s[i].f1 >> s[i].f2 >> s[i].f3 >> s[i].f4;
            cout << s[i].f1 << ' ' << s[i].f2 << ' ' << s[i].f3 << ' ' << s[i].f4 << endl;
        }
        fin.close();
    }
    cout << "Read from file" << endl;

    int i = 0, j = 0;
    Task1 stemp;
    for (int i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            if (s[i].f2 > s[j].f2) {
                stemp = s[i];
                s[i] = s[j];
                s[j] = stemp;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            cout << "string" << '\t' << "int" << '\t' << "double" << '\t' << "int" << endl;
        }
        cout << s[i].f1 << '\t' << s[i].f2 << '\t' << s[i].f3 << '\t' << s[i].f4 << endl;
    }

    if (is_file_exist(fileName)) {
        remove(fileName);
    }

    cout << "Saving to file" << endl;

    fout.open(fileName);
    cout << "string" << '\t' << "int" << '\t' << "double" << '\t' << "int" << endl;
    for (int i = 0; i < N; i++) {
        fout << s[i].f1 << ' ' << s[i].f2 << ' ' << s[i].f3 << ' ' << s[i].f4 << endl;
        cout << s[i].f1 << '\t' << s[i].f2 << '\t' << s[i].f3 << '\t' << s[i].f4 << endl;
    }
    fout.close();

    cout << "Saving direc array to file" << endl;
    fout.open(fileName, std::ios_base::app);
    for (int i = 0; i < N; i++) {
        fout << s[i].f1 << ' ' << s[i].f2 << ' ' << s[i].f3 << ' ' << s[i].f4 << endl;
        cout << s[i].f1 << ' ' << s[i].f2 << ' ' << s[i].f3 << ' ' << s[i].f4 << endl;
    }
    fout.close();
    

    //cсчитаем размер файла
    if (is_file_exist(fileName)) {
        fin.open(fileName);
        char c;
        while (fin.get(c)) {         // циклом посимвольно читаем
            length++;
            if (c == '\n') length++; //учитываем конец строк - обычно игнорируется как символ
        }
        fin.close();
    }
    cout << "\nSize of:" << ' ' << length << endl;
    
}

