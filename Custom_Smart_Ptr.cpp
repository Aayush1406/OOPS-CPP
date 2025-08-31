#include<bits/stdc++.h>

using namespace std;

class SmartPointer{

    private:
        int* p;

    public:

        SmartPointer(int* ptr){
            p = ptr;
        }

        int getValue(){
            return *p;
        }

        void setValue(int val){
            *p = val;
        }

        ~SmartPointer(){
            delete p;
        }

        int& operator*(){ // returns the heap memory location reference 
            return *p;
        }

        SmartPointer(const SmartPointer& o){
            this->p = new int;
            *(this->p) = *(o.p);
        }

};


int main(){

    SmartPointer p(new int(5)); 

    cout<<p.getValue()<<endl; // 5

    p.setValue(100);

    cout<<p.getValue()<<endl; // 100

    *p = 13;

    cout<<*p<<endl; // 13

    cout<<p.getValue()<<endl; //13

    SmartPointer p2 = p; // shallow copy (copy constructor) is invoked !
    // problem is when p and p2 both goes out of the scope destructor deletes same heap twice
    // which is incorrect and leads to crash !

    *p2 = 9;

    cout<<*p2<<endl;
    
    return 0;
}
