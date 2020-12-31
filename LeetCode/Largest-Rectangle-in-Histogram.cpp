//https://leetcode.com/problems/largest-rectangle-in-histogram/
#include<iostream>
#include<vector>
#include<stack>
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

int largestRectangleArea(vector<int>& heights) {
    stack<int>s;
    int n=heights.size();
    int area=0, i;
    for(i=0; i<n; i++){
        while(!s.empty() and heights[i]<=heights[s.top()]){
            int ht = heights[s.top()];
            s.pop();
            area = max(area, ht*(s.empty()?i:i-s.top()-1));
        }
        s.push(i);
    }
    while(!s.empty()){
        int ht = heights[s.top()];
        s.pop();
        area = max(area, ht*(s.empty()?i:i-s.top()-1));
    }
    return area;
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