#include <iostream>
using namespace std;
 
class Num
{
protected:
    int num;
public:
    Num(int n): num(n){};
    virtual void shownum()
    {
        cout << "Initial number: " << num << endl;
    }
};
 
class outhex: public Num
{
public:
    outhex(int n): Num(n){};
    void shownum()
    {
        cout << "Number [hex] : " << hex << num << endl;
    }
};
 
class outoct: public Num
{
public:
    outoct(int n): Num(n){};
 
    void shownum()
    {
        cout << "Number [oct]: " << oct << num << endl;
    }
};
 
 
 
int main()
{
    Num obj1 = Num(255);
    outhex obj2 = outhex(255);
    outoct obj3 = outoct(255);
 
    obj1.shownum();
    obj2.shownum();
    obj3.shownum();
    
    return 0;
}
