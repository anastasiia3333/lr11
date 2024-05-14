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
        cout << "\nAllocation error.\n";
        exit(1);
    }
    item->num = i;
    if (tail)
    {
        tail->next = item;
    }
    tail = item;
    item->next = NULL;
    if (!head)
    {
        head = tail;
    }
}
int queue::retrieve()
{
    int i;
    list *p;
    if (!head)
    {
        cout << "\nList is empty.\n";
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
        cout << "\nAllocation error.\n";
        exit(1);
    }
    item->num = i;
    if (head)
    {
        item->next = head;
    }
    head = item;
    if (!tail)
    {
        tail = head;
    }
}
int stack::retrieve()
{
    int i;
    list *p;
    if (!head)
    {
        cout << "\nList is empty.\n";
        return 0;
    }
    i = head->num;
    p = head;
    head = head->next;
    delete p;
    return i;
}
 
class sorted : public list
{
public:
    void store(int i);
    int retrieve();
};
 
void sorted::store(int i)
{
    list *item;
    item = new sorted;
    if (!item)
    {
        cout << "\nAllocation error.\n";
        exit(1);
    }
    item->num = i;
 
    list **pp;
    for (pp = &head; *pp && (*pp)->num < i; pp = &((*pp)->next)) {}
    item->next = *pp;
    *pp = item;
 
    if (!tail)
    {
        tail = item;
    }
}
 
int sorted::retrieve()
{
    int i;
    list *p;
    if (!head)
    {
        cout << "\nList is empty.\n";
        return 0;
    }
    i = head->num;
    p = head;
    head = head->next;
    delete p;
    return i;
}
 
int main()
{
    list *p;
    queue q_ob;
    stack s_ob;
    sorted r_ob;
    char ch;
    for (int i = 0; i < 10; i++)
    {
        cout << "Stack, Queue or Sorted? (S/Q/R):";
        cin >> ch;
        ch = tolower(ch);
        if (ch == 'q')
            p = &q_ob;
        else if (ch == 'r')
            p = &r_ob;
        else
            p = &s_ob;
        p->store(i);
    }
 
    cout << "Enter T to terminate\n";
    for (;;)
    {
        cout << "Remove from Stack, Queue or Sorted? (S/Q/R):";
        cin >> ch;
        ch = tolower(ch);
        if (ch == 't')
            break;
        if (ch == 'q')
            p = &q_ob;
        else if (ch == 'r')
            p = &r_ob;
        else
            p = &s_ob;
        cout << p->retrieve() << '\n';
    }
    cout << '\n';
    return 0;
}
