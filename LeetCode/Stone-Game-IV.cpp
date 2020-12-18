//https://leetcode.com/problems/stone-game-iv/
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

bool winnerSquareGame(int n) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(n==0)
        return false;

    vector<bool> dp(n+1, false);        
    //dp[i] = true -> Alice wins
    //dp[i] = false -> Bob wins

    for(int i=0; i<=n; i++){
        if(dp[i]==false){ // means if bob wins and alice can remove square number 
            // he remove it and make himself win
            for(int j=1; j*j+i<=n; j++){
                dp[i+j*j]=true;
            }
        }
    }

    return dp[n];
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