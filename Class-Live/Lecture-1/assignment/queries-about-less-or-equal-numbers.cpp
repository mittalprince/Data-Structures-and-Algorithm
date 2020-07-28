#include<iostream>
#include<climits>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll search(ll arr[], ll s, ll e, ll target){
    ll ans=0;
    while(s<=e){
        ll mid = (s+e)/2;
        if(arr[mid] <= target){
            ans = mid+1;
            s=mid+1;
        }
        else e=mid-1;
    }
    return ans;
}
int main(){
    ll na,nb;
    cin>>na>>nb;
    ll arr[na], arr2[nb];
    for(ll i=0; i<na; i++){
        cin>>arr[i];
    }
    for(ll i=0; i<nb; i++){
        cin>>arr2[i];
    }
    sort(arr, arr+na);
    for(ll i=0; i<nb; i++){
        cout<<search(arr, 0, na-1, arr2[i])<<" ";
    }
}