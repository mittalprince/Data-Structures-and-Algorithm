// https://codeforces.com/contest/451/problem/B
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
    vector<int>arr(n), b(n);
    ip(arr, n);
    b = arr;
    sort(b.begin(), b.end());
    vector<pair<int, int> >t;
    for(int i=0; i<n; i++){
        int start=i;
        while(start<n-1 and arr[start]>arr[start+1])start++;
        if(start-i>=1){
            t.push_back({i, start});
        }
        i=start;
    }

    if(t.empty()){
        cout<<"yes\n";
        cout<<"1 1\n";
        return;
    }
    if(t.size()==1){
        reverse(arr.begin()+t[0].first, arr.begin()+t[0].second+1);
        if(arr == b){
            cout<<"yes\n";
            cout<<t[0].first+1<<" "<<t[0].second+1<<endl;   
        }
        else cout<<"no\n";
    }
    else cout<<"no\n";
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