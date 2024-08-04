#include<iostream>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

void print(vector<int> ans, int n){
    for(int i = 0; i < n; i++){
        cout<<ans[i];
    }
}

vector<int> reverse(vector<int> v){
    int s = 0;
    int n = v.size();
    int e = n-1;
    while(s<e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
}

bool check_rotate(int arr[], int n){
    int count = 0;
    for(int i = 1; i < n; i++){
        if(arr[i-1] > arr [i]){
            count++;
        }
    }
    if(arr[n-1] > arr[0]){
        count++;
    }
    return count==1 || count == 0;
}

int main(){
    /*Rotate Array
    int arr[] = {1,2,3,4,5};
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp[n];
    for(int i = 0; i < n ; i++){
        temp[(i+k)%n] = arr[i];
    }
    for(int i = 0; i < n; i++){
        arr[i] = temp[i];
    }
    print(arr,n);*/

    /*Check if rotated and sorted;
    int arr[] ={1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(check_rotate(arr,n) == true){
        cout<<"Sorted and Rotated";
    }else{
        cout<<"NOt sorted and rotated";
    }*/

    //Add arrays

    /*BRUTE FORCE
    int arr1[] = {1,2,3,4};
    int arr2[] = {6};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    int s1 = 0 ,s2 = 0;
    int factor = 1;
    for(int i = n-1; i >= 0; i--){
        s1 += arr1[i]*factor;
        factor *= 10;
    }
    factor = 1;
    for(int i = m-1; i >= 0; i--){
        s2 += arr2[i]*factor;
        factor *= 10;
    }
    int s3 = s1+s2;
    int o = log10(s3)+1;
    int arr3[o];
    for(int i = o-1; i >= 0; i--){
        arr3[i] = s3%10;
        s3 /= 10;
    }
    print(arr3,o);*/

    vector<int> a = {1,2,3,4};
    vector<int> b = {6};
    vector<int> ans;
    int n = a.size();
    int m = b.size();
    int carry = 0;
    int i = n-1, j = m-1;
    while(i >= 0 && j >= 0){
        int sum = a[i] + b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;

    }
    while(i >= 0){
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    while(j >= 0){
        int sum = b[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }
    while(carry != 0){
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }

    print(reverse(ans),ans.size());


 }