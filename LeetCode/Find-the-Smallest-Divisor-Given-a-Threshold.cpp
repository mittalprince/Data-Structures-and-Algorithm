//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
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

bool isPossible(vector<int>& nums, int threshold, int divisor){
    int res=0;
    for(int i: nums){
        if(i%divisor){
            res += (i+divisor)/divisor;
        }
        else res += i/divisor;
    }
    return res<=threshold;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=nums.size();

    int s = 1;
    int e=*max_element(nums.begin(), nums.end());
    int ans=-1;

    while(s<=e){
        int mid = (s+e)/2;
        if(isPossible(nums, threshold, mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
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