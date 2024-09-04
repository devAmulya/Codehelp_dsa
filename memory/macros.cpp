#include<iostream>
using namespace std;

#define PI 3.14

int score = 30;

inline int getMax(int&a, int&b){
    return(a>b) ? a : b; 
}

void print(int arr[], int n  , int start = 0) {

    for(int i = start; i<n; i++) {
        cout << arr[i] << endl;
    }

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

    /*Inline FUnctions
    int a = 1, b = 2;
    int ans = 0;
    ans = getMax(a,b);
    cout<< ans<<endl;
    
    a += 3;
    b += 1;

    ans = getMax(a,b);
    cout<< ans<<endl;
    */

    /*default arguments
    int arr[5] = {1,4,7,8,9};
    int size = 5;

    print(arr, size);
    cout << endl;
    print(arr, size, 2);
    */
    

    return  0;
}