// https://codeforces.com/contest/1395/problem/A
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
    ll r,g,b,w;
    cin>>r>>g>>b>>w;

    int odd=0, even=0;
    if(r&1){
        odd++;
    }
    else even++;

    if(g&1)odd++;
    else even++;

    if(b&1)odd++;
    even++;

    if(w&1)odd++;
    else even++;

    if(odd == 4 or even == 4 or odd==1 or (odd==3 and w%2==0)){
        cout<<"Yes\n";
        return;
    }

    if(odd==2){
        cout<<"No\n";
        return;
    }
    if(w&1){
        if(r<=0 or g<=0 or b<=0){
            cout<<"No\n";
            return;
        }
        else{
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";

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