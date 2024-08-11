#include<iostream>//1 2 3 4 5 6 7 8 9 10 11 12
#include<limits.h>
#include<algorithm>
using namespace std;

bool isFound(int arr[][4], int n, int m, int target){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == target){
                return true;
            }
        }
    }
    return 0;
}

void row_sum(int arr[][4], int row, int col){
    int sum = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            sum+=arr[i][j];
        }
        cout<<i+1<<" row sum = "<<sum<<endl;
        sum = 0;
    }
}

void col_sum(int arr[][4], int row, int col){
    int sum = 0;
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            sum+=arr[j][i];
        }
        cout<<i+1<<" row sum = "<<sum<<endl;
        sum = 0;
    }
}

int Large_row_sum(int arr[][4], int row, int col){
    int sum = 0, maxsum = INT_MIN, row_l = -1;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            sum+=arr[i][j];
        }
        if(maxsum < sum){
            maxsum = sum;
            row_l = i;
        }
        sum = 0;
    }
    cout<<"Max sum = "<<maxsum<<endl;
    return row_l;
}

int main(){

    /*create 2D array
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int arr[3][4] = {{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};
    int arr[3][4];*/
    
    int n, m;
    cout << "Enter size : ";
    cin >> n >> m;
    int arr[n][m];

    /*input -> row wise*/
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    /**input -> col wise
    for(int i = 0 ; i < 4; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[j][i];
        }
    }*/

    /*output*/
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout<<endl;
    }

    /*Linear Search
    int target;
    cout<<"Element to search : ";
    cin >> target;
    if(isFound(arr, 3, 4, target)){
        cout<<"Found";
    }else{
        cout<<"Not Found";
    }*/

    /*Row wise SUm
    row_sum(arr, 3, 4);*/

    /*Col wise sum
    col_sum(arr, 3, 4);*/

    /*Largest Row Sum
    cout<<"Row number : "<<Large_row_sum(arr, 3 , 4) + 1<<endl;*/

    /*Wave print
    for(int i = 0; i < 4; i++){
        if(!(i%2)){
            for(int j = 0; j < 3; j++){
                cout<<arr[j][i]<<" ";
            }
        }else{
            for(int j = 3-1; j >= 0; j--){
                cout<<arr[j][i]<<" ";
            }
        }
        
    }*/

    /*Spiral print
    int count = 0, total = n*m;
    int row_s = 0 , row_e = n-1, col_s = 0, col_e = m-1;
    while(count < total){
        for(int i = col_s;count < total && i <= col_e; i++){
            cout<<arr[row_s][i]<<" ";
            count++;
        }row_s++;
        for(int i = row_s;count < total &&  i <= row_e; i++){
            cout<<arr[i][col_e]<<" ";
            count++;
        }col_e--;
        for(int i = col_e;count < total &&  i >= col_s; i--){
            cout<<arr[row_e][i]<<" ";
            count++;
        }row_e--;
        for(int i = row_e;count < total &&  i >= row_s; i--){
            cout<<arr[i][col_s]<<" ";
            count++;
        }col_s++;
        
    }*/

    //Search a 2D matrix
    
    /*First method Binary search since linearly sorted when forsaw in memory allocation
    int target;
    cin>>target;
    bool flag = 0;
    int start = 0, end = (n*m)-1;
    int mid = start + (end - start)/2;
    while(start <= end){
        int element = arr[mid/m][mid%m];
        if(element == target){
            flag = 1;
            break;
        }else if(element > target){
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    cout<<flag;*/

    /*2nd method*/
    int target;
    cin>>target;
    int r = 0, c = m-1;
    while(r < n && c >= 0){
        if(arr[r][c] == target){
            cout<<"Target found at r : "<<r+1<<" and c : "<<c+1;
            break;
        }else if(arr[r][c] > target){
            c--;
        }else{
            r++;
        }
    }

    
    

    

    return 0;
}