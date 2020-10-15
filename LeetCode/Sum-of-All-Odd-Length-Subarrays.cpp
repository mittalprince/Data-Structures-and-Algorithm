//https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
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

int sumOddLengthSubarrays(vector<int>& arr) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=arr.size();
    int ans=0;
    for(int i=0; i<n; i++){
        int t=0;
        for(int j=i; j<n; j++){
            t += arr[j];
            if((j-i+1)&1){
                ans += t;
            }
        }
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