#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int minSetSize(vector<int>& arr) {
    unordered_map<int,int>mp; 
    vector<int>dp;
    for(auto x:arr) mp[x]++;

    for(auto x:mp) dp.push_back(x.second);

    sort(dp.begin(),dp.end()); 

    int sum=0,ans=0;
    for(int i=dp.size()-1 ; i>=0 ; i--)
    {
        sum+=dp[i];
        if(sum>=arr.size()/2){ 
            ans=dp.size()-i; 
            break;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}