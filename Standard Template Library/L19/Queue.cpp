#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue<string> q;

    q.push("Coder");
    q.push("Amulya");
    q.push("Gupta");

    cout<<"First Element : "<<q.front()<<endl;
    cout<<"Size before pop : "<<q.size()<<endl;
    q.pop();
    cout<<"First element after pop : "<<q.front()<<endl;

    cout<<"Size after pop : "<<q.size()<<endl;

}