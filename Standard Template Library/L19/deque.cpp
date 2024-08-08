#include<iostream>
#include<deque>
using namespace std;

int main(){

    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.push_front(3);
    for(int i : d){
        cout<<i<<" ";
    }
    //d.pop_front();
    /*d.pop_back();
    for(int i : d){
        cout<<i<<" ";
    }*/
    cout<<"Print First Index ELement : "<<d.at(0)<<endl;

    cout<<"fornt : "<<d.front()<<endl;
    cout<<"back : "<<d.back()<<endl;

    cout<<"Empty or not : "<<d.empty()<<endl;

    cout<<"before erase"<<d.size()<<endl;
    d.erase(d.end()-1,d.end());
    cout<<"After erase"<<d.size()<<endl;
    for(int i : d){
        cout<<i<<endl;
    }


}