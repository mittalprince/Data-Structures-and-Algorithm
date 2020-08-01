// https://codeforces.com/contest/1332/problem/A
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
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int x,x1,x2,y,y1,y2;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    
    x+=(b-a), y+=(d-c);
    if(x>=x1 and x<=x2 and y>=y1 and y<=y2 and (x1<x2 or a+b==0) and (y1<y2 or c+d==0)){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
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