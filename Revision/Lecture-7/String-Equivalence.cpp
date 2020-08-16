// https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_d
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

void stringEquivalence(int i, string t, char max_char){
    if(i==n){
        cout<<t<<endl;
        return;
    }
    for(char c='a'; c<=max_char; c++){
        t += c;
        if(c==max_char){
            stringEquivalence(i+1, t, max_char+1);
        }
        else stringEquivalence(i+1, t, max_char);
        t.pop_back();
    }
}

void solve(){
    cin>>n;
    stringEquivalence(0, "", 'a');
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