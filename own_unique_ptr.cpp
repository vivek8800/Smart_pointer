#include<iostream>
using namespace std;

class Base
{
    int x;
    
    public:
    
    Base(){}
    
    Base(int x)
    {
        this->x = x;
    }
    
    void display()
    {
        cout<<"Value of x is : "<<x<<endl;
    }
};

template<class T>
class unique
{
    T *p;
    
    public:
    
    // default constructor
    unique(){}
    
    // perametrized ctr
    unique(T *obj)
    {
        this->p = obj;
    }
    
    // overloaded * operator
    T & operator *()
    {
        return *p;
    }
       
    // overloaded -> operator
    T * operator ->()
    {
        return p;
    }
    
    // delete copy constructor
    unique(unique &rhs) = delete;
    
    // delete assignment operator
    unique operator = (unique &rhs) = delete;
    
    // move constructor
    unique(unique &&rhs)
    {
        // assign the value to current object
        this->p = rhs.p;
        
        // need to point to null of previous object
        rhs.p = nullptr;
    }
    
    // move assignment operator
    unique & operator = (unique && rhs)
    {
        // assign the value to current object
        this->p = rhs.p;
        
        // need to point to null of previous object
        rhs.p = nullptr;
    }
};

int main()
{
    /*
    // This will work when using another class (like Base{}) with template unique pointer
    
    unique<Base> b1(new Base(70));
    b1->display();
    
    cout<<"Create another object and move the ownership"<<endl;
    
    unique<Base> b2 = move(b1);
    b2->display();
    
    cout<<"As b1 object data is moved so program will crash after this!!!"<<endl;
    b1->display();
    */
    
//***************This will work for template unique class only*****!!!use any one either above or bottom one!!!***************

    // created object dynamically
    int *p1=new int;
    
    // Assign the value
    *p1=40;
    
    cout<<"Unique pointer"<<endl<<endl;
    unique<int> obj1(p1);
    
    cout<<"Printing the value of obj1: ";
    cout<<*obj1<<endl<<endl;
    
    cout<<"Another object created"<<endl<<endl;
    unique<int> obj2=move(obj1);
    
    cout<<"Printing the value of obj2: ";
    cout<<*obj2<<endl<<endl;
    
    cout<<"Printing the value of obj1 after moving data to obj2 : 'Nothing will print as object data is moved' "<<endl;
    cout<<*obj1<<endl;
    
    return 0;
}
