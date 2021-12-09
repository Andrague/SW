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

struct Task1  {
    string f1 = "";
    int f2 = 0;
    double f3 = 0.0;
    int f4 = 0;
};
Task1 *s;
bool is_file_exist(const char* fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}
int main()
{
    fstream file;
    int N;
    cout << "Enter a number of strings ";
    cin >> N;
    s= new  Task1[N];
    string str = "";
    int length = 0;
    const char* fileName = "test";
    ofstream fout;
    ifstream fin;
   

    for (int i = 0; i < N; i++)
    {
        cout << endl;
        cout << "Enter a string: ";
        cin >> s[i].f1;
        cout << "Enter a int value: ";
        cin >> s[i].f2;
        cout << "Enter a double value: ";
        cin >> s[i].f3;
        cout << "Enter a int value: ";
        cin >> s[i].f4;
        
    }
    int i = 0, j = 0;
    Task1 stemp;
    for (int i = 0; i <N; i++) {
        for (j = i + 1; j <N; j++) {
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
        cout << s[i].f1 << '\t' <<  s[i].f2 << '\t' <<  s[i].f3 << '\t' << s[i].f4 << endl;
    }
    if (is_file_exist("test.txt")) {
        file.clear();
    }

    fout.open(fileName);
    for (int i = 0; i < N; i++) {
        fout << s[i].f1 << ' ' << s[i].f2 << ' ' << s[i].f3 << ' ' << s[i].f4 << endl;
        cout << s[i].f1 << ' ' << s[i].f2 << ' ' << s[i].f3 << ' ' << s[i].f4 << endl;
    }
    fout.close();
    cout << "Saved to file" << endl;

    if (is_file_exist(fileName)) {
        file.clear();
    }
    cout << "Read from file" << endl;


    fout.open(fileName, std::ios_base::app);
    for (int i =0; i<=N-1; i++) {
        fout << s[i].f1 << ' ' << s[i].f2 << ' ' << s[i].f3 << ' ' << s[i].f4 << endl;
        cout << s[i].f1 << ' ' << s[i].f2 << ' ' << s[i].f3 << ' ' << s[i].f4 << endl;
    }
    fout.close();
    cout << "Saved reverse to file" << endl;

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