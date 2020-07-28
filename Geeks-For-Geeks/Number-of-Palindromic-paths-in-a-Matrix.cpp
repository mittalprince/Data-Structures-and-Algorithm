#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007
#define MAX 20

int n,m;
char arr[MAX][MAX];
int dp[MAX][MAX][MAX][MAX];

int solve(int i, int j, int p, int q){
    
    if(i<0 || i>=n || j<0 || j>=m){
        return 0;
    }

    if(p<0 || p<i || q<0 || q<j){
        return 0;  
    }
    
    if(arr[i][j] != arr[p][q]){
        return 0;
    }

    if (abs((i - p) + (j - q)) <= 1) {
        return 1; 
    }

    if(dp[i][j][p][q] != -1)return dp[i][j][p][q];

    int ans=0;
    ans += solve(i+1, j, p-1, q);
    ans += solve(i+1, j, p, q-1);
    ans += solve(i, j+1, p-1, q);
    ans += solve(i, j+1, p, q-1);
    
    return dp[i][j][p][q] = ans;
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
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>arr[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        cout<<solve(0, 0, n-1, m-1)<<endl;
    }
    return 0;
}