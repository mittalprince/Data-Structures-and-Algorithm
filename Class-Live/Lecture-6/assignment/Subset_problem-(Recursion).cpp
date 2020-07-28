#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(ll i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(ll i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll ans=0;
void findSubsets(vector<ll>arr, ll n, ll i, ll sum, vector<ll> temp){
    if(sum < 0 || i>=n) return;
    if(i == (n-1) && sum == arr[i]){
        ans++;
        temp.push_back(arr[i]);
        for(ll j=0; j<temp.size(); j++)
            cout<<temp[j]<<" ";
        cout<<" ";
    }
    if(sum == 0){
        ans++;
        for(ll j=0; j<temp.size(); j++)
            cout<<temp[j]<<" ";
        cout<<" ";
        return; 
    }
    temp.push_back(arr[i]);
    findSubsets(arr, n, i+1, sum-arr[i], temp);
    temp.pop_back();
    findSubsets(arr, n, i + 1, sum, temp);
}

ll findsubsets(ll arr[], ll n, ll i, ll sum, ll target, string ans){
    if(i == n){
        if(target == sum){
            cout<<ans<<" ";
            return 1;
        }
        return 0;
    }

    ll ct=0;
    ct += findsubsets(arr, n, i+1, sum+arr[i], target, ans+to_string(arr[i])+" ");
    ct += findsubsets(arr, n, i+1, sum, target, ans);
    return ct;
}

void helper(){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0; i<n; i++) cin>>arr[i]; 
    string ans="";
    int target=0;
    cin>>target;
    ll ct = findsubsets(arr, n, 0, 0, target, ans);
    cout<<endl<<ct<<endl;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    ll sum=0;
    cin>>sum;
    vector<ll>temp;
    findSubsets(arr, n, 0, sum, temp);
    cout<<endl<<ans<<endl;
    // helper();
    return 0;
}