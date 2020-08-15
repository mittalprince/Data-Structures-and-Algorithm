// https://hack.codingblocks.com/app/contests/1496/543/problem
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

void solve(int i, string t, int open, int close){
    if(i==(2*n)){
        cout<<t<<endl;
        return;
    }

    if(open>close){
        t += ")";
        solve(i+1, t, open, close+1);
        t.pop_back();
    }

    if(open<n){
        t += "(";
        solve(i+1, t, open+1, close);
        t.pop_back();
    }
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n;
    solve(0, "", 0, 0);
    return 0;
}