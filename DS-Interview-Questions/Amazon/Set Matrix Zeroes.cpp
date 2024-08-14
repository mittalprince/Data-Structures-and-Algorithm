// https://leetcode.com/problems/set-matrix-zeroes/
#include<iostream>
#include<vector>
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

void setZeroes(vector<vector<int>>& ar) {
    int n = ar.size();
    int m = ar[0].size();
    int row = 0, col = 0;
    for(int i = 0; i < m; i++){
        if(ar[0][i] == 0){
            row = 1;
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(ar[i][0] == 0){
            col = 1;
            break;
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(ar[i][j] == 0){
                ar[i][0] = 0;
                ar[0][j] = 0;
            }
        }
    }
    for(int i = 1; i < n; i++){
        if(ar[i][0] == 0)
            for(int j = 0; j < m; j++)
                ar[i][j] = 0;
    }
    for(int i = 1; i < m; i++){
        if(ar[0][i] == 0)
            for(int j = 0; j < n; j++)
                ar[j][i] = 0;
    }
    if(row == 1){
        for(int i = 0; i < m; i++)
            ar[0][i] = 0;
    }
    if(col == 1){
        for(int i = 0; i < n; i++)
            ar[i][0] = 0;
    }
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}