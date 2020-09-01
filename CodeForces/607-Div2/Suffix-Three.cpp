// https://codeforces.com/contest/1281/problem/A
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

string arr[3] = { "FILIPINO","JAPANESE","KOREAN"};

void solve(){
    string s;
    cin>>s;
    int n=s.length();
    if(n>=5){
        string t = s.substr(n-5);
        if(t=="mnida"){
            cout<<arr[2]<<endl;
            return;
        }
    }
    if(n>=4){
        string t = s.substr(n-4);
        if(t=="desu" or t=="masu"){
            cout<<arr[1]<<endl;
            return;
        }
    }
    if(n>=2){
        string t = s.substr(n-2);
        if(t=="po"){
            cout<<arr[0]<<endl;
            return;
        }
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