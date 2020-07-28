#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

int longestConsecutive(vector<int>& nums) {
        
    unordered_set<int>s;
    for(int i=0; i<nums.size(); i++){
        s.insert(nums[i]);
    }
    
    int ans=0;
    for(int i=0; i<nums.size(); i++){
        if(s.find(nums[i]-1) == s.end()){
            int j=nums[i];
            while(s.find(j) != s.end()){
                j++;
            }
            ans = max(ans, j-nums[i]);
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