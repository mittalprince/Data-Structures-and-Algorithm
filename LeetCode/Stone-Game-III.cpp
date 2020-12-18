//https://leetcode.com/problems/stone-game-iii/
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

string stoneGameIII(vector<int>& A) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=A.size();
    vector<int>dp(n, -1e9);

    for(int i=n-1; i>=0; i--){
        for(int k=0, take=0; k<3 and i+k<n; k++){
            take += A[i+k];
            dp[i] = max(dp[i], take-(i + k + 1 < n ? dp[i + k + 1] : 0));
        }
    }
    if (dp[0] > 0) return "Alice";
    if (dp[0] < 0) return "Bob";
    return "Tie";
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