#include<iostream>
using namespace std;

bool isSorted(int arr[], int start, int end, int n){
    /*First way uses arr, start, end
    if(start == end){
        return true;
    }
    if(arr[start] > arr[start+1]){
        return false;
    }
    start++;
    isSorted(arr,start,end);
    */
    /*Second way uses arr, size(n)*/
    if(n == 0 || n == 1 ){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }else{
        isSorted(arr+1,0,n-1,n-1);
    }
}

int arrSum(int arr[], int n){
    int sum = 0;
    if(n == 0){
        return sum;
    }
    sum = arr[0] + arrSum(arr+1,n-1);
}

bool linear_search(int arr[], int n, int target){
    if(n == 0){
        return false;
    }
    if(arr[0] == target){
        return true;
    }
    linear_search(arr+1,n-1,target);
}

bool binary_search(int arr[], int start, int end, int target){
    int mid = start + (end - start)/2;
    if(start > end){
        return false;
    }
    if(arr[mid] == target){
        return true;
    }else if(arr[mid] > target){
        binary_search(arr,start,mid-1,target);
    }else{
        binary_search(arr,mid+1,end,target);
    }
}

int main(){

    /*Array is sorted or not
    int arr[] = {2,4,6,9,11,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<isSorted(arr,0,n-1,n);
    */

    /*Array SUm  HW
    int arr[] = {3,2,5,1,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"The sum is : "<<arrSum(arr,n);
    */

    /*Linear Search
    int arr[] = {3,2,5,1,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<linear_search(arr,n,7);
    */

    //binary search
    int arr[] = {2,4,6,9,11,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Found : "<<binary_search(arr,0,n-1,14);
    
    



    

    return 0;
}