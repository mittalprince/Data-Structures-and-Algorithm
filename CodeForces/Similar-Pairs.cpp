#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    int n;
    cin>>n;

    vector<int>even, odd;
    map<int, int>m;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x&1){
            odd.push_back(x);
        }
        else{
            even.push_back(x);
            m[x]++;
        }
    }

    ll e=even.size(), o=odd.size();

    if((e%2 == 0) && (o%2 == 0)){
        cout<<"YES\n";
        return;
    }
    if((e%2) != (o%2)){
        cout<<"NO\n";
        return;
    }

    for(int i=0; i<o; i++){
        if(m[odd[i]+1]>0 || m[odd[i]-1]>0){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}