// https://leetcode.com/problems/non-overlapping-intervals/
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

int eraseOverlapIntervals(vector<vector<int>>& arr) {
    int n=arr.size();
    if(n==0)return 0;

    sort(arr.begin(), arr.end(), [&](vector<int>&a, vector<int>&b)->bool{
        return a[1]<b[1];
    });

    int end=arr[0][1];
    int ct=1;

    for(int i=1; i<n; i++){
        if(arr[i][0]>=end){
            ct++;
            end = arr[i][1];
        }
    }
    return n-ct;
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