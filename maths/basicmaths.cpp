#include<iostream>
using namespace std;

int countPrimes(int n) {
    if(n < 2) return 0;
    bool *arr = new bool[n];
    for(int i = 0; i < n; i++){
        arr[i] = true;
    }
    
    for(int i = 2; i*i < n; i++){
        if(arr[i]){
            for(int j = i*i; j < n; j = j + i){
                arr[j] = false;
            }
        }
    }
    int count = 0;
    for(int i = 2; i < n; i++){
        if(arr[i]){
            count++;
        }
    }
    delete[] arr; 
    return count;
}

int gcd(int a,int b){
    if(a==0){
        return b;
    }
    if(b == 0){
        return a;
    }
    while(a!=b){
        if(a>b){
            a = a-b;
        }
        else{
            b = b- a;
        }
    }
    return a;
}

int modularExponential(int x, int n, int m){
    int res = 1;
    while(n>0){
        if(n&1){
            res *= x;
        }
        x = x*x;
        n = n >> 1;
    }
    return res; //Use of m if % m solution is needed
}

int main(){
    //Sieve of eothosis
    cout<<countPrimes(10)<<endl;
    
    //GCD
    int a,b;
    cout<<"Enter the values of a and b"<<endl;
    cin >> a >> b;

    int ans = gcd(a,b);

    cout<<"The GCD of "<<a<<" & "<<b<<" is: "<<ans<<endl;

    //Fast Exponential
    cout<<"5 to the power of 10 : "<<modularExponential(5,2,1);


    return 0;
}