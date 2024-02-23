#include<iostream>
#include<memory>
using namespace std;

class Base
{
    int x;

public:

    Base(int x):x{x}{}

    void setx()
    {
        this->x=x+7;
    }

    ~Base()
    {
        cout<<"Destructor called"<<endl;
    }
};

int main()
{
    std::shared_ptr<Base> sp(new Base(10));
    
    cout<<sp.use_count()<<endl;
    
    std::shared_ptr<Base> sp1=sp;
    
    cout<<sp.use_count()<<endl;
    
    cout<<sp1.use_count()<<endl;

    return 0;
}
