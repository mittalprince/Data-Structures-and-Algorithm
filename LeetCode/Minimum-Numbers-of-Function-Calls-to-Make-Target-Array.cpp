// https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/
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

int minOperations(vector<int>& nums) {
    int ans=0;
    int n=nums.size();
    while(1){
        int zero=0;
        int i;
        for(i=0; i<n; i++){
            if(nums[i]&1)break;
            else if(nums[i]==0)zero++;
        }

        if(zero==n)return ans;
        if(i==n){
            for(int j=0; j<n; j++){
                nums[j] /= 2;
            }
            ans++;
        }

        for(int j=i; j<n; j++){
            if(nums[j]&1){
                ans++;
                nums[j]--;
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