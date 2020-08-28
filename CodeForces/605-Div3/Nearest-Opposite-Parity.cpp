// https://codeforces.com/contest/1272/problem/E
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
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
#define MAX 200005

vector<ll>adj[MAX];

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n+1);
    ip1(arr, n);

    for(int i=1; i<=n; i++){
        int left = i-arr[i];
        int right = i+arr[i];

        if(left>=1 and ((arr[i]&1) == (arr[left]&1))){
            adj[left].push_back(i);
        }
        if(right<=n and ((arr[i]&1) == (arr[right]&1))){
            adj[right].push_back(i);
        }
    }

    vector<int>ans(n+1, -1);
    queue<int>q;

    for(int i=1; i<=n; i++){
        int left = i-arr[i];
        int right = i+arr[i];

        if(left>=1 and ((arr[i]&1) ^ (arr[left]&1))){
            ans[i]=1;
        }
        if(right<=n and ((arr[i]&1) ^ (arr[right]&1))){
            ans[i]=1;
        }
        if(ans[i]==1)q.push(i);
    }

    while(!q.empty()){
        int top=q.front();
        q.pop();

        for(int child: adj[top]){
            if(ans[child]!=-1)continue;
            ans[child] = ans[top]+1;
            q.push(child);
        }
    }

    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    // for(int i=0; i<=n; i++){
    //     adj[i].clear();
    // }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}