#include<iostream>
#include<vector>
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
    int n;
    cin>>n;
    vector<int> arr(n);
    ip(arr, n);

    vector<pair<int, int> >ans; // {count of factors, arr[i] element}

    for(int i: arr){ // here i  is arr[i]
        int ct=0;
        for(int j=1; j*j<=i; j++){
            if(i%j==0){
                ct++;
                if(i/j != j)ct++;
            }
        }
        // cout<<i<<" -> "<<ct<<endl;
        ans.push_back({ct, i});
    }

    sort(ans.begin(), ans.end(), [&](const pair<int,int>&a, const pair<int,int>&b)->bool{
        return a.first>b.first;
    });

    for(pair<int, int>&i: ans){
        cout<<i.second<<" ";
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

// complexity -> n*sqrt(n)