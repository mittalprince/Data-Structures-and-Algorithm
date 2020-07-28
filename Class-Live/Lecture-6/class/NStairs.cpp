#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int nstairs(int n, int k){
    if(n==0) return 1;
    if(n<0) return 0;

    int ans=0;
    for(int i=1; i<=k; i++){
        ans += nstairs(n-i, k);
    }
    return ans;
}
 
int main(){
    int n, k;
    cin>>n>>k;
    cout<<nstairs(n,k)<<endl;
    return 0;
}