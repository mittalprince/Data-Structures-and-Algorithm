#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,q;
    cin>>n>>q;
    ll arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(i>0) arr[i]=arr[i-1]+arr[i];
    }
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    ll temp=0;
    while(q--){
        ll time;
        cin>>time;
        temp += time;
        if(temp >= arr[n-1]){
            cout<<n<<endl;
            temp=0;
        }
        else{
            ll ans=0;
            ll l=0, r=n-1;
            while(l<=r){
                ll mid = (l+r)/2;
                // phela aise no jo x se bda hai ya uska equal hai
                // lower bound -> which gives pos (phela aise no) whose val is equal to or greater than than the target value 
                if(arr[mid]>=temp){
                    ans=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            // cout<<arr[ans]<<"P"<<endl;
            if(arr[ans] == temp){
                cout<<n-(ans+1)<<endl;
            }
            else cout<<n-ans<<endl;
            // cout<<n-(ans+1)<<endl;
        }
    }
}
