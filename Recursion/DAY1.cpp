#include<iostream>
using namespace std;

int factorial(int n){
    if(n == 0){
        return 1;
    }
    return (n*factorial(n-1));
}

int PowerOf2(int n){
    //base case
    if(n == 0){
        return 1;
    }
    //recursive relation
    int smallerProblem = PowerOf2(n-1);
    int biggerProblem = 2*PowerOf2(n-1);
    return biggerProblem;
}

void printCount(int n){
    //base case
    if(n == 0){
        return;
    }
    /*Tail Recursion - first processing then recursive relation
    //Processing
    cout<<n<<" ";
    //Recursive relation
    printCount(n-1);
    */

    //Head Recursion - first recursive and processing
    //Recursive relation
    printCount(n-1);
    //Processing
    cout<<n<<" ";
}

int main(){
    
    /*Factorial through recursion
    int n;
    cin >> n;
    int ans = factorial(n);
    cout<<ans<<endl;
    */
    
    /*Power of 2
    int n;
    cin>>n;
    int ans = PowerOf2(n);
    cout<<ans<<endl;
    */
    
    /*Print Counting - Tail and head Recursion*/
    int n;
    cin >> n;
    printCount(n);
    
    return 0;
}