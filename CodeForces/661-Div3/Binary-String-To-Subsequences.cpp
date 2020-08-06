// https://codeforces.com/contest/1399/problem/D
#include<iostream>
#include<vector>
#include<queue>
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
    string s;
    cin>>s;

    vector<int>ans(n);
    queue<int>one, zero;
    int ct=1;
    for(int i=0; i<n; i++){
        if(s[i]=='0'){
            if(zero.empty()){
                ans[i] = ct;
                one.push(ct++);
            }
            else{
                ans[i] = zero.front();
                one.push(zero.front());
                zero.pop();
            }
        }
        else{
            if(one.empty()){
                ans[i]=ct;
                zero.push(ct++);
            }
            else{
                ans[i] = one.front();
                zero.push(one.front());
                one.pop();
            }
        }
    }

    cout<<ct-1<<endl;
    for(int i: ans){
        cout<<i<<" ";
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