// https://codeforces.com/contest/1209/problem/C
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
    string s;
    cin>>s;
    vector<int>arr;
    for(int i: s){
        arr.push_back(i-'0');
    }

    vector<int>t = arr;
    vector<int>second;
    sort(t.begin(), t.end());
    int ptr1=0, ptr2=0;
    string ans="";
    int mx=-inf;
    while(ptr1<n){
        if(t[ptr2] == arr[ptr1]){
            ans += "1";
            ptr2++;
        }
        else{
            ans += "2";
            second.push_back(arr[ptr1]);
        }
        ptr1++;
    }   

    vector<int>t2 = second;
    sort(t2.begin(), t2.end());
    if(t2 == second){
        cout<<ans<<endl;
    }
    else cout<<"-"<<endl;

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