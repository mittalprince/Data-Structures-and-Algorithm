// https://codeforces.com/contest/1315/problem/D
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<iterator>
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
    vector<pair<int, int> >arr(n);
    
    for(int i=0; i<n; i++){
        cin>>arr[i].first;
    }
    for(int i=0; i<n; i++){
        cin>>arr[i].second;
    }

    sort(arr.begin(), arr.end());
    multiset<ll>s;
    ll prev=0, ans=0, temp=0;

    for(int i=0; i<n; i++){
        while(!s.empty() and prev<arr[i].first){
            multiset<ll>::iterator it = s.end();
            --it;
            temp -= *it;
            ans += temp;
            s.erase(it);
            prev++;
        }
        prev = arr[i].first;
        temp += arr[i].second;
        s.insert(arr[i].second);
    }
    while(s.size()>1){
        multiset<ll>::iterator it = s.end();
        --it;
        temp -= *it;
        ans += temp;
        s.erase(it);
    }

    cout<<ans<<endl;
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