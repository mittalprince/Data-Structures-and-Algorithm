// https://leetcode.com/problems/maximum-number-of-robots-within-budget/
#include<iostream>
#include<vector>
#include<set>
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

int maximumRobots(vector<int>& times, vector<int>& costs, long long budget) {
    long long i = 0, j, sum = 0, n = times.size();
    multiset<int> s;
    long long ans=0;
    for (int j = 0; j < n; ++j) {
        sum += costs[j];
        s.insert(times[j]);
        if (*rbegin(s) + sum * (j - i + 1) > budget) {
            sum -= costs[i];
            s.erase(s.find(times[i++]));
        }
        ans = max(ans, j-i+1);
    }
    return ans;
    // return n - i;
}


int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}