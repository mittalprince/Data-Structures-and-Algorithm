// https://codeforces.com/contest/899/problem/B
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
    int n;
    cin>>n;

    int brr[n];
    ip(brr, n);

    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int idx=0,cnt=0,f=0;

    for(int i=0; i<12; i++){
        int k=i;
        f=0;
        while(brr[idx]==arr[k] or (brr[idx]==29 and arr[k]==28)){
            if(f and brr[idx]==29 and arr[k]==28){
                cout<<"No\n";
                return;
            }
            if(!f and brr[idx]==29 and arr[k]==28){
                f=1;
            }
            idx++;
            cnt++;
            k = (k+1)%12;
            if(cnt==n){
                cout<<"Yes\n";
                return;
            }
        }
        idx=0,cnt=0;
    }
    cout<<"No\n";
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