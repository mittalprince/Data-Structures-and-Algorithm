// https://leetcode.com/problems/find-right-interval/
#include<iostream>
#include<vector>
#include<map>
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

// using Binary Search
vector<int> findRightInterval(vector<vector<int>>& intervals) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=intervals.size();
    vector<int>ans(n);

    for(int i=0; i<n; i++){
        ans[i] = intervals[i][1];
        intervals[i][1]=i;
    }

    sort(intervals.begin(), intervals.end(), [&](const vector<int>a, const vector<int>b)->bool{
        return a[0]<=b[0];
    });

    for(int i=0; i<n; i++){
        int end = ans[i];

        int l=0, r=n-1, res=-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(intervals[mid][0] >= end){
                res=intervals[mid][1];
                r=mid-1;
            }
            else l=mid+1;
        }
        ans[i]=res;
    }

    return ans;
}

vector<int> findRightInterval(vector<vector<int>>& intervals) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, int>m;
    int n=intervals.size();
    for(int i=0; i<n; i++){
        m[intervals[i][0]]=i;
    }

    vector<int>ans(n, -1);
    for(int i=0; i<n; i++){
        auto it = m.lower_bound(intervals[i][1]);
        if(it != m.end()){
            ans[i]=it->second;
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