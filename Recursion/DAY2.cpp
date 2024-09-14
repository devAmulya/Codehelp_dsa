#include<iostream>
#include<string>
using namespace std;

int fib(int n) {
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    int fn = fib(n-1)+fib(n-2);
    return fn;
}

int NoOfDistinctWay(long long n){
    if(n<0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    int fn = NoOfDistinctWay(n-1) + NoOfDistinctWay(n-2);
    return fn;
}

void SayDigit(int n){
    if(n <= 0){
        return;
    }
    string arr[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    SayDigit(n/10);
    int d = n%10;
    cout<<arr[d]<<" ";
}

int main(){

    //fibonacci number
    cout<<fib(6)<<endl;
    //Count distinct way to climb stair
    cout<<NoOfDistinctWay(4);
    //Say digit 432 - four three two
    int n;
    cin>>n;
    SayDigit(n);


    return 0;
}