// https://codeforces.com/contest/59/problem/A
#include<iostream>
#include<vector>
#include<algorithm>
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
    string s;
    cin>>s;

    int lower=0, upper=0;
    for(char i: s){
        if(i>='a' and i<='z')lower++;
        else upper++;
    }

    if(lower>=upper){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout<<s<<endl;
    }
    else{
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        cout<<s<<endl;
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