//https://leetcode.com/problems/ways-to-make-a-fair-array/
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

int waysToMakeFair(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=nums.size();
    vector<int>e(n+1, 0),o(n+1, 0);

    for(int i=n-1; i>=0; i--){
        if(i&1){
            o[i] += nums[i];
        }
        else e[i] += nums[i];
        e[i] += e[i+1];
        o[i] += o[i+1];
    }

    int even=0, odd=0, ans=0;

    for(int i=0; i<n;i++){
        ans += (even+o[i+1] == odd+e[i+1]);
        if(i&1){
            odd += nums[i];
        }
        else even += nums[i];
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