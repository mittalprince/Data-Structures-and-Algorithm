// https://leetcode.com/problems/132-pattern/
#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<climits>
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

bool find132pattern(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int third=INT_MIN;
    stack<int>s;

    reverse(nums.begin(), nums.end());
    for(int i: nums){
        if(i<third)return true;
        while(!s.empty() and s.top()<i){
            third=s.top();
            s.pop();
        }
        s.push(i);
    }

    return false;
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