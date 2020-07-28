// https://codeforces.com/contest/1382/problem/C2
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

/*
In first step I perform operation on A string
First I make string A into a string that contain only one type of char only

Ex: 010101
iteration 1: 0
          2: 11
          3: 000
          4: 1111
          5: 00000
          6: 111111

Now I perform operation on B string, means check if ith pos match with B[i] or not
if not then reverrse the whole string berfore it, so insert (i+1)  
*/
void solve(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;

    vector<ll>ans;
    char curr=a[0];

    for(int i=0; i<n; i++){
        if(a[i] == curr)continue;
        else{
            ans.push_back(i);
            if(curr == '0')curr='1';
            else curr='0';
            // cout<<i<<" "<<curr<<endl;
        }
    }
    // for(int i: ans){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    for(int i=n-1; i>=0; i--){
        if(b[i] == curr)continue;
        else{
            ans.push_back(i+1);
            if(curr == '0')curr='1';
            else curr='0';
        }
    }
    
    cout<<ans.size()<<" ";
    if(ans.size()){
        for(int i: ans){
            cout<<i<<" ";
        }
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