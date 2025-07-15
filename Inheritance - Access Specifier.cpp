#include<bits/stdc++.h>

using namespace std;

class A{

    public:
        int a;
    protected:
        int b;
    private:
        int c;

};

class B: public A{

    // a = public
    // b = protected
    // c = not inherited
    void f(){
        cout<<b;
        cout<<a;
        // cout<<c;
    }
};

class C: private A{

    // a = private
    // b = private
    // c = not inherited
    void f(){
        cout<<b;
        cout<<a;
        // cout<<c;
    }

};

class D: protected A{

    // a = protected
    // b = protected
    // c = not inherited
    void f(){
        cout<<b;
        cout<<a;
        // cout<<c;
    }

};

int main(){

    // b = protected and c = private
    B* b= new B();    
    b->a;
    // b->b; 
    // b->c;

    // a, b, and c access not allowed (are private for main)
    C* c = new C();
    // c->a;
    // c->b;
    // c->c;

    // a, b, and c access not allowed (are protected for main)
    D* d = new D();
    // c->a;
    // c->b;
    // c->c;

}
