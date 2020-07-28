#include<iostream>
#include<climits>
using namespace std;
typedef long long ll;
#define MAX 100005

int main(){
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    ll left[n+1], right[n+1];
    left[0]=INT_MIN;
    for(int i=1; i<=n; i++){
        left[i] = max(left[i-1], arr[i-1]);
    }
    right[n]=INT_MAX;
    for(int i=n-1; i>=0; i--){
        right[i] = min(right[i+1], arr[i]);
    }

    ll ans = 1;
    for(int i=1; i<n; i++){
        if(left[i] <= right[i]){
            ans++;
        }
    }

    cout<<ans<<endl;
}