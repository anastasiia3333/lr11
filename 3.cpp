#include <iostream>
#include <fstream>
using namespace std;
 
int main() 
{
    ifstream file("task3.txt");
    if (!file) 
    {
        cout << "Error!" << endl;
        return 1;
    }
    string word;
    cout << "Enter a word that will be found in the text: ";
    cin >> word;
    int count= 0;
    string str;
    while (file >> str) 
    {
        if (str == word)
        {
            count++;
        }
    }
    cout << "We found: " << count << " word(-s)." <<  endl;
    file.close();
    return 0;
}
