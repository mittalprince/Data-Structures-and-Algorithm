// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
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

static bool comp (pair<int, int>& i, pair<int, int>& j) { 
    return i.second < j.second; 
}

int findMinArrowShots(vector<vector<int>>& p) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = p.size();
    if (n == 0)
        return 0;
    int i;
    vector<pair<int, int>> interval;
    for(i = 0; i < n; ++i){
        interval.push_back({p[i][0], p[i][1]});
    }
    sort(interval.begin(), interval.end(), comp);

    auto res = 1;
    auto ce = interval[0].second;
    for (i = 1; i < n; ++i) {
        if (interval[i].first <= ce)
        {
            continue;
        } else {
            ce = interval[i].second;
            ++res;    
        }


    }
    return res;
    // res=1 qki jitne baar non overlapping interval hai usse ek jayda arrow chahiye
    // as we have _|_|_|_ 3 line but actually we have 4 blank spaces
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