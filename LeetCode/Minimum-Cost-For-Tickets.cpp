// https://leetcode.com/problems/minimum-cost-for-tickets/
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

int mincostTickets(vector<int>& days, vector<int>& costs) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d=0;
    vector<int>dp(366, 0);

    for(int i=1; i<=365; i++){
        if(d<days.size() and days[d]==i){
            int min_cost=INT_MAX;
            int opt1 = costs[0]+dp[i-1]; // choose 1-day pass
            int opt2 = costs[1]+(i>=7?dp[i-7]:0); // choose 7-days pass
            int opt3 = costs[2]+(i>=30?dp[i-30]:0); // choose 3-day pass
            d++;
            dp[i] = min(opt1, min(opt2, opt3));
        }
        else dp[i] = dp[i-1];
    }
    return dp[365];
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