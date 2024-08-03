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

int pair_sum(int arr[], int n,int t, int a, int idx){
    int i = idx+1;
    int j = n-1;
    int found = -1;
    while(i<j){
        if((a+arr[i]+arr[j]) == t){
            cout<<a<<" "<<arr[i]<<" "<<arr[j];
            while(i<j && arr[i] == arr[i+1]){
                i++;
            }
            while(i<j&&arr[j]==arr[j-1]){
                j--;
            }
            i++;
            j--;
        }
        else{
            if(a+arr[i]+arr[j] < t){
                i++;
            }
            else if(a+arr[i]+arr[j] > t){
                j--;
            }
        }
    }
    return 0;

}


int main(){
    
    //int arr[] = {-3,0,1,-3,1,1,1,-3,10,0};
    int arr[] = {4,3,2,7,8,2,3,1};
    //int arr[] = {10,5,5,5,2};
    
    //sort(arr,arr+n);
    //int arr[] = {0,1,2,0,2,2,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    /*Unique number of occurence
    unique_occurence(arr,n);*/

    //Duplicates 
    /*1st o(n) space 
    long long int N = 100000;
    int idx[N];
    for(int i = 0; i  < N; i++){
        idx[i] = -1;
    }
    for(int i = 0; i < n; i++){
        if(idx[arr[i]] != -1){
            cout<<idx[arr[i]]<<" ";
        }
        else{
            idx[arr[i]] = i;
        }
    }*/
    //2nd const space
    for (int i = 0; i < n; ++i) {
        while (arr[i] != arr[arr[i] - 1]) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] != i + 1) {
            cout<<arr[i]<<" ";
        }
    }

    /*3 SUM 
    int tg = 12;
    for(int i = 0; i < n-2;i++){
        if(i>0 && arr[i] == arr[i-1]){
            continue;
        }
        pair_sum(arr,n,tg,arr[i],i);
    }*/

    /*Sort 0 1 2
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(arr[mid] == 0){
            int temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else if(arr[mid] == 2){
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i];
    }*/


}


