#include<iostream>
using namespace std;

class Hero{
    // properties
    char name[100];
    int health;
    public:
    char level;

    void print(){
        cout<<health<<endl;
    }

};

int main(){

    //creation of object
    Hero h1;
    cout<<"size :"<<sizeof(h1)<<endl;

    // Assigning values : 
    h1.level = 'A';

    // cout<<"health is:"<<h1.health<<endl;
    cout<<"Level is:"<<h1.level<<endl;








    /* oops : object -> entity(state/properties, behaviour)
    object : instance of class
    If class is an empty class(no properties) : min size 1 bytr memory assigned
    Class can be defined anywhere in directory and be accesses from outer source
    Using #include as header file */
    /* Accesing properties of a class - using dot operator.
    acc to access modiefiers
    (i) Public datamember/property : accessible everywhere inside or outside class
    (ii) Private property/datamenmber/function : acessible inside class only.
    (iii) Protected : accessible in inside and child class only;
    */
    /*For to access private members , we use getter/Setter*/
    return 0;
}
