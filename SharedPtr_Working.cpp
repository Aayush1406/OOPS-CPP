#include<iostream>
#include <memory>

using namespace std;

int main(){

  
    shared_ptr<int> p1(new int(10));
    shared_ptr<int> p2;

    p2 = p1; // both refer to the same memory location . Here both points to the 10
    // p2 = move(p1); // the ownership moves to p2 from p1. p1 now points to null

    cout<<p2.use_count()<<endl; // '2' to find the how many pointers are pointing to a particular res.

    p1.reset(); // now p1 will stop pointing to that particular resource.

    cout<<p2.use_count()<<endl; //'1' only p2 points to 10

    cout<<p1.get()<<endl; //0x0 here p1 is not pointing to any resource

    cout<<p2.get()<<endl; //points to the address of the res it is pointing to.
}