// Number of paths
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007

int n,m;

void solve(){
    vector<vector<int> >dp(n, vector<int>(m, 0));
    dp[0][0]=1;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 || j==0){
                dp[i][j]=1;
            }
            else{
                dp[i][j] = dp[i][j-1]+dp[i-1][j];
            }
        }
    }
    cout<<dp[n-1][m-1]<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        solve();
    }
    return 0;
}
