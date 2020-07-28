// https://codeforces.com/contest/285/problem/B
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,s,t;
    cin>>n>>s>>t;
    vector<int> arr(n+1);
    
    ip1(arr, n);
    if(s==t){
        cout<<0<<endl;
        return 0;
    }
    vector<bool>visited(n+1, false);
    ll ans=0;
    while(s != t){
        if(!visited[arr[s]]){
            visited[arr[s]]=true;
            s = arr[s];
            ans++;
        }
        else{
            cout<<"-1\n";
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}