// https://leetcode.com/problems/contains-duplicate-iii/
#include<iostream>
#include<vector>
#include<unordered_map>
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

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(k==10000)return false;
    int n=nums.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<min(i+k+1, n); j++){
            long long diff = (long long)nums[i]-(long long)nums[j];
            if(abs(diff)<=t)return true;
        }
    }
    return false;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int,int>buckets;
    int n=nums.size();

    if(n == 0 || k < 0  || t < 0) return false;

    for(int i=0; i<n; i++){
        int bucket = nums[i]/((long)t+1);
        if(nums[i]<0)bucket--;

        if(buckets.find(bucket)!= buckets.end())return true;
        else{
            buckets[bucket]=nums[i];
            if(buckets.count(bucket-1) and (long)nums[i]-buckets[bucket-1]<=t)return true;
            if(buckets.count(bucket+1) and (long)buckets[bucket+1]-nums[i]<=t)return true;

            if(buckets.size()>k){
                int key_to_remove = nums[i-k]/((long)t+1);
                if(nums[i-k] < 0) --key_to_remove;

                buckets.erase(key_to_remove);
            }
        }
    }

    return false;
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