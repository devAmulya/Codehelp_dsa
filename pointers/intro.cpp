#include<iostream>
using namespace std;

int main(){

    /*int num = 5;
    cout<<num<<endl;

    //address of operator -&

    cout<<"address of num is : "<<&num<<endl;

    int *ptr = &num;
    cout<<"Address is : "<<ptr<<endl;
    cout<<"Value is : "<<*ptr<<endl;

    double d = 4.3;
    double *p2 = &d;

    cout<<"Address is : "<<p2<<endl;
    cout<<"Value is : "<<*p2<<endl;
    cout<<"size of integer is "<<sizeof(num)<<endl;
    cout<<"size of pointer is "<<sizeof(p2)<<endl;*/

    /*Bad habbit
    //pointer to int is created pointing to some garbage address
    int *p;
    cout<<*p<<endl;*/

    /*Null pointer
    int i = 4;
    int *p = 0;
    p = &i;
    cout<<p<<endl;
    cout<<*p<<endl;*/
    
    /*No change without address
    int num = 5;
    int a = num;
    a++;
    cout<<num<<endl;*/

    /*Change with memory
    int num = 5;
    cout<<num<<endl;
    int *p = &num;
    (*p)++;
    cout<<num<<endl;*/

    /*copying a pointer
    int *q = p;
    cout<<p<<" - "<<q<<endl;
    cout<<*p<<" - "<<*q<<endl;*/

    /*pointer addition
    int i = 3;
    int *t = &i;
    cout<<"before t"<<t<<endl;
    t = t+1;
    cout<<"after t"<<t<<endl;*/

    


    return 0;
}