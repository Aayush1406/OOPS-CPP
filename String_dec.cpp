#include <bits/stdc++.h>
using namespace std;

int main(){

    char ch1[] = "Aayush"; // created on stack, size = 7 (6 char + \0), 
    char* ch2 = "Aayush"; // read only memory, modifying it gives undefined behavior, 
    char ch3[7] = "Aayush"; // same as 1st, size explicitly given.
    char* ch = new char[7];// created on heap, used when only size is know at runtime
    strcpy(ch,"Aayush");
    string s = "Aayush";

}
