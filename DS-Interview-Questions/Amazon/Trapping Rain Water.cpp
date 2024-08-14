// https://leetcode.com/problems/trapping-rain-water/?envType=company&envId=amazon&favoriteSlug=amazon-all
#include<iostream>
#include<vector>
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

 int trap(vector<int>& height) {
    int n = height.size();
    vector<int>left(n,0), right(n, 0);

    left[0]=height[0];
    for(int i=1; i<n; i++){
        left[i] = max(left[i-1], height[i]);
    }
    right[n-1]==height[n-1];
    for(int i=n-2; i>=0; i--){
        right[i] = max(right[i+1], height[i]);
    }
    int ans=0;
    for(int i=0; i<n; i++){
        ans += min(left[i], right[i]) - height[i];
    }
    return ans;
 }

 int trap(vector<int>height){
    int n = height.size();
    if(!n)return 0;
    int ans=0;

    int l=0, r=n-1, left_max=0, right_max=0;
    // two pointer approach
    // will pick index which has small height, ideally iss height tak ka max water trap hoga
    // isliye height[l]<= height[r] condition
    // now check ki i indedx  par kitna water trap hoga either left/right se
    while(l<=r){
        if(height[l] <= height[r]){
            if(height[l]>=left_max) left_max = height[l];
            ans += left_max-height[l];
            l++;
        }
        else {
            if(height[r]>=right_max) right_max = height[r];
            ans += right_max - height[r];
            r--;
        }
    }
    return ans;
 }

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}