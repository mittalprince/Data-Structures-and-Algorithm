#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

int main(){

    int n;
    cin>>n;
    vector<int> arr(n+1);

    for(int i=1; i<=n; i++){
        cin>>arr[i];
        arr[i] = arr[i]^arr[i-1];
    }
    ll ans=0;

    for(int i=0, p=1; i<30; i++, p <<= 1){
        ll c=0;
        for(int j=0; j<=n; j++){
            if(arr[j]&p) c++;
        }
        ans += c*(n-c+1)*p;
    }
    cout<<ans<<endl;
    return 0;
}