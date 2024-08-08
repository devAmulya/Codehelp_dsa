#include<iostream>
#include<map>
using namespace std;

int main(){

    map<int,string> m;

    m[1] = "babbar";
    m[2] = "love";
    m[3] = "kumar";

    m.insert({5,"Bheem"});

    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"find 13 : "<<m.count(13)<<endl;
    m.erase(3);
    cout<<"after erase"<<endl;
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    auto it = m.find(2);
    for(auto i = it; i != m.end(); i++){
        cout<<(*i).first<<endl;
    }
}