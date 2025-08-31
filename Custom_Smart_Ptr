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

};


int main(){

    SmartPointer p(new int(5)); 

    cout<<p.getValue()<<endl; // 5

    p.setValue(100);

    cout<<p.getValue()<<endl; // 100

    *p = 13;

    cout<<*p<<endl; // 13

    cout<<p.getValue()<<endl; //13

    
    return 0;
}
