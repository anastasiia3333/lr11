#include <iostream>
#include <iomanip>
using namespace std;
 
class Dist
{
protected:
    double dist;
public:
    Dist(int mile): dist(mile){};
    virtual void trav_time()
    {
        cout << "Trevel time 1: " << setprecision(2) << dist / 60 << " h." << endl;
    }
};
 
class Metric: public Dist
{
public:
    Metric(int km): Dist(km){};
    void trav_time()
    {
        cout << "Trevel time 2: " << setprecision(2) << dist / 100 << " h." << endl;
    }
};
 
 
int main()
{
    Dist obj1 = Dist(20);
    Metric obj2 = Metric(20);
 
    obj1.trav_time();
    obj2.trav_time();
    
    return 0;
}
