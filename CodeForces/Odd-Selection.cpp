#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

void solve(){
    int n,x;
    cin>>n>>x;
    int odd=0, even=0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x&1) odd++;
        else even++;
    }

    if(odd==0||(odd==n&&x%2==0)||(x==n&&odd%2==0))cout<<"No\n";
    else cout<<"Yes\n";
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