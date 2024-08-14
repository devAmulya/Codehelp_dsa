#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    
    /*Rotate 2D - array by 90 degree
    int n;
    cin >> n;
    int arr[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
    /*First approach transporse and reverse
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            swap(arr[i][j],arr[j][i]);
        }
        reverse(arr[i].begin(),arr[i].end());
    }*/

    /*2nd approach needs more improvement right now
    int var = 0,row = 0, col = 0 , temp;
    for(int i = 0; i < n-1; i++){
        swap(arr[row][col+var],arr[col+var][n-1]);
        swap(arr[row][col+var],arr[n-1][n-1-var]);
        swap(arr[row][col+var],arr[n-1-var][col]);
        var++;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){
            cout << arr[i][j];
        }
        cout << endl;
    }*/
    
    


    return 0;
}