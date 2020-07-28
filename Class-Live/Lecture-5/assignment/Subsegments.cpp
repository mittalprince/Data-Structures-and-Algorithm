#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    ll n,k;
    cin>>n>>k;

    map<ll ,ll>freq;
    set<ll, greater<ll> > s;
    ll arr[n];
    ip(arr, n);

    vector<string>ans;
    for(ll i=0; i<k; i++){
        if(freq.find(arr[i]) == freq.end()){
            freq[arr[i]] =1;
            s.insert(arr[i]);
        }
        else{
            freq[arr[i]]++;
            auto it = s.find(arr[i]);
            if(it != s.end()) s.erase(it);
        }
    }
    if(s.empty()){
        ans.push_back("Nothing");
    }
    else ans.push_back(to_string(*s.begin()));

    for(ll i=k; i<n; i++){

        if(freq[arr[i-k]] == 1){
            auto it = s.find(arr[i-k]);
            if(it != s.end()) s.erase(it);
            auto it2 = freq.find(arr[i-k]);
            if(it2 != freq.end()) freq.erase(it2);
        }
        else{
            freq[arr[i-k]]--;
            if(freq[arr[i-k]] == 1){
                s.insert(arr[i-k]);
            }
        }

        if(freq.find(arr[i]) == freq.end()){
            freq[arr[i]]=1;
            s.insert(arr[i]);
        }
        else{
            freq[arr[i]]++;
            auto it = s.find(arr[i]);
            if(it != s.end()) s.erase(it);
        }

        if(s.empty()){
            ans.push_back("Nothing");
        }
        else ans.push_back(to_string(*s.begin()));
    }

    for(ll i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}