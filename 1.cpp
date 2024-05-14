#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout.setf(ios::uppercase | ios::showpoint | ios::scientific);
    cout << 13579.2468 << endl;
    return 0;
}

