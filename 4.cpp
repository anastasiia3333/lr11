#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
    ofstream file("task4.txt", ios::out);

    if (!file) 
    {
        cout << "Error!" << endl;
        return 1;
    }

    string str(80, ' ');
    file << str;
    file.seekp(80, ios::beg);
    file << "Hello";
    file.close();
    cout << "The result was saved to the file.";
    return 0;
}
