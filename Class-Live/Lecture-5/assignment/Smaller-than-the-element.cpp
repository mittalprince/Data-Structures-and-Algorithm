#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    ll n, temp;
    cin>>n;
    set<ll> s;
    for(int i=0; i<n; i++){
        cin>>temp;
        auto it = s.lower_bound(temp);
        if(it == s.begin()){
            cout<<"-1\n";
        }
        else{
            cout<<*(--it)<<endl;
        }
        s.insert(temp);
    }
    return 0;
}