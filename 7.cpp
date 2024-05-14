#include <iostream>
using namespace std;
 
// class area
// {
//     double dim1, dim2;
 
// public:
//     void setarea(double d1, double d2)
//     {
//         dim1 = d1;
//         dim2 = d2;
//     }

//     void getdim(double &d1, double &d2)
//     {
//         d1 = dim1;
//         d2 = dim2;
//     }
//     virtual double getarea() = 0;
// };

// class rectangle : public area
// {
// public:
//     double getarea()
//     {
//         double d1, d2;
//         getdim(d1, d2);
//         return d1 * d2;
//     }
// };

// class triangle : public area
// {
// public:
//     double getarea()
//     {
//         double d1, d2;
//         getdim(d1, d2);
//         return 0.5 * d1 * d2;
//     };
// };


// int main()
// {
//     area *p;
//     area q;
//     rectangle r;
//     triangle t;
//     r.setarea(2.1, 3.8);
//     t.setarea(1.9, 7.1);
//     p = &r;
//     cout << "Rectangle's area: " << p->getarea() << endl;
//     p = &t;
//     cout << "Triangle's area: " << p->getarea() << endl;
//     return 0;
// }


class base
{
public:
    virtual void func()
    {
        cout << "Using base version of func()\n";
    }
};
class derived1 : public base
{
public:
    // void func()
    // {
    //     cout << "Using derived1 version of func()\n";
    // }
};
class derived2 : public derived1
{
public:
    // void func()
    // {
    //     cout << "Using derived2 version of func()\n";
    // }
};
int main()
{
    base *p;
    base obj;
    derived1 objd1;
    derived2 objd2;
    p = &obj;
    p->func();
    p = &objd1;
    p->func();
    p = &objd2;
    p->func();
    return 0;
}
