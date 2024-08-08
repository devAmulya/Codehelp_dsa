#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v;

    vector<int> a(5,1);

    vector<int> l(a);
    cout<<"print l"<<endl;
    for(int i : l){
        cout<<i<<" "<<endl;
    }

    cout<<"print a"<<endl;
    for(int i : a){
        cout<<i<<" "<<endl;
    }

    cout<<"Capacity-->"<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"Capacity-->"<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Capacity-->"<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Capacity-->"<<v.capacity()<<endl;
    cout<<"Size-->"<<v.size()<<endl;

    cout<<"front : "<<v.front()<<endl;
    cout<<"back : "<<v.back()<<endl;

    cout<<"Before pop: "<<endl;
    for(int i : v){
        cout<<i<<" ";
    }cout<<endl;

    v.pop_back();
    cout<<"After pop : "<<endl;
    for(int i : v){
        cout<<i<<" ";
    }cout<<endl;

    cout<<"Before clear: "<<v.size()<<endl;
    v.clear();
    cout<<"after clear: "<<v.size()<<endl;

}