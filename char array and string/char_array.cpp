#include<iostream>
#include<algorithm>
using namespace std;

char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }else{
        return ch+32;// 'a' - 'A' = 32
    }
}

int getLength(char name[]){
    int i = 0;
    while(name[i] != '\0'){
        i++;
    }
    return i;
}

void reverse(char name[]){
    int n = getLength(name);
    for(int i = 0; i < n/2; i++){
        swap(name[i],name[n-1-i]);
    }
}

bool check_palindrome(char word[]){
    int n = getLength(word);
    int s = 0, e = n-1;
    while(s<e){
        if(word[s] != word[e]){
            return false;
        }
        s++,e--;
    }
    return true;
}

int main(){

    /*char arr[15] = "Hello Everyone";
    cout<<arr<<endl;
    char arr1[15] = "a\0b\0";
    cout<<arr1;*/

    char name[20];
    cout<<"Enter your name : ";
    cin >> name;
    cout<<"Your name is : "<<name<<endl;

    /*Length of string
    
    cout<<"Length : "<<getLength(name);*/
    
    /*Reverse ch array
    reverse(name);
    cout<<"Reverse : "<<name<<endl;*/

    /*Palindrome - if reverse array is same as org
    //Case sensitive
    for(int i = 0; i < getLength(name); i++){
        name[i] = toLowerCase(name[i]);
    }
    //not case sensitive
    if(check_palindrome(name)){
        cout<<name<<" is palindrome";
    }else{
        cout<<name<<" is not palindrome";
    }*/

    



    return 0;

}