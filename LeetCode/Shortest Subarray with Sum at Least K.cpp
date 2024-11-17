// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
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

int shortestSubarray(vector<int>& nums, int k) {
    // https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/143726/C%2B%2BJavaPython-O(N)-Using-Deque
    int n = nums.size();
    vector<long long>temp(n, 0);
    temp[0] = nums[0];
    int ans = n+1;
    deque<int>d;
    /*
    variation of sliding window -> not exact as nums contains -ve values
    in original one -> start-end -> condition break hoti hai toh start+1-end sabbhi ke liye valid hai
    but in this case it's not aslwayys true as contain -ve so sum up and down ho sakta hai
    */
    for(int i=0; i<n; i++){
        if(i) temp[i] = temp[i-1] + nums[i];
        // storing prefix sum
        if(temp[i]>=k) ans = min(ans, i+1);
        /*
        in deque we store index which have monotonic increasing behavior prefix[d[i]] < prefix[d[i+1]]
        */
        while(!d.empty() && temp[i] - temp[d.front()] >= k){
            ans = min(ans, i-d.front());
            d.pop_front();
        }
        /*
        prefix[x] > prefix[y] && x < y
        prefix[x] - prefix[i] <= k
        then definitely instead of storing x we can remove it and save only y
        as x<y and x-i > x-y but we want min distance
        */
        while(!d.empty() && temp[i] <= temp[d.back()]) d.pop_back();
        d.push_back(i);
    }
    return ans == n+1 ? -1 : ans;
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