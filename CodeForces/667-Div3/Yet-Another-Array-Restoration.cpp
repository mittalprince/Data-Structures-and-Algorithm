//https://codeforces.com/contest/1409/problem/C
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
    int n,x,y;
    cin>>n>>x>>y;

    int diff = y-x;

    for(int i=1; i<=diff; i++){
        if(diff%i)continue; // as ap's (a[n]-a[m])%d==0
        if(diff/i+1 > n) continue; // as total term or element in arr for this d is greater than n
        int k=min((y-1)/i, n-1);
        int a = y-k*i;
        for(int j=0; j<n; j++){
            cout<<a+j*i<<" ";
        }
        cout<<endl;
        break;
    }
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