// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
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

// const int MOD = 1000000007;

int numOfSubarrays(vector<int>& A) {
    long long arr[2]={1,0};
    unsigned long long ans=0, val=0;

    for(int i=0; i<A.size(); i++){
        val = ((val + A[i]) % 2 + 2) % 2; 
        arr[val]++;
    }
    ans=(arr[0]%MOD * arr[1]%MOD)%MOD;
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