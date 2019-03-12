#include <iostream>
#include <memory>
#include <map>

using namespace std;

class A
{
public:
    A(){ cout << "A()\n";}
    ~A() { cout << "~A()\n";}
};


typedef shared_ptr<A> Aptr;

int main()
{
    map<int, Aptr> map;
    Aptr t(new A());
    map[1] = t;
    map.erase(1);
    
}

