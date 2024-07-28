#include<iostream>
#include <algorithm>
#include<limits.h>
using namespace std;

/*bool isPossible(int arr[], int n, int m, int mid){
    int student = 1;
    int pagesum = 0;
    for(int i = 0; i < n; i++){
        if(pagesum + arr[i] <= mid){
            pagesum += arr[i];
        }else{
            student++;
            if(student > m || arr[i] > mid){
                return false;
            }
            pagesum = arr[i];
        }
    }
    return true;
}

int BOOK_allocation(int arr[],int n, int m){
    int s = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(isPossible(arr,n,m,mid)){
            ans = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
    

}*/

bool possible(int arr[], int n,int m, int mid){
    int cow_no = 1;
    int pos = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i]-pos >= mid){
            cow_no++;
            if(cow_no == m){
                return true;
            }
            pos = arr[i];
        }
    }
    return false;
}

int COW_STALL(int arr[],int n, int m){
    sort(arr,arr+n);
    int s = 0;
    int e = arr[n-1]-arr[0];
    int ans = -1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(possible(arr, n,m, mid)){
            ans = mid;
            s = mid+1;
        }else{
            e = mid -1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int main(){

    /*BOOK ALLOCATION PROBLEM
    int arr[] = {10,20,30,40};
    cout<<BOOK_allocation(arr,4,2);*/

    //AGGRESSIVE COW PROBLEM
    int arr[] = {87,93,51,81,68,99,59};
    int n = sizeof(arr)/sizeof(int);
    cout<<COW_STALL(arr,n,4);

    return 0;
}
