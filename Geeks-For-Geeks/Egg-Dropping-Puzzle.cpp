#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll dp[15][55];
// dp[i][j] -> what will be min attempt when we have i eggs and j floors

// n-eggs
// k=floor

ll eggDrop(int n, int k){
    if(k<=1) return k; // when 0/1 building so total min attempt will be k
    if(n==1) return k; // when no of eggs 1, then min attempt will be k, as we try each building

    if(dp[n][k] != -1) return dp[n][k];
    int ans=INT_MAX;
    for(int x=1; x<=k; x++){
        // 2 possibility whether egg break or not
        // 1. if break we try lowerr floors, so total egg will be now n-1(one break) and rem floor will be x-1(as i drop form x, so try lower that is x-1)
        // 2. if not break then try higher floor, egg remain same(as not break), and fllor will be k-x(total k floor, drop from x, but not break, so looking upper of x, so total floor will be k-x).

        // now we take max of these two option, as conisder worst case possibility, as we don;t the exact floor where egg break, we just find if we
        // we drop from this floor with n egg available what will be min attempts, so consider worst case as best case already covered with worst case
        int res = max(eggDrop(n-1, x-1), eggDrop(n, k-x));
        ans = min(ans, res);
    }
    return dp[n][k] = ans+1;
}

void bottomUp(int n, int k){
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++){
        dp[i][1]=1; // when one floor
        dp[i][0]=0; // when zero floor
    }

    for(int i=1; i<=k; i++){
        dp[1][i]=i; // when we have only 1 egg, total min attempt will be total floor available
    }

    for(int i=2; i<=n; i++){
        for(int j=2; j<=k; j++){
            dp[i][j] = INT_MAX;
            for(int l=1; l<=j; l++){
                dp[i][j] = min(dp[i][j], 1+max(dp[i-1][l-1], dp[i][j-l]));
            }
        }
    }
    cout<<dp[n][k]<<endl;
}
void solve(){
    int n,k;
    cin>>n>>k;
    // memset(dp, -1, sizeof(dp));
    // cout<<eggDrop(n,k)<<endl;
    bottomUp(n, k);
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}