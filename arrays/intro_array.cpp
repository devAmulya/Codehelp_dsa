#include<iostream>
#include<limits.h>
using namespace std;


int print(int arr[],int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<endl;
    }
}


int main(){

    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    int arr[n];
    for(int i = 0; i < n ; i++){
        cin>>arr[i];
    }


    /*print sum of all elements
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    cout<<"Sum is : "<<sum;*/

    /*Swap Alternate elements
    int i = 0;
    while(i<n){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        i += 2;
    }
    print(arr,n);*/

    /*Unique number in an array size = 2m+1 where m elements repeat twice while only one has one occurence
    int xr = arr[0];
    for(int i = 1; i < n; i++){
        xr = xr^arr[i];
    }
    cout<<xr;*/

    /*Duplicate value(one always)*/
    /*For any value in array
    for(int i = 0; i < n-1; i++){
        int point = arr[i];
        for(int j = i+1; j < n; j++){
            if(point == arr[j]){
                cout<<"Duplicate value : "<<point;
                break;
            }
        }
    }*/
    /*For value between 1 - (n-1)
    int xr = 0;
    for(int i = 0; i < n; i++){
        xr = xr^arr[i];
        xr = xr^i;
    }
    cout<<"Duplicate Value : "<<xr;*/

    /*Array Intersection
    int m;
    cin>>m;
    int arr1[m];
    for(int i = 0; i < m; i++){
        cin>>arr1[i];
    }

    int i = 0, j = 0;
    while(i < n && j < m){
        if(arr[i]<arr1[j]){
            i++;
        }
        else if (arr[i] == arr1[j]){
            cout<<arr[i]<<" ";
            i++;
            j++;
        }
        else{
            j++;
        }
    }*/

    /*Pair Sum
    int s;
    cin>>s;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n;j++){
            if((arr[i]+arr[j])==s){
                if(arr[i]>arr[j]){
                    cout<<arr[j]<<" "<<arr[i]<<endl;
                }else{
                    cout<<arr[i]<<" "<<arr[j]<<endl;
                }
            }
        }
    }*/

    /*Triplet Sum*/

    /*Sort 0 & 1*/
    int i = 0,j = n-1;
    while(i < j){
        while(arr[i] == 0 && i <j){
            i++;
        }
        while(arr[j] == 1&&i<j){
            j--;
        }
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    print(arr,n);

    

    return 0;
}