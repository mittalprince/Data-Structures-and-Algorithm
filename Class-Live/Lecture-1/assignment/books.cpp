#include<iostream>
#include<climits>
using namespace std;
typedef long long ll;

int main(){
    ll n,t;
    cin>>n>>t;
    ll arr[n];
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    ll sum=0, l=0, ans=0;
    for(ll i=0; i<n; i++){
        sum += arr[i];
        while(sum>t){
            sum -= arr[l++];
        }
        // new elemnt count = i-l+1 as index start from 0, so we add +1 extra (0-2 = 3 elemnt, but 2-0 = 2)
        ans = max(ans, i-l+1);
    }
    cout<<ans<<endl;

    // ll j=0, sum=0;
    // while(j<n && sum+arr[j]<t){
    //     sum += arr[j++];
    // }
    // ll ans=j;
    // for(ll i=0; i<n; i++){
    //     sum -= arr[i];
    //     while(j<n && sum+arr[j]<t){
    //         sum += arr[j++];
    //     }
           // new elmnt ct = j-1-i, as j will be incremt one extra time, so j-1 and we have to remove ith elemnt so just -i  
    //     ans = max(ans, j-i-1);
    // }
    // cout<<ans<<endl;
}