#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    ll ans=0;
    for(int i=1; i<=n; i++){
        ans += abs(i-arr[i-1]);
    }
    cout<<ans<<endl;
}