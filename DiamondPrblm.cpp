#include<iostream>

using namespace std;

class A{

    public:
    A(){
        cout<<"A constrcutor"<<endl;
    }

    ~A(){
        cout<<"A destructor"<<endl;
    }
    void f(){
        cout<<"A";
    }
};

class B: virtual public A{
    public:
    B(){
        cout<<"B constrcutor"<<endl;
    }

    ~B(){
        cout<<"B destructor"<<endl;
    }
    void f(){
        cout<<"B";
    } 
};

class C: virtual public A{
    public:
    C(){
        cout<<"C constrcutor"<<endl;
    }

    ~C(){
        cout<<"C destructor"<<endl;
    }
    void f(){
        cout<<"C";
    }
};

class D: public B, public C{
    public:
    D(){
        cout<<"D constrcutor"<<endl;
    }

    ~D(){
        cout<<"D destructor"<<endl;
    }
    // if D doesn't have the f() 
    void f(){
        cout<<"D"<<endl;
    }
};

int main(){
    // if virtual inheritance is not used
    D obj;
    // 1. A constructor (1st copy)
    // 2. B constructor
    // 3. A constructor (2nd copy)
    // 4. C constructor
    // 5. D constructor
    // 6. D destructor
    // 7. C destructor
    // 8. A destructor 
    // 9. B destructor
    // 10.A destructor

    // The f() func of Class D is called, since Class D overrides the f() function, so it resolves the 
    // ambiguity. If Class D didn't have its own f() function, the compiler would be unable to 
    // decide which show() function to call (from B or C), and this would lead to a compile-time error
    obj.f();

    // If virtual inheritance used
    //1. A constructor
    //1. B constructor
    //1. C constructor
    //1. D constructor
    //1. D destructor
    //1. C destructor
    //1. B destructor
    //1. A destructor

    // The problem of which f() to call in B or C cannot be solved. D has to have impl of f().
}