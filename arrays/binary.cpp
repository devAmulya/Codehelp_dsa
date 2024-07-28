#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of elements : ";
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    /*FIRST AND LAST POSITION OF AN ELEMENT(Sorted Array)
    int e; 
    cout<<"Enter element : ";
    cin>>e;
    int ans = -1;
    int start = 0;
    int end = n-1;
    while(start <= end){
        int mid = (end/2+start/2);
        if(e == arr[mid]){
            ans = mid;
            end = mid-1;
        }else if(e < arr[mid]){
            end = mid - 1;
        }else if(e > arr[mid]){
            start = mid + 1;
        }
    }
    cout<<"First occurence is : "<<ans<<endl;
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
    cout<<"Second occurence is : "<<ans1<<endl;*/

    /*Total number of occurence
    cout<<"Total occurence : "<<ans1-ans+1;*/
    
    /Mountain array peak index
    int ans = -1;
    int start = 0;
    int end = n-1;
    while(start <= end){
        int mid = (start+(end-start)/2);
        if(arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid]){
            ans = mid;
            break;
        }else if(arr[mid-1]<arr[mid]){
            start = mid + 1;
        }else if(arr[mid-1]>arr[mid]){
            end = mid - 1;
        }
    }
    cout<<"peak index : "<<ans;
}