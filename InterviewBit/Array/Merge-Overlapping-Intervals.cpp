// https://www.interviewbit.com/problems/merge-overlapping-intervals/
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

vector<Interval> merge(vector<Interval>&A){
    int n=A.size();
    if(n==0)return {};

    vector<Interval>ans;
    sort(A.begin(), A.end(), [&](const Interval &a, const Interval &b)->bool{
        return a.start < b.start;
    });

    int idx=0;
    ans.push_back(A[0]);

    for(int i=1; i<n; i++){
        if(ans[idx].end >= A[i].start){
            ans[idx].start = min(ans[idx].start, A[i].start);
            ans[idx].end = max(ans[idx].end, A[i].end);
        }
        else{
            ans.push_back(A[i]);
            idx++;
        }
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