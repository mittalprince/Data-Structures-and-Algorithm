// https://hack.codingblocks.com/app/contests/1496/754/problem
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007
#define MAX 9

int n;
int grid[MAX][MAX];

bool isSafe(int i, int j, int number){
    for(int k=0; k<n; k++){
        if(grid[k][j]==number or grid[i][k]==number)return false;
    }

    int t=sqrt(n);
    int starti = (i/t)*t;
    int startj = (j/t)*t;

    for(int k=starti; k<starti+t; k++){
        for(int l=startj; l<startj+t; l++){
            if(grid[k][l]==number)return false;
        }
    }
    return true;
}

bool solve(int i, int j){
    if(i==n){
        for(int k=0; k<n; k++){
            for(int l=0; l<n; l++){
                cout<<grid[k][l]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    if(j==n){
        return solve(i+1, 0);
    }

    if(grid[i][j] != 0)return solve(i, j+1);

    for(int k=1; k<=n; k++){
        if(isSafe(i,j,k)){
            grid[i][j]=k;
            bool checkRemSudoku = solve(i, j+1);
            if(checkRemSudoku)return true;
            grid[i][j] = 0;
        }
    }
    return false;

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    solve(0,0);
    return 0;
}