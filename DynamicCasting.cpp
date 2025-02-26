// Generally used when we want to do downcasting.
// Downcasting - converting a base class ptr to derived class ptr only if the obj is of the derived type. 
// Downcasting can be unsafe so we need to verify the actual object's type by doing dynamic_cast<>();

// Upcasting - converting a derived class ptr to the base class ptr. It is always safe.
// Upcasting - only possible when the inheirtanc of dericed class is public.

//static_cast - happens at compile time.
//dynamic_cast - happens at runtime. (we need virtual keyword to support runtime polymorphism).


#include<iostream>

using namespace std;

class Base{virtual void fun(){}};

class Derived: public Base{};

int main(){

   Base* b = new Derived(); // implicit upcasting.

   Derived* d = dynamic_cast<Derived*>(b); // safe downcasting.
   
   Base* b2 = new Base();

   Derived* d = dynamic_cast<Derived*>(b2); // returns nullptr as the b2 is poiting to the obj of Base class
}