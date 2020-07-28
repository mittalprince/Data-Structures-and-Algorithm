#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 9

bool isSafe(int arr[][MAX], int i, int j, int n, int number){
    for(int k=0; k<n; k++){
        if(arr[i][k] == number || arr[k][j] == number) return false;
    }

    n = sqrt(n);
    int starti = (i/n)*n;
    int startj = (j/n)*n;

    for(int k=starti; k<starti+n; k++){
        for(int l=startj; l<startj+n; l++){
            if(arr[k][l] == number) return false;
        }
    }
    return true;
}

bool solveSudoku(int arr[][MAX], int i, int j, int n){
    if(i==n){
        for(int k=0; k<n; k++){
            for(int l=0; l<n; l++){
                cout<<arr[k][l]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    if(j==n){
        return solveSudoku(arr, i+1, 0, n);
    }
    if(arr[i][j] != 0) return solveSudoku(arr, i, j+1, n);

    for(int k=1; k<=n; k++){
        if(isSafe(arr, i, j, n, k)){
            arr[i][j] = k;
            bool checkRemSudoku = solveSudoku(arr, i, j+1, n);
            if(checkRemSudoku) return true;
            arr[i][j] = 0;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int grid[MAX][MAX];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    solveSudoku(grid, 0, 0, n);
    return 0;
}