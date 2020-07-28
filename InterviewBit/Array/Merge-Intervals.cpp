// https://www.interviewbit.com/problems/merge-intervals/
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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    if(newInterval.start > newInterval.end){
        swap(newInterval.start, newInterval.end);
    }

    int n = intervals.size();
    vector<Interval>ans;

    if(n==0){
        ans.push_back(newInterval);
        return ans;
    }

    for(int i=0; i<n; i++){
        if(max(newInterval.start, intervals[i].start) <= min(newInterval.end, intervals[i].end)){
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
        }
        else{
            ans.push_back(intervals[i]);
        }
    }

    int j=0;
    while(j<n and intervals[j].start<newInterval.start){
        j++;
    }

    ans.insert(ans.begin()+j, newInterval);
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