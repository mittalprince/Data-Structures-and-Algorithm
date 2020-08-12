// https://codeforces.com/contest/1395/problem/C
#include<iostream>
#include<vector>
#include<climits>
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

ll ans=LLONG_MAX;
ll *arr, *brr;
int n, m;

void solve(){
    cin>>n>>m;
    arr = new ll[n];
    brr = new ll[m];
    ip(arr, n);
    ip(brr, m);

    for(int k=0; k<512; k++){
        bool flag=true;
        for(int i=0; i<n; i++){
            bool exist=false;
            for(int j=0; j<m; j++){
                if(((arr[i]&brr[j])|k) == k){
                    exist=true;
                    break;
                }
            }
            if(!exist){
                flag=false;
            }
        }
        if(flag){
            cout<<k<<endl;
            return;
        }
    }
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