#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

string adjdup1(string s){
    bool flag = true;
    while(true){
        int i = 0;
        while(s[i] != s[i+1] && i < s.size()){
            i++;
            if(i == s.size() - 1){
                flag = false;
                break;
            }
        }
        if(flag){
            s.erase(i,2);
        }
        else {
            break;
        }
    }
    return s;

}

string adjdup(string s){
    string s1;
    int i = 0;
    while(i<s.length()){
        if(s.empty() || s[i] != s1.back()){
            s1.push_back(s[i]);
        }else{
            s1.pop_back();
        }
        i++;
    }
    return s1;
}

void rev(vector <char>&s){
    //Reverse entire string
    reverse(s.begin(), s.end());
        
    //Reverse each wordd
    int start = 0;
    for (int end = 0; end <= s.size(); ++end) {
    // If we reach a space or the end of the string
        if (end == s.size() || s[end] == ' ') {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
    }
}

int main(){
    string s = "abbaca";
    cout<<adjdup(s)<<endl;
    vector <char> s1 = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    rev(s1);
    for(char i : s1){
        cout<<i;
    }

}