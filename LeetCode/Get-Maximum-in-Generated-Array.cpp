//https://leetcode.com/problems/get-maximum-in-generated-array/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

int getMaximumGenerated(int n) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(n<=1)return n;
    vector<int>arr(n+1);
    arr[0]=0;
    arr[1]=1;
    int ans=0;

    for(int i=2; i<=n; i++){
        if(i&1){
            arr[i] = arr[i/2]+arr[i/2+1];
        }
        else{
            arr[i] = arr[i/2];
        }
        ans = max(ans, arr[i]);
    }
    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}