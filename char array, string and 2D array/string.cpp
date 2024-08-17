#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

char getMaxOCCCharacter(string s){
    int arr[26] = {0};
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        if(ch >= 'a' && ch <= 'z'){
            int n = ch - 'a';
            arr[n]++;
        }else{
            int n = ch - 'A';
            arr[n]++;
        }
    }
    int mx = -1;
    char idx;
    for(int i = 0; i < 26; i++){
        if(arr[i] > mx){
            mx = arr[i];
            idx = i + 'a';
        }
    }
    return idx;
}

string removeOcurrences(string s, string part){
    while(s.length() != 0 && s.find(part) < s.length()){
        s.erase(s.find(part),part.length());
    }
    return s;
}

bool checkEqual(int arr1[], int arr2[]){
    for(int i = 0; i < 26; i++){
        if(arr1[i] != arr2[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2){
    int count[26] = {0};
    for(int i = 0; i < s1.length(); i++){
        int index = s1[i] - 'a';
        count[index]++;
    }

    //traverse through s2 in window of size s1 and compare
    int i  = 0;
    int windowSize = s1.size();
    int count2[26] = {0};
    while(i < windowSize){
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    if(checkEqual(count, count2)){
        return 1;
    }

    while(i < s2.length()){
        char newchar = s2[i];
        int index = newchar - 'a';
        count2[index]++;

        char oldchar = s2[i-windowSize];
        index = oldchar - 'a';
        count2[index]--;
        if(checkEqual(count, count2)){
            return 1;
        }
        i++;

    }
    return 0;
}

int compress(vector<char>& chars){
    int i = 0;
    int ansIndex = 0;
    int n = chars.size();
    while(i<n){
        int j = i + 1;
        while(j<n && chars[i] == chars[j]){
            j++;
        }
        chars[ansIndex++] = chars[i];
        int count = j-i;
        if(count > 1){
            string cnt = to_string(count);
            for(char ch : cnt){
                chars[ansIndex++] = ch;
            }
        }
        i=j;

    }
    return ansIndex;

}

int main(){

    /*Declaration
    string str;
    str = "hello world";*/

    //Reverse words in a string
    /*get Max Occurence Character
    string s;
    cin >> s;
    cout<<getMaxOCCCharacter(s);*/

    /*Change space to @40
    string s;
    string s1;
    getline(cin,s);
    int n = s.length();
    /*for(int i = 0; i < n; i++){
        if(s[i] == ' '){
            s1 += '@';
            s1 += '4';
            s1 += '0';

        }else{
            s1 += s[i]; 
        }
    }
    cout<<s1;*/

    //inplace space : O(n)

    //Remove ALl occurences of a substring

    /*string s;
    getline(cin,s);
    string part;
    getline(cin,part);
    cout<<removeOcurrences(s,part);*/

    /*Permutation in strin
    string s1;
    getline(cin,s1);
    string s2;
    getline(cin,s2);
    if(checkInclusion(s1,s2))
        cout<<"true";
    */


    return 0;
}