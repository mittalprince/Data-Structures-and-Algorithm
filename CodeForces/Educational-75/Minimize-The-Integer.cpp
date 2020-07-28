// https://codeforces.com/contest/1251/problem/C
#include<iostream>
#include<vector>
#include<queue>
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
    queue<char> odd, even;

    for(char i: s){
        if((i-'0')&1)odd.push(i);
        else even.push(i);
    }

    string ans="";

    while(!even.empty() and !odd.empty()){
        char a = even.front();
        char b = odd.front();
        if(a<b){
            ans += a;
            even.pop();
        }
        else{
            ans += b;
            odd.pop();
        }
    }

    while(!even.empty()){
        ans += even.front();
        even.pop();
    }
    while(!odd.empty()){
        ans += odd.front();
        odd.pop();
    }
    cout<<ans<<endl;
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