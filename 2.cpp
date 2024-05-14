#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
    ifstream source("task2(1).txt");
    ofstream destination("task2(2).txt");

    if (!source.is_open() || !destination.is_open())
    {
        cout << "Error!" << endl;
        return 1;
    }

    char c;
    while (source.get(c))
    {
        if (c == '\t')
        {
            destination << ' ';
        }
        else
        {
            destination << c;
        }
    }

    source.close();
    destination.close();
    cout << "File has been successfully copied with tabs replaced by spaces." << endl;
    return 0;
}
