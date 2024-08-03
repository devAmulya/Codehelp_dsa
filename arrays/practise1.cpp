#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;
void print(int ans[], int n){
    for(int i = 0; i < n; i++){
        cout<<ans[i]<<endl;
    }
}
void merge_array(int arr1[], int n, int arr2[], int m, int arr3[]){
    int i = 0, j = 0,k=0;
    while(i < n && j < m){
        if(arr1[i]<arr2[j]){
            arr3[k++] = arr1[i++];
        }else{
            arr3[k++] = arr2[j++];
        }
    }
    while(i<n){
        arr3[k++] = arr1[i++];
    }
    while(j<m){
        arr3[k++] = arr2[j++];
    }
}

int main(){
    
    /*Reverse an array after M element
    int arr[] = {1,2,3,4,5,6};
    int M = 1;
    int s = M+1;
    int n = sizeof(arr)/sizeof(arr[0]);
    int e = n-1;
    while(s<e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i];
    }*/

    /*Merge Two sorted array
    int arr1[] = {1,3,5,7,9};
    int arr2[] = {2,4,6};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    int arr3[n+m];
    merge_array(arr1, n, arr2, m, arr3);
    print(arr3,n+m);*/

    //move zeroes
    int arr[] = {0,1,0,3,12,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i = 0;
    for(int j = 0; j < n; j++){
        if(arr[j] != 0){
            swap(arr[j],arr[i]);
            i++;
        }
    }
    print(arr,n);
}