// https://www.spoj.com/problems/STAR3CAS/
#include<iostream>
#include<vector>
#include<cstring>
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
#define MAX 100000

int ans=inf, n;
bool visited[MAX]={0};
int *arr;

void findMinSteps(int stair, int step_taken){
    if(stair == n){
        ans = min(ans, step_taken);
        return;
    }
    visited[stair]=1;
    if(stair+1<=n and !visited[stair+1]){
        findMinSteps(stair+1, step_taken+1);
    }

    if(stair+arr[stair]<=n and stair+arr[stair]>=0 and !visited[stair+arr[stair]]){
        findMinSteps(stair+arr[stair], step_taken+1);
    }
    visited[stair]=false;
}

void solve(){
    cin>>n;
    arr = new int[n];
    ip(arr, n);

    ans=inf;
    memset(visited, 0, sizeof(visited));
    findMinSteps(0,0);
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