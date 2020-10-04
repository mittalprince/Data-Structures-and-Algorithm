// https://leetcode.com/problems/remove-covered-intervals/
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
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

int removeCoveredIntervals(vector<vector<int>>& intervals) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n=intervals.size();
    sort(intervals.begin(), intervals.end(), [&](const vector<int>&a, const vector<int>&b)->bool{
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    });

    int idx=0;
    for(int i=1; i<n; i++){
        if(intervals[idx][0] <= intervals[i][0] and intervals[idx][1] >= intervals[i][1]){
            intervals[idx][1] = max(intervals[i][1], intervals[idx][1]);
            intervals[idx][0] = min(intervals[i][0], intervals[idx][0]);
        }
        else{
            idx++;
            intervals[idx][0]=intervals[i][0];
            intervals[idx][1]=intervals[i][1];
        }
    }

    return idx+1;
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