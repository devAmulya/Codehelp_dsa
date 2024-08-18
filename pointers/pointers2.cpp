#include<iostream>
using namespace std;

void print(int *p){
    cout << *p << endl;
}

void update(int *p){
    p = p + 1;
    cout<<"inside : "<<p<<endl;
}

int main(){

    /*
    int arr[10] = {2,5,6};
    cout<<"address of first memory block is : "<<arr<<endl;
    cout<<arr[0]<<endl;
    cout<<"address of first memory block is : "<<&arr[0]<<endl;
    cout<<"4th : "<<*arr<<endl;
    cout<<"5th : "<<*arr+1<<endl;
    cout<<"6th : "<<*(arr+1)<<endl;
    cout<<"6th : "<<*(arr+2)<<endl;

    int i = 1;
    cout<<i[arr]<<endl;

    char temp = 'z';
    char *p = &temp;
    cout<<p<<endl;*/

    int value = 5;
    int *p = &value;
    print(p);
    update(p);
    print(p);

    //pointer is pass in a function instead of array

    return 0;
}