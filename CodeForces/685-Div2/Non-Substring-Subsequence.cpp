//https://codeforces.com/contest/1451/problem/B
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
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;

    vector<int>zero, one;
    for(int i=0; i<n; i++){
        if(s[i]=='0'){
            zero.push_back(i+1);
        }
        else one.push_back(i+1);
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        if(zero.size() and s[l-1]=='0' and zero[0]<l){
            cout<<"YES\n";
        }
        else if(one.size() and s[l-1]=='1' and one[0]<l){
            cout<<"YES\n";
        }
        else if(zero.size() and s[r-1]=='0' and zero.back()>r){
            cout<<"YES\n";
        }
        else if(one.size() and s[r-1]=='1' && one.back()>r){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
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