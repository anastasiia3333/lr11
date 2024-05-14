#include <iostream>
#include <cstdlib> 
using namespace std;
 
class list
{
public:
    list *head; 
    list *tail; 
    list *next; 
    int num; 
    list() { head = tail = next = NULL; }
    virtual ~list() {} 
    virtual void store(int i) = 0;
    virtual int retrieve() = 0;
    void operator+(int i);
    int operator-();
};
 
class queue : public list
{
public:
    void store(int i);
    int retrieve();
};
 
void queue::store(int i)
{
    list *item;
    item = new queue;
    if (!item)
    {
        cout << "Allocation error.\n";
        exit(1);
    }
    item->num = i;
    
    if (tail){
        tail->next = item;
    }
    tail = item;
    item->next = NULL;
    if (!head){
        head = tail;
    }
}
 
int queue::retrieve()
{
    int i;
    list *p;
    if (!head)
    {
        cout << "List empty.\n";
        return 0;
    }
   

    i = head->num;
    p = head;
    head = head->next;
    delete p;
    return i;
}
 

class stack : public list
{
public:
    void store(int i);
    int retrieve();
};
 
void stack::store(int i)
{
    list *item;
    item = new stack;
    if (!item)
    {
        cout << "Allocation error.\n";
        exit(1);
    }
    item->num = i;
    
    if (head){
        item->next = head;
    }
    head = item;
    if (!tail){
        tail = head;
    }
}
 
int stack::retrieve()
{
    int i;
    list *p;
    if (!head)
    {
        cout << "List empty.\n";
        return 0;
    }
    i = head->num;
    p = head;
    head = head->next;
    delete p;
    return i;
}
 
void list::operator+(int i)
{
    store(i);
}
 
int list::operator-()
{
    return retrieve();
}
 
int main()
{
    list *p;
    queue q_ob;
    p = &q_ob; 
    *p + 2;
    *p + 4;
    *p + 6;
    cout << "Queue: ";
    cout << -(*p);
    cout << -(*p);
    cout << -(*p);
    cout << '\n';
    stack s_ob;
    p = &s_ob; 
    *p + 2;
    *p + 4;
    *p + 6;
    cout << "Stack: ";
    cout << -(*p);
    cout << -(*p);
    cout << -(*p);
    cout << '\n';
    return 0;
}
