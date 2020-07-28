#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int>dp(arr.size()+1, 0);
    
    for(int i=1; i<=arr.size(); i++){
        dp[i] = dp[i-1]^arr[i-1];
    }
    
    vector<int>ans;
    
    for(int i=0; i<queries.size(); i++){
        int l = queries[i][0];
        int r = queries[i][1]+1;
        
        ans.push_back(dp[r]^dp[l]);
    }
    
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}