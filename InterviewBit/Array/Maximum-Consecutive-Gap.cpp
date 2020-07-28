// https://www.interviewbit.com/problems/maximum-consecutive-gap/
#include<iostream>
#include<vector>
#include<climits>
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

int maximumGap(const vector<int>&A){
    int n=A.size();
    if(n<2)return 0;

    int minE=INT_MAX, maxE=INT_MIN;
    for(int i: A){
        minE = min(minE, i);
        maxE = max(maxE, i);
    }

    int gap = (maxE-minE)/(n-1);
    vector<int>bucketMax(n-1, INT_MIN), bucketMin(n-1, INT_MAX);

    for(int i=0; i<n; i++){
        if(A[i] != minE and A[i] != maxE){
            int idx = (A[i]-minE)/gap;
            bucketMax[idx] = max(bucketMax[idx], A[i]);
            bucketMin[idx] = min(bucketMin[idx], A[i]);
        }
    }

    int ans=INT_MIN;
    int prev = minE;
    for(int i=0; i<n-1; i++){
        if(bucketMax[i] == INT_MIN && bucketMin[i] == INT_MAX){
            continue;
        }

        ans = max(ans, bucketMin[i]-prev);
        prev = bucketMax[i];
    }
    ans = max(ans, maxE-prev);
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