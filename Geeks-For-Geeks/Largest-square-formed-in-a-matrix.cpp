#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Logic every cell is samllest possible sqaure
we use dp in top-dwon approach i.e we fill up table from row 1 to row n
So we start from 2 row as in 1 row all are smallest possible

now for a given row arr[i][j] cell the maximum len square formed till this cell
And for arr[i][j] to contribute in its prev sqaure we must conside all three possible direction
i.e left, top, diagonal upper -> (i,j-1) (i-1,j) (i-1,j-1)
if we found square in all these cell, then arr[i][j] will add 1 to get form new len
dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;

why we take min, as if one of these 3 possible direction if there is no square at these points,
then arr[i][j] can not form square
so we consider min square all these 3 possiblity form will be ans for the particular cell (i,j)
*/

int maximalSquare(vector<vector<char>>& matrix) {
    int n=matrix.size();
    if(n==0) return 0;
    int m=matrix[0].size();
    if(m==0) return 0;
    
    vector<vector<int> >dp(n+1, vector<int>(m+1, 0));
    int maxsqlen = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (matrix[i-1][j-1] == '1'){
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                maxsqlen = max(maxsqlen, dp[i][j]);
            }
        }
    }
    return maxsqlen;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> >arr(n, vector<char>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    cout<<maximalSquare(arr)<<endl;
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}