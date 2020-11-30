//https://leetcode.com/problems/find-the-most-competitive-subsequence/
#include<iostream>
#include<vector>
#include<stack>
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

vector<int> mostCompetitive(vector<int>& nums, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int>s;
    int n=nums.size();

    for(int i=0; i<n; i++){
        while(!s.empty() and nums[i]<nums[s.top()] and n-i+s.size()>k){
            s.pop();
        }
        if(s.size()<k){
            s.push(i);
        }
    }

    vector<int>ans(k);
    for(int i=k-1; i>=0; i--){
        ans[i]=nums[s.top()];
        s.pop();
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