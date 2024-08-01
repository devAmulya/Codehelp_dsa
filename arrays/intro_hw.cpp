#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int no_of_occurence(int arr[], int n, int e){
    int ans = -1;
    int start = 0;
    int end = n-1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(e == arr[mid]){
            ans = mid;
            end = mid-1;
        }else if(e < arr[mid]){
            end = mid - 1;
        }else if(e > arr[mid]){
            start = mid + 1;
        }
    }
    int ans1 = -1;
    int s = ans;
    int ed = n-1;
    while(s <= ed){
        int mid = s+(ed-s)/2;
        if(e == arr[mid]){
            ans1 = mid;
            s = mid+1;
        }else if(e < arr[mid]){
            ed = mid - 1;
        }else if(e > arr[mid]){
            s = mid + 1;
        }
    }
    int value = ans1 - ans + 1;
    return value;
}

bool unique_occurence(int arr[], int n){
    int arr1[n];
    int start = arr[0];
    arr1[0] = no_of_occurence(arr,n,arr[0]);
    int q = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] != start){
            arr1[q+1] = no_of_occurence(arr,n,arr[i]);
            q++;
            start = arr[i];
        }
    }
    int count = 1;
    for(int i = 0; i < q; i++){
        for(int j = i+1; j <= q; j++){
            if(arr1[i] == arr1[j]){
                cout<<"False";
                count = 0;
                break;
            }
        }
        if(count == 0){
            break;
        }
    }
    if(count == 1){
        cout<<"True";
    }
}


int main(){
    
    /*Unique number of occurence
    int arr[] = {-3,0,1,-3,1,1,1,-3,10,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    unique_occurence(arr,n);*/

    
    
}


