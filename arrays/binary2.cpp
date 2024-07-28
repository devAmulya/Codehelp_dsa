#include<iostream>
#include<limits.h>
using namespace std;
//Sorted and rotated question
int binary_search(int a[],int start,int end,int element){
    int mid = start+(end-start)/2;
    while(start <= end){
        if(element == a[mid]){
            cout<<"Index is : "<<mid;
            break;
        }else if(element < a[mid]){
            end = mid-1;
            //cout<<end;
        }else{
            start = mid+1;
            //cout<<start;
        }
        mid = start+(end-start)/2;
    }
    return 0;
}

int pivot_search(int a[],int n){
    /*Find Pivot Element in sorted and rotated array
    *where pivot element is the point where they change. For example, [7,9,1,3,6] - Here 9 & 1 can be pivot*/ 
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s<e){
        if(a[mid] >= a[0]){     
            s = mid+1; //s = mid if taken larger pivot (9)
        }else{
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    int p = s;
    //cout<<s<<endl;
    return p;
} 

long long int sqrt_int(int n){
    int s = 0; 
    int e = n;
    long long int ans = -1; //ans for 2nd 
    long long int mid = s + (e-s)/2;
    while(s<=e){
        long long int square = mid*mid;
        if(square == n){
            return mid;
        }
        else if(mid*mid < n){
            s = mid+1;
            ans = mid; //2nd approach
        }else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    cout<<min(s,e)<<endl;//"Both approaches can be used(min and ans)"
    cout<<ans<<endl; //2nd
    return ans;
}

double sqrt_float(int n, int precision, int tempsol){
    double factor = 1;
    double ans = tempsol;

    for(int i = 0; i < precision;i++){
        factor = factor/10;
        for(double j = ans; j*j < n; j = j + factor){
            ans = j;
        }
    }
    return ans;
}

int main(){

    /*int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    

    searh in a rotated sorted array
    int element;
    cin>>element;
    int pivot = pivot_search(arr,n);//Find pivot index
    if(element >= arr[pivot] && element < arr[n-1] ){
        binary_search(arr,pivot,n-1,element); 
    }else{
        binary_search(arr,0,pivot,element); 
    }*/

    //Int Square root using binary search
    int n;
    cin>>n;
    int temp = sqrt_int(n);
    double final = sqrt_float(n,4,temp);
    cout<<final;

    //

    return 0;
}