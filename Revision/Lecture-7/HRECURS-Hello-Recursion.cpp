// https://www.spoj.com/problems/HRECURS/
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

int n;
int *arr;


ll findSum(int i){
    if(i==n){
        return 0;
    }
    return arr[i]+findSum(i+1);
}

void solve(){
    cin>>n;
    arr = new int[n];
    ip(arr, n);
    cout<<findSum(0)<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    int tc=1;
    while(t--){
        cout<<"Case "<<tc++<<": ";
        solve();
    }
    return 0;
}