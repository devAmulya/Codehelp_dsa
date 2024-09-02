#include<iostream>
using namespace std;

void update1(int n){
    n++;
}

void update2(int& n){
    n++;
}

int getSum(int *arr, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){

    /*Refrence variable
    int i = 5;
    int& j = i;
    cout<<i<<j<<endl;
    i++;
    cout<<i<<j<<endl;
    j++;
    cout<<i<<j<<endl;
    update1(i);
    cout<<i<<j<<endl;
    update2(i);
    cout<<i<<j<<endl;
    */

    /*Variable size array using heap and pointer
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        cout << arr[i]<<" ";
    }cout<<endl;
    cout<<"Sum of array : "<<getSum(arr,n)<<endl;
    //Release memory
    delete[] arr;
    */

    //2D array
    int n,m;
    cin >> n >> m;
    int ** arr = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j]<<" ";
        }cout<<endl;
    }

    //Releasing memory
    for(int i = 0; i < n; i++){
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}