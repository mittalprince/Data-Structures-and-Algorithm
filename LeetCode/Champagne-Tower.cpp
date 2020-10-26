//https://leetcode.com/problems/champagne-tower/
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

double champagneTower(int poured, int query_row, int query_glass) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int maxRows=105;
    vector<vector<double> >dp(maxRows, vector<double>(maxRows));
    dp[0][0] = poured;

    for(int i=0; i<query_row; i++){
        for(int j=0; j<=i; j++){
            if (dp[i][j] > 1) {
                dp[i+1][j] += (dp[i][j] - 1) / 2.0;
                dp[i+1][j+1] += (dp[i][j] - 1) / 2.0;
                dp[i][j] = 1.0;
            }
        }
    }
    return min(1.0, dp[query_row][query_glass]);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}