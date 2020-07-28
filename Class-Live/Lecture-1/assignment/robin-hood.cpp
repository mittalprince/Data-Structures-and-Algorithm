#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define MAX 500005

ll n,k;
ll arr[MAX]={0};

bool canMakeMax(ll mid){
    ll greater_diff=0, lesser_diff=0;
    for(ll i=0; i<n; i++){
        if(arr[i]>mid){
            greater_diff += arr[i]-mid;
        }
        else{
            lesser_diff += mid-arr[i];
        }
    }
    // mein phela check kiya ki jo element mid se bda hai (greater_diff) mein unme se k time 1 deduct kar sakta hoo ki nahi
    // then check kiya jo element mid se chota (lesser_diff)hai usme kitna 1 add kar sakta hai
    // then check kiya ki lesser_diff greater_diff se bda ya equal hai ya nahi 
    // qki mein utne hi 1 deduct kar sakta hoo jitna add kar sakta hoo
    // toh dono lesser ka equal ya jyda hona imp haio
    if(greater_diff<=k && lesser_diff>=greater_diff) return true;
    return false;
}
bool canMakeMin(ll mid){
    ll greater_diff=0, lesser_diff=0;
    for(ll i=0; i<n; i++){
        if(arr[i]<mid){
            lesser_diff += mid-arr[i];
        }
        else{
            greater_diff += arr[i]-mid;
        }
    }
    // same logic as above, just lesser and greater variable change

    // mein <= k isliye kiya qki k se jayda nahi hone chaiye
    // agr koi bhi k se chota milta hai toh matalb ek yeh ans ho sakta hai 
    // but mein koshish karunga ki voh at most k kar sake, isliye <= k check iya and range ko change kiya neecha
    if(lesser_diff<=k && greater_diff>=lesser_diff) return true;
    return false;
}
int main(){
    cin>>n>>k;
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    ll MX=arr[n-1], MI=arr[0];
    ll s=arr[0], e=arr[n-1];
    while(s<=e){
        ll mid = (s+e)/2;
        if(canMakeMax(mid)){
            // agr yeh mid satisfy kar rha hai toh isse bade sare karenge
            // so range ko decrease kiya
            MX=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    s=arr[0], e=arr[n-1];
    while(s<=e){
        ll mid = (s+e)/2;
        if(canMakeMin(mid)){
            // agr yeh mid satisfy kar rha hai toh isse chote sare karenge
            // so range ko incr kiya
            // i.e agr yeh min element ban sakta hai toh isse chota sare ban sakta hai
            MI=mid;
            s=mid+1;
        }
        else e=mid-1;
    }
    cout<<MX-MI<<endl;
}