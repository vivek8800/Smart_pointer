// Implementation of own Shared pointer

#include<iostream>
using namespace std;

template<class T>
class shared
{
    T *p;
    static int nResCount;
    
    public:
    
    shared()
    {
        cout<<"Default Constructor called"<<endl<<endl;
    }
    
    shared(T *p)
    {
        cout<<"Perametrized Constructor called"<<endl<<endl;        
        this->p=p;
    }
    
    shared(shared &rhs)
    {
        nResCount++;
        this->p=rhs.p;
    }
    
    shared & operator = (shared &rhs)
    {
        cout<<"Assignment operator called"<<endl<<endl;
        nResCount++;
        this->p=rhs.p;
        return *this;
    }
    
    shared(shared &&rhs)
    {
        cout<<"Move Constructor called"<<endl<<endl;
        // dont need to increase resurce count
        this->p=rhs.p;
        rhs.p=nullptr;
    }
    
    shared & operator = (shared &&rhs)
    {
        // dont need to increase resurce count
        this->p=rhs.p;
        rhs.p=nullptr;
    }
    
    T & operator *()
    {
        return *p;
    }
    
    T & operator ->()
    {
        return p;
    }
    
    ~shared()
    {
        cout<<"Destructor called"<<endl<<endl;
    }
};

template<class T>
int shared<T>::nResCount=0;

int main()
{
    // created object
    int *p1=new int;
    
    // assigned value
    *p1=100;
    
    // created first shared pointer
    shared<int> sp1(p1);
    cout<<"sp1 object: ";
    cout<<*sp1<<endl<<endl;
    
    cout<<"Copied sp1 data to sp2: copy ctr called"<<endl<<endl;
    // Created second shared pointer
    shared<int> sp2(sp1);
    
    cout<<"sp2 object: ";
    cout<<*sp2<<endl<<endl;
    
    cout<<"sp1 object: ";
    cout<<*sp1<<endl<<endl;
    
    // Created third shared pointer
    shared<int> sp3;
    
    cout<<"Copied sp2 data to sp3: Assignment operator called"<<endl<<endl;
    sp3=sp2;
    
    cout<<"sp2 object: ";
    cout<<*sp2<<endl<<endl;
    
    cout<<"sp3 object: ";
    cout<<*sp3<<endl<<endl;
    
    cout<<"Moved sp1 data to sp4: Move Assignment operator called"<<endl<<endl; 
    // Created fourth shared pointer
    shared<int>sp4=move(sp1);
    
    cout<<"sp4 object: ";
    cout<<*sp4<<endl<<endl;
    
    cout<<"sp1 object: nothing will print and system will crash bc'z data already moved "<<endl<<endl;
    // cout<<*sp1<<endl<<endl;      // if uncomment then program will crash and destructor will not call
    
    /*
    while creating object Constructor called as follows:
    1. Perametrized Constructor called
    2. copy Constructor called
    3. copy assignment operator called
    4. move Constructor called
    
    So, destructor is called four times because of four instances of the shared class being created
    */
    return 0;
}