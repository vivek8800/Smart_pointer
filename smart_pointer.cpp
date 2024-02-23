/*
Topic: Smart Pointer in C++!!!

Notes:
1. Smart pointer is a class which wraps a raw pointer, to manage the life time of the pointer.
2. The most fundamental job of smart pointer is to remove the chances of memory leak.
3. It makes sure that the object is deleted if it is not referenced any more.

Types:
1. unique_ptq :
Allow only one owner of the underlaying pointer.

2. shared_ptr:
Allows multiple owners of the same pointer (Reference count is Maintained).

3. weak_ptr:
It is special type of shared_prt which doesn't count the reference.

*/

#include<iostream>
using namespace std;

class MyInt{

    
};

int main(){

    return 0;
}