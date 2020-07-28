#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    ll n;
    cin>>n;
    char arr[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    bool flag=true;

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if(arr[i][j]=='1'){
                if(i==n-1 || j==n-1)continue;
                else if(arr[i+1][j]=='1' || arr[i][j+1]=='1')continue;
                else{
                    flag=false; 
                    break;
                }
            }
        }
    }
    (flag)?cout<<"YES\n":cout<<"NO\n";
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}