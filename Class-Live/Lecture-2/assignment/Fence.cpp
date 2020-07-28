#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    ll ans=0;
    for(int i=0; i<k; i++){
        ans += arr[i];
    }
    // cout<<ans<<endl;
    ll temp=ans;
    int idx=0;
    for(int i=1; i<=n-k; i++){
        temp = temp-arr[i-1]+arr[i+k-1];
        if(ans>temp){
            ans=temp;
            idx=i;
        }
    }
    cout<<idx+1<<endl;
}