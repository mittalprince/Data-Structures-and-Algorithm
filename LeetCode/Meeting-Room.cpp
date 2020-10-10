// https://www.lintcode.com/problem/meeting-rooms/description
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

class Interval {
    public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

bool canAttendMeetings(vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(), [&](const Interval &a, const Interval &b)->bool{
        return a.start<b.start;
    });
    int n=intervals.size();
    for(int i=0; i<n-1; i++){
        if(intervals[i].end>intervals[i+1].start)return false;
    }
    return true;
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