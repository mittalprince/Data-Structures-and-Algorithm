// https://leetcode.com/problems/maximum-number-of-visible-points/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
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

int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& loc) {
    vector<double> angs;
    int max_points = 0, overlap = 0;
    for (auto &p : points) {
        if (p[1] == loc[1] && p[0] == loc[0])
            ++overlap;
        else
            angs.push_back(atan2(p[1] - loc[1], p[0] - loc[0]) * 180 / M_PI);
    }
    sort(begin(angs), end(angs));
    int sz = angs.size();
    for (int i = 0, j = 0; i < sz * 2 and j<=i; ++i) {
        while (360 * (i >= sz) + angs[i % sz] - 360 * (j >= sz) - angs[j % sz] > angle)
            ++j;
        max_points = max(max_points, i - j + 1);
    }
    return max_points + overlap;
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