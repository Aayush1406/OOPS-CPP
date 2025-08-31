#include<bits/stdc++.h>

using namespace std;

class Rectangle{

    private:
        int length, breadth;

    public:

        Rectangle(int l, int b){
            this->length = l;
            this->breadth = b;
        }

        int area(){
            return length*breadth;
        }

};


int main(){

    unique_ptr<Rectangle> obj1(new Rectangle(4,5));
    cout<<"obj1 area = "<<obj1->area()<<endl;
    unique_ptr<Rectangle> obj2 = move(obj1); // obj1 internally is nullptr
    cout<<"obj2 area = "<<obj2->area()<<endl;
    
    obj2.reset(new Rectangle(6,7)); // obj2 is set to new Rectanlge(6,7) and the old Rectangle(4,5) is deleted !
    cout<<"obj2 new area"<<obj2->area()<<endl;
    

    shared_ptr<Rectangle> obj3(new Rectangle(2,3));
    shared_ptr<Rectangle> obj4 = obj3;
    cout<<"use cnt = "<<obj4.use_count()<<endl; // 2
    cout<<"obj3 area = "<<obj3->area()<<endl;
    cout<<"obj4 area = "<<obj4->area()<<endl;
    
    obj4.reset(new Rectangle(5,5));
    cout<<"use cnt obj3 = "<<obj3.use_count()<<endl; // 1
    cout<<"use cnt obj4 = "<<obj4.use_count()<<endl; // 1

    cout<<"obj3 new area = "<<obj3->area()<<endl; // 6 ref cnt  = 1
    cout<<"obj4 new area = "<<obj4->area()<<endl; // 25 ref cnt = 1

    return 0;

}
