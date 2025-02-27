#include<iostream>

using namespace std;
void swap(int *a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int* getLarger(int *a, int *b){
    return (*a>*b) ? a : b;
}
int main(){

    /*

    cout<<"=======Basic Pointers ==========="<<endl;

    int num = 10;
    int *ptr = &num;

    // cout<<*ptr<<endl; // 10;
    // &num == ptr
    cout<<&num<<endl;
    // cout<<ptr<<endl;

    // changing the val of num through ptr.
    *ptr = 123;
    // cout<<num<<endl; // 123
    // add of num still remains the same but value inside changes.
    // cout<<&num<<endl;
*/

/*
    cout<<"=======Pointers Arithmetic==========="<<endl;

    int a[5] = {1,2,3,4,5};
    int *p = a;
    // a has memory addr of 1st location of arr i.e. "1"
    cout<<*p<<endl; // 0th el
    cout<<*(p+1)<<endl; // 1st el
    cout<<*(p+2)<<endl; // 2nd el
    cout<<*(p+3)<<endl; // 3st el

    // Rule : add / sub int from ptr moves ptr by [integer * sizeOf (data type)]
    // Multiplication and Division are not applicable on ptr.

    // p = p + 3; //  adding 3 to ptr base addr. Ptr now points to the 4th location.
    // cout<<*p<<endl; //4 

    // p = p-1; // Ptr now points to 1 loc. back that is the 2nd location.
    // cout<<*p<<endl;  
*/

/*
    cout<<"=======Pointers to Pointer==========="<<endl;

    // int num = 42; //0 level
    // Rule  -> a ptr can store addr of a variable/ptr a level just below it
    // int *ptr = &num; // 1st level ptr 
    // int **dptr = &ptr; // 2nd level ptr
    // **dptr = -345;
    // cout<<num<<endl; // -345
    // int ***tptr = &dptr; // 3rd level ptr

    // tptr = &ptr; // 3 level ptr cannot store 1 level ptr.
*/

/*
    cout<<"=======Array - Pointer Reln==========="<<endl;

    int a[5] = {10,20,30,40,50};
    cout<<*a<<endl; // 10
    cout<<*(a+4)<<endl; // 50
*/

/*
    cout<<"=======Array vs Pointer==========="<<endl;

    int a[5] = {1,2,3,4,5};
    int *p = a;
    
    p = p+3;
    cout<<*p<<endl;// 4
    cout<<*a<<endl; // 1
    // arrays are not assignable. Do not support add / sub opn like ptrs.
    // a = a + 3;
    
    // 8 bytes
    // cout<<sizeof(p)<<endl;

    // cout<<sizeof(a)<<endl; //20 bytes
*/

/*
    cout<<"======== Pointers and String==========="<<endl;

    char s[] = "Aayush";
    // cout<<s<<endl; //Aayush

    char *sp = s;
    // cout<<*sp<<endl; // A

    // Traversing string char - by - char using ptr.
    // while(*sp!='\0'){
    //     cout<<*sp<<endl;
    //     sp++;
    // }
*/

/*
    // cout<<"======== Pass by Reference using Pointers ==========="<<endl;

    // int x = 5, y = 10;
    // swap(&x,&y);
    // cout<<"x = "<<x<<endl;
    // cout<<"y = "<<y<<endl;
*/

/*
    cout<<"======== Returning pointer from functions ==========="<<endl;
    int x = 5;
    int y = 10;
    int* ans = getLarger(&x,&y);
    cout<<*ans<<endl;
*/
/*
    cout<<"======== Dynamic Memory Allocation ==========="<<endl;

    // int* p  = (int*)malloc(sizeof(int));
    // if(p==nullptr){
    //     cout<<"Memory allocation failed !";
    // }

    // *p = 100;
    // cout<<" *p = "<<*p<<endl;
    // free(p);

    // Allocates 5*sizeof(int) in single contigous block.  
    // It allocates 20 bytes but is not aware about how many elements are inside. 
    // It just gives total memory size what is asked for.
    // The data so remains uninitialized (garbage value).
    // | 20 bytes |   (5 integers, but values are uninitialized)
    int* malloc_ptr = (int*)malloc(5*sizeof(int));
    if(malloc_ptr==NULL){
        cout<<"Memory allocation failed !"<<endl;
    }

    // for(int i = 0;i<5;i++){
    //     a[i] = i;
    // }

    // for(int i = 0;i<5;i++){
    //     cout<<*(a+i)<<endl;
    // }
    // free (malloc_ptr);

    // allocate memory for each elements nums*size i.e. 20 in this case.
    // all the element location are initialised to 0(the bits are set to 0).
    int* calloc_ptr = (int*)calloc(5,sizeof(int));

    *(calloc_ptr + 0) = 1;
    *(calloc_ptr + 1) = 2;
    *(calloc_ptr + 2) = 3;
    *(calloc_ptr + 3) = 4;
    *(calloc_ptr + 4) = 5;

    // for(int i=0;i<5;i++){
    //     cout<<*(calloc_ptr+i)<<endl;
    // }
    
    // free(calloc_ptr);

    // This resize the block of 5 to block of 10. The first 5 members assigned with calloc
    // remains intact but the extra memory allocated with realloc will be unitialised and will
    // have garbage values. eg: 1 2 3 4 5 0 5996 0 0 0

    calloc_ptr = (int*)realloc(calloc_ptr,10*sizeof(int));
        for(int i=0;i<10;i++){
            cout<<*(calloc_ptr+i)<<endl;
        }
    */

    cout<<"======== Common ptr errors ==========="<<endl;

    // int *ptr; // unintialised ptr / Wild pointer
    //*ptr = 10; // Can override some memory location which this process / prog. doesn't have the right.
    // int* p = nullptr // Best practice
    
    // int* ptr = (int*) malloc (sizeof(int));
    // if you don't write free(ptr) than it will 


    // Dangling ptr - ptr trying to access a memory location that has already been freed.
    // int* ptr = new int(10);
    // delete ptr;  // Memory freed, but ptr still holds the old address
    // cout << *ptr;  // ❌ Undefined behavior (dangling pointer)
        
}

