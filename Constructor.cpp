#include <iostream>

using namespace std;

class A {
public:
  A(){
     cout<<"A default"<<endl;
  }
  A(int a, int b){
    cout<<"A Parameterised"<<endl;
  }
  A(int a, int b, int c){
    cout<<"A Parameterised"<<endl;
  }

  virtual ~A(){
    cout<<"A destructor called"<<endl;
  }
};

class B: public A {
public:
  B(){
     cout<<"B default"<<endl;
  }

  B(int x, int y, int z):   A(x,y,z){
  
    cout<<"B Parameterised"<<endl;
  }
  ~B(){
    cout<<"B destructor called"<<endl;
  }
};
//Constructor -> Base class (first) than Derived class
//Destructor -> Derived class (first) than Base class
int main() {
    
  //  B obj; //A default -> B default -> B destructor -> A destructor.
  //  B obj(1,2,3); //A Parameterised -> B Parameterised -> B destrcuctor -> A destructor.

  // A default -> B default -> A destructor
    A* a = new B();
    //calls only destructor of A, but B's memory is not released.
    //To solve this we can make the destructor of A virtual
    delete a; 
  // A default-> B default -> B destructor -> A destructor.




    return 0;
}