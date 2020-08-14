// https://codeforces.com/contest/911/problem/C
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
    int a,b,c;
    cin>>a>>b>>c;

    if(a==1 or b==1 or c==1 or (a==b and b==c and c==a and a==3)){
        cout<<"YES\n";
        return;
    }
    if((a==2 and b==2) or (a==2 and c==2) or (b==2 and c==2)){
        cout<<"YES\n";
        return;
    }
    if((a==4 and b==4 and c==2) or (a==4 and c==4 and b==2) or (a==2 and b==4 and c==4)){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
    return;
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