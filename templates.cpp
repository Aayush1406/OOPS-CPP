#include<bits/stdc++.h>

using namespace std;



template<class X>
class ArrayList{

    private:
        struct ControlBlock{
            int capacity;
            X *arr_ptr;
        };

        ControlBlock* s;

        public:
            ArrayList(int capacity){ 

                s = new ControlBlock();
                s->capacity = capacity;
                s->arr_ptr = new X[s->capacity];
            }
            
            void addElement(int index, X data){
                if(index>=0&&index<s->capacity){
                    *(s->arr_ptr+index) = data;
                }else{
                    cout<<"Please enter index within range !"<<endl;
                }
            }

            X viewElement(int index){
                if(index>=0 && index<s->capacity){
                    return s->arr_ptr[index];
                }else{
                    return -1;
                }
            }

            void viewList(){
                for(int i=0;i<s->capacity;i++){
                    cout<<s->arr_ptr[i]<<endl;
                }
            }    
            
            ~ArrayList(){
                delete[] s->arr_ptr;
                delete s;
            }
};

int main(){

    ArrayList<float> ls1(5);
    ls1.addElement(0,3.7);
    ls1.addElement(1,2.5);
    ls1.addElement(2,5);
    ls1.addElement(3,7);
    ls1.addElement(4,9);

    ls1.viewList();
    return 0;
}
