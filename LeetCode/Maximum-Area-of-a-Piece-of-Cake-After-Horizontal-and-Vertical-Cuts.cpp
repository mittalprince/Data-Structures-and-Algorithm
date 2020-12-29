//https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
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

int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());

    long max_h=0, max_w=0;
    long prev=0;
    for(int i: horizontalCuts){
        max_h = max(max_h, i-prev);
        prev=i;
    }
    max_h = max(max_h, h-prev);

    prev=0;
    for(int i: verticalCuts){
        max_w = max(max_w, i-prev);
        prev=i;
    }
    max_w = max(max_w, w-prev);

    return (max_h*max_w)%(1000000007);
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