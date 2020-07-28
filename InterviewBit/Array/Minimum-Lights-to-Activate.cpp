// https://www.interviewbit.com/problems/minimum-lights-to-activate/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
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

int solve(vector<int> &A, int B) {
    vector<pair<int, int> >intervals;
    int N=A.size();
    
    for(int i=0; i<N; i++){
        if(A[i]){
            intervals.push_back({max(0, i-B+1), min(N-1, i+B-1)});
        }
    }
    
    sort(intervals.begin(), intervals.end());
    int ans=0;
    int i=0, start=0;
    int n=intervals.size();
    while(i<n){
        if(intervals[i].first>start)return -1;
        int maxEnd=INT_MIN;
        while(i<n and intervals[i].first<=start){
            if(intervals[i].second>=start){
                maxEnd = max(maxEnd, intervals[i].second);
            }
            i++;
        }
        ans++;
        if(maxEnd>=N-1)break;
        start = maxEnd+1;
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