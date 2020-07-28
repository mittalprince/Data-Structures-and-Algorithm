// https://codeforces.com/contest/1370/problem/B
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
    int n;
    cin>>n;
    vector<int>odd, even;
    for(int i=0; i<2*n; i++){
        int x;
        cin>>x;
        if(x&1)odd.push_back(i+1);
        else even.push_back(i+1);
    }
    int s = even.size();
    if(s&1){
        even.pop_back();
        odd.pop_back();
        for(int i=0; i<even.size(); i+=2){
            cout<<even[i]<<" "<<even[i+1]<<endl;
        }
        for(int i=0; i<odd.size(); i+=2){
            cout<<odd[i]<<" "<<odd[i+1]<<endl;
        }
    }
    else{
        if(s>=2){
            even.pop_back();
            even.pop_back();
        }
        else{
            odd.pop_back();
            odd.pop_back();
        }
        for(int i=0; i<even.size(); i+=2){
            cout<<even[i]<<" "<<even[i+1]<<endl;
        }
        for(int i=0; i<odd.size(); i+=2){
            cout<<odd[i]<<" "<<odd[i+1]<<endl;
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