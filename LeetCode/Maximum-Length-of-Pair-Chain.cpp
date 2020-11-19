//https://leetcode.com/problems/maximum-length-of-pair-chain/
#include<iostream>
#include<vector>
#include<algorithm>
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

int findLongestChain(vector<vector<int>>& pairs) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=pairs.size();
    vector<int>dp(n, 1);
    int ans=0;

    sort(pairs.begin(), pairs.end());

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(pairs[i][0] > pairs[j][1] and dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}

int findLongestChain(vector<vector<int>>& pairs) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n= pairs.size();
    pair<int, int> c[n];

    for(int i=0;i<n;i++){
           c[i].first  =pairs[i][0];
           c[i].second  =pairs[i][1];
    }

    sort(c,c+n, [&](auto a, auto b)->bool{
        return a.second<b.second;
    });

    int ans=1;
    int j=1,i=0;

    while(j<n){
        if(c[i].second<c[j].first){
            i=j;
           ans++;
        }
        j++;
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