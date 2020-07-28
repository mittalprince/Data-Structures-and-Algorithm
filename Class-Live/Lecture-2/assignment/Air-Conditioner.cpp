#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// we basically use two pointer apporach, means we take two var min_temp, max_temp
// these var store ki hum ith customer ane se humari max, min temp kya ho sakta hai
// then we check if ki agr mera max temp ki customer ke low_temp se chota hai toh obvious unstaify hai
// simillary agr mera min temp jo hai voh uska high_temp se jadya hai toh bhi unsatisfy rahega
 

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,inital_temp;
        cin>>n>>inital_temp;
        ll t[n], l[n], h[n];
        for(ll i=0; i<n; i++){
            cin>>t[i]>>l[i]>>h[i]; // store time, low, high temp
        }

        ll prev_temp=0; // intially for first customer we sub 0 to make his range
        ll max_temp=inital_temp, min_temp=inital_temp; 
        // starting mein mera max, min dono initial hi hoga
        bool exist = true;
        for(ll i=0; i<n; i++){
            // abb mein apne abhi tak ke max_temp jo customer ko statisfy kar rha tha, usme prev customer
            // ke incoming time aur abhi vale ka time ka diff add kar diya
            // qki i sec mein 1 temp either + or -
            // so max_temp ke liye diff ko add kiya, ki itna max range hogi
            // simillary for min_tmep
            max_temp += t[i]-prev_temp; 
            min_temp -= t[i]-prev_temp;

            // here check ki out of customer range toh nahi
            if(max_temp< l[i] || min_temp>h[i]){
                exist = false;
                break;
            }

            // max temp har customer ke ane ke baad voh hoga ya toh jo vph chahata tha ya jo humara aya tha
            // toh inn dono mein se min possible lenge
            max_temp = min(h[i], max_temp);
            // min temp har customer ke ane ke baad voh hoga ya toh jo vph chahata tha ya jo humara aya tha
            // toh inn dono mein se max possible lenge
            min_temp = max(l[i], min_temp);
            prev_temp = t[i];
        }

        if(exist){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }

    return 0;
}