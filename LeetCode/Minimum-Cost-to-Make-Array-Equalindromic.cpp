// https://leetcode.com/problems/minimum-cost-to-make-array-equalindromic/
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

// Idea -> find all the closet palindrone from median of array
// There are 5 cases to find nearest plaindrone, use same logic and for each candidate find the min total cost

long long minimumCost(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long ans = LONG_MAX, median = 0, n = nums.size();
    sort(nums.begin(), nums.end());
    median = (n %2 )?nums[n/2]: (nums[n/2] + nums[n/2 - 1])/2;

    string t = to_string(median);
    int tSize = t.size();
    vector<long long>candidates;
    candidates.push_back(pow(10,tSize-1)-1);
    candidates.push_back(pow(10,tSize)+1);

    int mid=(tSize+1)/2;
    long prefix=stol(t.substr(0,mid));
    vector<long>v={prefix,prefix+1,prefix-1};
    for(long i:v)
    {
        string postfix=to_string(i);
        if(tSize%2!=0) postfix.pop_back();//// If the total length is odd number, pop the middle number in postfix
        reverse(postfix.begin(),postfix.end());
        string c=to_string(i)+postfix;
        candidates.push_back(stol(c));
    }
    for(long long i: candidates){
        long long t = 0;
        for(int j: nums){
            t += abs(i-j);
        }
        ans = min(ans, t);
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