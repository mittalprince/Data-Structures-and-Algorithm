// https://hack.codingblocks.com/app/contests/1496/253/problem
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

string s;
int ans=0;

void solve(int i, string t){
    if(i==s.length()){
        cout<<t<<" ";
        ans++;
        return;
    }
    solve(i+1, t);
    t += s[i];
    solve(i+1, t);
    t.pop_back();
    t += to_string((int)s[i]);
    solve(i+1, t);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>s;
    solve(0, "");
    cout<<endl<<ans<<endl;
    return 0;
}