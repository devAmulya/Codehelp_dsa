#include<iostream>
#include <algorithm>
#include<limits.h>
using namespace std;

bool ispossible(int arr[],int n, int m, int mid){
    int painter = 1;
    int boards = 0;
    for(int i = 0; i < n; i++){
        if(boards+arr[i] <= mid){
            boards += arr[i];
            continue;
        }else{
            painter++;
            if(painter >  m || arr[i] > mid){
                return false;
            }
            boards = arr[i];
        }
    }
    return true;
}

int painter_partition(int arr[], int n, int m){
    int start = 0;
    int sum = 0;
    for(int i = 0; i<n;i++){
        sum += arr[i];
    }
    int end = sum;
    int ans = -1;
    int mid = start+(end-start)/2;
    while(start<=end){
        if(ispossible(arr,n,m,mid)){
            end = mid-1;
            ans = mid;
        }else{
            start = mid+1;
        }
        mid = start+(end-start)/2;
    }
    return ans;
}

bool iscorrect(int arr[], int n, int m, int mid){
    int trees = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > mid){
            trees += arr[i] -mid;
            if(trees >= m){
                return true;
            }
        }
    }
    return false;
}

int cutting_trees(int arr[], int n, int m){
    int start = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    int end = sum;
    int ans = -1;
    int mid = start + (end - start)/2;
    while(start <= end){
        if(iscorrect(arr,n,m,mid)){
            start = mid +1;
            ans = mid;
        }
        else{
            end = mid-1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int dish_no(int arr, int time){
    int T = 0;
    int count_dish = 1;
    while(T<=time){
        T += arr*count_dish;
        count_dish++;
    }
    return count_dish-2;

}

bool isright(int arr[], int n, int m, int mid){
    int dishes = 0;
    for(int i = 0; i < n; i++){
        dishes += dish_no(arr[i],mid); 
        if(dishes >= m){
            return true;
        }
    }
    return false;
}

int dish_time(int arr[], int n, int m){
    int start = 0;
    int ans = -1;
    int end = INT_MAX;
    int mid = start + (end - start)/2;
    while(start <= end){
        if(isright(arr, n , m , mid)){
            end = mid -1;
            ans = mid;
        }
        else{
            start = mid+1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main(){

    /*PAINTERS PARTITION PROBLEM
    int arr[] = {48,90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 2;
    cout<<painter_partition(arr,n,m);*/

    /*EKO
    int arr[] = {4,42,40,26,46};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 20;
    cout<<cutting_trees(arr,n,m);*/

    //SPATA
    int arr[] = {8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 11;
    cout<<dish_time(arr,n,m);

    return 0;
}