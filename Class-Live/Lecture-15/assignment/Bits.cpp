#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int n;
    cin>>n;
    while(n--){
        ll l,r;
        cin>>l>>r;

        for(ll i=1; (l|i)<=r; i = i<<1){
            l = l|i;
        }
        cout<<l<<endl;
    }
    return 0;
}