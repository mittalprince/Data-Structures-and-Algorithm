#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin>>n>>m;
    ll arr[n];
    for(int i=0; i<n; i++){
        ll c,t;
        cin>>c>>t;
        arr[i] = c*t;
        if(i>0) arr[i]=arr[i-1]+arr[i];
    }
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    while(m--){
        int x;
        cin>>x;
        int l=0, r=n-1;
        int ans=0;
        while(l<=r){
            int mid = (l+r)/2;
            // phela aise no jo x se bda hai ya uska equal hai
            // lower bound -> which gives pos (phela aise no) whose val is equal to or greater than than the target value 
            if(arr[mid]>=x){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<ans+1<<endl;
    }
}