//https://leetcode.com/problems/set-mismatch/
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

vector<int> findErrorNums(vector<int>& nums) {
    int correctSum = (nums.size()*(2 + nums.size()-1))/2;
    int actualSum = 0;
    int badNum = 0;        
    for (auto n : nums) {
        nums[abs(n)-1] *= -1;
        if (nums[abs(n)-1] > 0) {
            badNum = abs(n);
        }
        actualSum += abs(n);
    }
    return {badNum, correctSum - (actualSum - badNum)};
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