#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    ip(arr, n);

    int dp[k+1];
    for(int i=0; i<=k; i++) dp[i]=2;

    for(int i=1; i<=k; i++){
        for(int j=0; j<n; j++){
            if(i-arr[j]<0) continue;
            if(dp[i-arr[j]] == 2){
                dp[i]=1;
            }
        }
    }
    if(dp[k] == 2) cout<<"Second\n";
    else cout<<"First\n";
    return 0;
}