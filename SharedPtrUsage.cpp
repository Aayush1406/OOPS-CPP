#include<iostream>
#include<memory>

using namespace std;


class Tyre{

    public:
    void doRepair(){}
};

class Car{

    private:
        shared_ptr<Tyre> wheel1;
    
    public:
        Car(){  
            wheel1 = make_shared<Tyre>();
        }
        
        shared_ptr<Tyre>& getWheel1(){
            return wheel1; //safe as long as the Car object exist.
        }

        // Never return a reference to a temporary object because the temporary 
        // object is destroyed at the end of the expression.
        // shared_ptr<Tyre>& getWheel1(){
            // Tyre localtyre //this localtyre is local obj which will get destroyed when  
            // return localtyre; //fun exits.
        // }

};
int main(){

    Car c;
    shared_ptr<Tyre>& wheel1 = c.getWheel1();
    cout<<wheel1.use_count();
}