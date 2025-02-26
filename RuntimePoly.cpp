// if we don't use the virtual keyword in the base class than the function call binding will be done at the 
// compile time and it will bind the function call to the type of pointer (Animal* a) in this case.
//and so we use the keyword called virtual in the Animal class to do late Binding that means the call
// for which sound() to call will be done at the runtime which will be seeing that there is new Dog() so 
// it will call the sound() of the Dog class
#include<iostream>

using namespace std;

class Animal{

    public:
    virtual void sound(){
        cout<<"hu hu";
    }
};

class Dog: public Animal{
    public:
    void sound(){
        cout<<"Bow Bow";
    }
};

int main(){
    Dog d;
    Animal* a = &d;
    a->sound();
    return 0;
}