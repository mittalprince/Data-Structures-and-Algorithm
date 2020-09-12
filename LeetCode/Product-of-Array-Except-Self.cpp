// https://leetcode.com/problems/product-of-array-except-self/
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

vector<int> productExceptSelf(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=nums.size();
    vector<int>ans(n);

    ans[0]=1;
    for(int i=1; i<n; i++){
        ans[i] = ans[i-1]*nums[i-1];
    }

    int prod = 1;
    for(int i=n-1; i>=0; i--){
        ans[i] = ans[i]*prod;
        prod *= nums[i];
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