#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// logic is if agr kissi bhi no mein ith msb bit set hai toh ans mein voh bit set hogi
// so in this case we bassiliccy set ith bit in ans (1<<bit)

// now we in every no if ith bit is either completely set or not that in both case the contribution of 
// thos bit to ans will be 0. so we dont add (1<<bit)

// now abb humne msb ith bit toh dekh lee abb hum no's ko unki msb bit ke acc segregate kar denge
// qki hume yeh toh pta chal gya ki iss bit se ans mein kya contribution hoga, so to cal contribution of other we use recc

ll DrEvil(vector<ll>arr, int bit){
    if(arr.empty() || bit<0){
        return 0;
    }
    vector<ll> one, zero;

    // Segregagate karo, ones and zeros mei according to MSB
    int mask = (1<<bit);
    for(ll i=0; i<arr.size(); i++){
        if(arr[i]&mask){
            one.push_back(arr[i]);
        }
        else{
            // MSB is 0, insert it into the array ones
            zero.push_back(arr[i]);
        }
    }
    
    if(zero.empty()) return DrEvil(one, bit-1);
    // if size of ones is 0, then ask only from zeros the answer
    if(one.empty()) return DrEvil(zero, bit-1);

    // Otherwise take the minimum of zeros and ones jo bhi unmei se chota answer dede hume that will the answer
    // here MSB will be equals to one for sure
    return min(DrEvil(zero, bit-1), DrEvil(one, bit)) + (1<<bit);
}

int main(){
    int n;
    cin>>n;
    vector<ll>arr(n);
    ip(arr, n);
    cout<<DrEvil(arr, 30)<<endl;
    return 0;
}