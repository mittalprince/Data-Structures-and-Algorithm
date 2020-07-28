#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 200005

int main(){
    int n, q, l, r;
    cin>>n>>q;
    ll arr[MAX], freq[MAX]={0}, b[MAX]={0};
    
    ip(arr, n);
    sort(arr, arr+n);

    while(q--){
        cin>>l>>r;
        l--;
        freq[l]++;
        if(r<n) freq[r]--;
    }
    ll val=0;
    for(int i=0; i<n; i++){
        val += freq[i];
        b[i] = val;
    }
    sort(b, b+n);
    ll ans=0;
    for(int i=0; i<n; i++){
        ans += (arr[i]*b[i]);
    }
    cout<<ans<<endl;
    return 0;
}