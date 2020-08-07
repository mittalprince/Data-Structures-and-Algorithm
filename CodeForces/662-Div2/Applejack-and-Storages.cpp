// https://codeforces.com/contest/1393/problem/B
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
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
    ll n;
    cin>>n;
    unordered_map<ll, ll>m;
    ll arr[2]={0};

    for(int i=0; i<n; i++){
        ll c;
        cin>>c;
        m[c]++;
        if(m[c]%4 == 0){
            arr[0]--;
            arr[1]++;
        }
        else if(m[c]%4 == 2){
            arr[0]++;
        }
    }

    int q;
    cin>>q;
    while(q--){
        char ch;
        ll x;
        cin>>ch>>x;
        if(ch=='+'){
            m[x]++;  
            if(m[x]%4 == 0){
                arr[0]--;
                arr[1]++;
            }
            else if(m[x]%4 == 2){
                arr[0]++;
            }  
        }
        else{
            if(m[x]%4 == 2){
                arr[0]--;
            }
            else if(m[x]%4 == 0){
                arr[1]--;
                arr[0]++;
            }
            m[x]--;
        }

        if(arr[1]>=2 or (arr[1]>0 and arr[0]>=2)){
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

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}