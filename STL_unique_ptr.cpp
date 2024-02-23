#include<iostream>
#include<memory>
using namespace std;

class Base
{
    int x;

    public:

    Base(int y):x{y}{}

    void setx()
    {
        this->x+=56;
    }

    void show()
    {
        cout<<x<<endl;
    }

    ~Base()
    {
        cout<<"Destructor called"<<endl;
    }
};


int main()
{    
    unique_ptr<Base> b (new Base(20));
    b->setx();
    b->show();

    unique_ptr<Base> p2 = move(b); 
    p2->show();

    return 0;
}