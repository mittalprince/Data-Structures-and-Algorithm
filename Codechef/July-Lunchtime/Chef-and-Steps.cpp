// https://www.codechef.com/LTIME86B/problems/CHEFSTEP
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){

    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        
        for(int i=0; i<n; i++)cin>>arr[i];

        string ans="";
        for(ll i=0; i<n; i++){
            if(arr[i]%k){
                ans += "0";
            }
            else ans += "1";
        }
        cout<<ans<<endl;
    }
    return 0;
}