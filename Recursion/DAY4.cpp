#include<iostream>
#include<string>
using namespace std;

void reverseString(string& s, int i){
    int size = s.size();
    if(i == size/2){
        return;
    }
    char temp = s[i]; 
    s[i] = s[size-i-1];
    s[size-i-1] = temp;
    reverseString(s,i+1);
}

bool palindrome(string s, int i){
    int n = s.size();
    if(i >= n/2){
        return true;
    }
    if(s[i] != s[n-i-1]){
        return false;
    }
    bool ans = palindrome(s,i+1);
    return ans;
}

int power(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }
    int ans = power(a,b/2);
    if(b%2 == 0){
        return ans*ans;
    }else{
        return a*ans*ans;
    }
}

void bubble_sort(int arr[], int size){
    if(size == 0 || size == 1){
        return;
    }
    for(int i = 0; i < size; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubble_sort(arr,size-1);
}

int main(){

    /*Reverse String
    string s = "abcdef";
    reverseString(s,0);
    cout<<s;
    */

    /*Check Palindrome
    string s = "abca";
    cout<<palindrome(s,0);
    */

    /*power
    cout<<power(2,5);
    */

    //Bubble sort
    int arr[] = {2,1,8,3,9,4};
    bubble_sort(arr,6);
    for(int i = 0; i < 6; i++){
        cout<<arr[i];
    }


    return 0;
}