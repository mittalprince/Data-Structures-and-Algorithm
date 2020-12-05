// https://codeforces.com/contest/1447/problem/D
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

void solve(){
    int n,m;
    cin>>n>>m;

    string a,b;
    cin>>a>>b;

    vector<vector<int> >dp(n+1, vector<int>(m+1,0));
    int ans=0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 or j==0){
                dp[i][j]=0;
            }
            else{
                // initially consider till prev i or j
                // -1 as lcs will be 0 or since consider prev i or j, so length of one string will be 0 as no new char add
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])-1;
                if(a[i-1]==b[j-1]){
                    // as char equal, so lcs will be one for one new char add and acc to formula 4-1-1=2;
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+2);
                }
				if(dp[i][j]<0)dp[i][j]=0; // this is the point which must be note
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout<<ans<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}