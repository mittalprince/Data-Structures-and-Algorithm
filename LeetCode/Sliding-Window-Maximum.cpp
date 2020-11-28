//https://leetcode.com/problems/sliding-window-maximum/
#include<iostream>
#include<vector>
#include<queue>
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


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=nums.size();
    deque<int>q;
    vector<int>ans;

    for(int i=0; i<k; i++){
        while(!q.empty() and nums[i]>=nums[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }

    for(int i=k; i<n; i++){
        ans.push_back(nums[q.front()]);

        while(!q.empty() and q.front()<=(i-k))q.pop_front();

        while(!q.empty() and nums[i]>=nums[q.back()])q.pop_back();
        q.push_back(i);
    }
    ans.push_back(nums[q.front()]);
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