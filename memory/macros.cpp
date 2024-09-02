#include<iostream>
using namespace std;

#define PI 3.14

int score = 30;

inline int getMax(int&a, int&b){
    return(a>b) ? a : b;
    
}

int main(){

    /*Macros
    int r = 5;
    //double pi = 3.14;
    double area = PI*r*r;
    cout<<"Area is "<<area<<endl;
    */

    /*Global Variables - score
    {
        int score = 20;  //local variable
        cout<<score<<endl; //local variable value
    }
    cout<<score;  //global variable value
    */

    //Inline FUnctions
    int a = 1, b = 2;
    int ans = 0;
    ans = getMax(a,b);
    cout<< ans<<endl;
    
    a += 3;
    b += 1;

    ans = getMax(a,b);
    cout<< ans<<endl;

    return  0;
}