#include<iostream>
using namespace std;

int main(){

    int value = 5;
    int *ptr = &value;
    int **ptr2 = &ptr; //Double Pointer

    cout<<"printing ptr : "<<ptr<<endl;
    cout<<"addres pf ptr : "<<&ptr<<endl;
    cout<<*ptr2<<endl;

}