#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

void solve(){
    int n;
    cin>>n;

    int a[105] = {0}, //the number of binary strings of length i which do not contain any two consecutive 1’s and which end in 0
        b[105] = {0}; // the number of such strings which end in 1
    a[0]=b[0]=1;
    // a[0] means binary string of len 1 and end woth 0 that is 0, so possible string are 1
    // b[0] means binary string of len 1 and end with 1 that is 1, so possible strings are 1

    // now we can append either 0 0r 1 to string that end with 0
    // so a[i] = a[i-1]+b[i-1]

    // but we can append only 0 tovstring that end with 1
    // so b[i] = b[i-1]

    for(int i=1; i<n; i++){
        a[i] = (a[i-1]+b[i-1])%mod;
        b[i] = (a[i-1])%mod;
    }
    cout<<(a[n-1]+b[n-1])%mod<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}