// https://leetcode.com/problems/get-the-maximum-score/
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

/* ---- Gives TLE ------------
vector<long long>dpA, dpB;
int n,m;
const int mod = 1000000007;

long long search(vector<int>&arr, int target){
    int n=arr.size();
    int s=0, e=n-1;

    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid]==target)return mid;
        if(arr[mid]<target)s++;
        else e--;
    }

    return -1;
}

long long startFromA(vector<int>&nums1, vector<int>&nums2, int i){
    if(i>=n)return 0;

    if(dpA[i] != -1)return dpA[i];

    long long ans = nums1[i]+startFromA(nums1, nums2, i+1);
    int idx = search(nums2, nums1[i]);
    if(idx>=0){
        ans = max(ans, nums1[i]+startFromB(nums1, nums2, idx+1));
    }

    return dpA[i]=ans;
}

long long startFromB(vector<int>&nums1, vector<int>&nums2, int i){
    if(i>=m)return 0;

    if(dpB[i] != -1)return dpB[i];

    long long ans = nums2[i]+startFromB(nums1, nums2, i+1);
    int idx = search(nums1, nums2[i]);
    if(idx>=0){
        ans = max(ans, nums2[i]+startFromA(nums1, nums2, idx+1));
    }

    return dpB[i]=ans;
}

int maxSum(vector<int>& nums1, vector<int>& nums2) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    n=nums1.size();  
    m=nums2.size();

    dpA = vector<long long>(n, -1);
    dpB = vector<long long>(m, -1);

    long long opt1 = startFromA(nums1, nums2, 0);
    long long opt2 = startFromB(nums1, nums2, 0);

    return (int)(max(opt1, opt2)%mod);
}
*/
const int mod = 1000000007;
int maxSum(vector<int>& nums1, vector<int>& nums2){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=nums1.size();
    int m=nums2.size();
    long long ans=0;
    long long a=0, b=0;
    int i=n-1, j=m-1;

    while(i>=0 and j>=0){
        if(nums1[i] == nums2[j]){
            ans += max(a, b);
            ans += nums1[i];
            a=0, b=0;
            i--;
            j--;
        }
        else if(nums1[i]>nums2[j]){
            a += nums1[i--];
        }
        else b += nums2[j--];
    }

    while(i>=0){
        a += nums1[i--];
    }
    while(j>=0){
        b += nums2[j--];
    }

    ans += max(a, b);
    ans %= mod;

    return (int)ans;
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