#include <bits/stdc++.h>
using namespace std;

class Human{

    protected:
        string name;
        int age;

    public:

        Human(string name, int age){
            cout<<"Human constructor called !"<<endl;
            this->name = name;
            this->age = age;
        }

        void work(){
            cout<<"I am working !"<<endl;
        }

        virtual void display(){
            cout<<"name = "<<name<<" age = "<<age<<endl;
        }

        virtual ~Human(){
            cout<<"Human destructor"<<endl;
        }
};

class Student: public Human{

    protected:
        int id;

    public:
        Student(int id, string name, int age): Human(name, age){
            cout<<"Student constructor called !"<<endl;
            this->id = id;
        }

        void display(){
            cout<<"name = "<<name<<" age = "<<age<<" id = "<<id<<endl;
        }

        ~Student(){
            cout<<"Student destructor"<<endl;
        }

};


int main(){

    Human* h = new Student(44,"Aayush", 25);

    h->display();

    delete h;

    return 0;
}
