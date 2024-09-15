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

int main(){

    /*Reverse String
    string s = "abcdef";
    reverseString(s,0);
    cout<<s;
    */

    //Check Palindrome
    


    return 0;
}