#include "iostream"
using namespace std;
#include <fstream>
int main()
{
    cout <<"quá ư là dệ";
    getchar();
    ofstream file;
    file.open("ok.xlsx", ios::app);
    file <<"đẹp zai";
}