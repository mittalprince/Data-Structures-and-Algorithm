#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int calSummation(int arr[], int n, int i){
    if(i==n){
        return 0;
    }
    return arr[i]+calSummation(arr, n, i+1);
}
void solve(){
    int n;
    cin>>n;
    int arr[n];
    ip(arr, n);
    cout<<calSummation(arr, n, 0)<<endl;
}

int main(){
    int t;
    cin>>t;
    int tc=1;
     while(t--){
         cout<<"Case "<<tc<<": ";
         solve();
         tc++;
    }
    return 0;
}