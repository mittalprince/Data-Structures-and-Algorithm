// https://leetcode.com/contest/biweekly-contest-29/problems/longest-subarray-of-1s-after-deleting-one-element/
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

/*
Given a binary array nums, you should delete one element from it.
Return the size of the longest non-empty subarray containing only 1's in the resulting array.
Return 0 if there is no such subarray.
*/

int longestSubarray(vector<int>& nums) {
    vector<pair<int, int> >arr;
    int ct=0, start=0;
    bool flag1=true, flag2=true;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == 0){
            flag1=false;
            if(ct){
                arr.push_back({start, ct});   
            }
            ct=0;
            start=i+1;
        }
        else{
            flag2=false;
            ct++;
        }
    }
    if(ct){
        arr.push_back({start, ct});   
    }

    if(flag1)return nums.size()-1;

    if(flag2)return 0;


    int ans=0;
    for(int i=0; i<arr.size(); i++){
        ans = max(ans, arr[i].second);
    }

    for(int i=0; i<arr.size()-1; i++){
        if((arr[i+1].first-(arr[i].first+arr[i].second)) == 1){
            int a = arr[i].second;
            int b = arr[i+1].second;
            ans = max(ans, a+b);
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