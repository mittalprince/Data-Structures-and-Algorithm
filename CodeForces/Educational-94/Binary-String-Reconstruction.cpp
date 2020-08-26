// https://codeforces.com/contest/1400/problem/C
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
    string s;
    cin>>s;
    int x;
    cin>>x;
    
    int n=s.length();
    string ans(n, '1');
    for(int i=0; i<n; i++){
        if(s[i]=='0'){
            if(i>=x)ans[i-x]='0';
            if(i+x<n)ans[i+x]='0';
        }
    }
    for(int i=0; i<n; i++){
        if(s[i]=='1'){
            bool flag=false;
            if(i>=x and ans[i-x]=='1'){
                flag=true;
            }
            if(i+x<n and ans[i+x]=='1'){
                flag=true;
            }
            if(!flag){
                cout<<"-1\n";
                return;
            }
        }
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