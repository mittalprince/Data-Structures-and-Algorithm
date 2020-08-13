// https://codeforces.com/contest/69/problem/E
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<iterator>
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
    int n,k;
    cin>>n>>k;

    unordered_map<ll, ll>freq;
    set<ll, greater<ll> >s;

    ll arr[n];
    ip(arr, n);

    for(int i=0; i<k; i++){
        if(!freq.count(arr[i])){
            freq[arr[i]]++;
            s.insert(arr[i]);
        }
        else{
            freq[arr[i]]++;
            set<ll, greater<ll> >::iterator it = s.find(arr[i]);
            if(it!=s.end())s.erase(it);
        }
    }
    vector<string>ans;
    if(s.empty())ans.push_back("Nothing");
    else ans.push_back(to_string(*s.begin()));

    for(int i=k; i<n; i++){
        if(freq[arr[i-k]]==1){
            set<ll, greater<ll> >::iterator it = s.find(arr[i-k]);
            if(it != s.end()) s.erase(it);
            unordered_map<ll, ll>::iterator it2 = freq.find(arr[i-k]);
            if(it2 != freq.end())freq.erase(it2);
        }
        else{
            freq[arr[i-k]]--;
            if(freq[arr[i-k]] == 1){
                s.insert(arr[i-k]);
            }
        }
        if(!freq.count(arr[i])){
            freq[arr[i]]++;
            s.insert(arr[i]);
        }
        else{
            freq[arr[i]]++;
            set<ll, greater<ll> >::iterator it = s.find(arr[i]);
            if(it!=s.end())s.erase(it);
        }

        if(s.empty())ans.push_back("Nothing");
        else ans.push_back(to_string(*s.begin()));

    }

    for(string i: ans){
        cout<<i<<"\n";
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