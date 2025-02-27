#include<iostream>
#include<string>
#include<memory>
using namespace std;


class Person{

    private:
    string name;
    int age;

    public:
    Person(){}
    Person(string n, int a) {
        cout<<"Constructor called!"<<endl;
        this->name = n;
        this->age = a;
    }

    Person(Person& p){
        cout<<"Copy constructor called !"<<endl;
        name = p.name;
        age = p.age;
    }
    // if we declare return type as Person than a copy constructor will be called.
    // Person operator=(Person& p) { } it will return by value and by value always create a copy of the obj passed or returned
    Person& operator = (const Person &p){
        // we cannot compare *this with p as comparison with obj is not allowed.
        if(this!=&p){
            this->age = p.age;
            this->name = p.name;
        }

        return *this;
    }

    // Destructor - called automatically when obj. goes out of scope.
    // useful for obj. creation on stack. As the obj goes out of the scope stack gets cleared and obj gets deleted
    // In heap the ptr pointing to obj gets deleted as it is on stack but the obj itself is not deleted.
    // we have to explicitly delete it using delete keyword.
    // To solve this smart ptrs or shared ptrs are also used.
    ~Person(){
        cout<<"Destructor called for name = "<<name<<endl;
    }

    void display(){
        cout<<"Name = "<<name<<" age = "<<age<<endl;
    }

    string getName(){
        return name;
    }

};

void demonstratePassByValue(Person p){ //will call the copy constructor here
    cout<<"Inside demonstrate Pass By value "<<p.getName()<<endl;
}

// we cannot have return type as Person& as p is local obj to the fun which will get destroyed when returned
// Even if we do it will create obj-> call destructor as it scope ends-> 
// when assigned like Person p6  = createPerson() it will call the copy constructor which will throw
// throw segmentation error as the location is not valid anymore.
Person createPerson(string name, int age){
    cout<<"Person creation"<<endl;
    Person p(name,age);
    return p;
}

int main(){
    cout<<"-----Stack Allocation-----"<<endl;
   /* {
        // exist on stack
        Person p1("Aayush", 25);
        p1.display();

        // // By default the copy constructor created by the compiler in cpp.
        // // copy constructor is called.
        Person p2 = p1;
        p2.display();

        Person p3("Meet", 26);
        
        //Copy Constructor will be called - whenever we pass obj by value to the fun call.
        //here the demonstratePassByValue(Person p) will have its own separate copy of p.
        demonstratePassByValue(p3); // Person p = p3 . Will call the copy constructor for Person(Person &p3)
        // so we have 2 obj here p and p3 so 2 times destructor will be called.
       

        Person p4 = createPerson("Shrey", 24);
        p4.display();

        Person p5;
        p5 = p4;
    } */

    // cout<<"----Heap Allocation----"<<endl;
    // {   
    //     //*p is created on stack.
    //     // obj exist on heap.
    //     Person* p = new Person("Rohit", 23);
    //     p->display();
    //     Person* p2 = new Person[3]{
    //         Person("Meet",26), Person("Rohan",33),Person("Shaun",45)
    //     }; // Allocate memory for 3 Person objects
    //     p2->display();
    //     // Will call the destructors
    //     delete p;
    //     delete[] p2;
    // }
    cout<<"----Smart pointers----"<<endl;
    {   ///Destructor called automatically when p6 goes out of the scope. 
        // unique ptr is used whenever we want only a single ptr for a particular resource.
        unique_ptr<Person> p6 = make_unique<Person>("Jack", 42);
        p6->display();
    }
}




// ***Passing primitive types (eg: int, float, char, etc) by value. 
// 1. For primitive types, passing by val creates copy of the variable.
//  eg:

// void f(int x){
//     x = 100;
// }

// main(){
//     int a = 10;
//     f(a); // copy of a is created and passed (pass by value). 
//     cout<<a; // a remain unchanged !
//     return 0; 
// }

// ***Passing Object by Value
// 1. For object, passing by value invokes copy constructor to create a copy of the obj.
// eg:
// class Person {
// public:
//     string name;
//     int age;

//     Person(string n, int a) : name(n), age(a) {}

//     Person(Person p) {
//         name = p.name;
//         age = p.age;
//         cout << "Copy constructor called!" << endl;
//     }
// };

// int main() {
//     Person p1("Alice", 25);
//     Person p2 = p1; 
// Copy constructor Person(Person p){} is called to initialize p2 with p1.
// The compiler also need to create a copy of p1 to pass it as an arg to p.
// Person p = p1;  
// Person p = p1; 
// Person p = p1; .... and so on
// }
// So pass p1 as a ref so that no copy of p1 is created when calling the copy constructor.
