#include<iostream>
#include<vector>
#include<set>
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
    int n,x;
    cin>>n;
    set<int>a,b;
    bool ans_exist=true;
    for(int i=0; i<n; i++){
        cin>>x;
        if(a.find(x) == a.end())a.insert(x);
        else if(b.find(x) == b.end())b.insert(x);
        else{
            ans_exist=false;
        }
    }
    if(!a.empty() and !b.empty()){
        if(*(a.rbegin()) == *(b.rbegin())){
            ans_exist=false;
        }
    }
    if(!ans_exist){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(int i: a){
        cout<<i<<" ";
    }
    for(auto it=b.rbegin(); it !=b.rend(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
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