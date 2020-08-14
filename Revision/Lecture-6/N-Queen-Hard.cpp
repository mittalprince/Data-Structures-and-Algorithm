// https://hack.codingblocks.com/app/contests/1496/133/problem
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
#define DONE (1<<n)-1

int ans=0;

void NQueen(int col, int ld, int rd, int n){
    if(col==DONE){
        ans++;
        return;
    }
    int rem = DONE&(~(col|ld|rd));
    while(rem){
        int pos = rem&(-rem);
        rem -= pos;
        NQueen(col|pos, (ld|pos)<<1, (rd|pos)>>1, n);
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    NQueen(0, 0, 0, n);
    cout<<ans<<endl;
    
    return 0;
}