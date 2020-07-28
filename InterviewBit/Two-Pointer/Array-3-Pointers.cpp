// https://www.interviewbit.com/problems/array-3-pointers/
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

int minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    // int ans=INT_MAX, diff=0;
    // int i=0, j=0, k=0;
    
    // while(i<A.size() and j<B.size() and k<C.size()){
    //     diff = max(abs(A[i] - B[j]), max(abs(B[j] - C[k]), abs(C[k] - A[i])));
    //     ans = min(ans, diff);
    //     if(A[i]>=B[j] and B[j]<=C[k])j++;
    //     else if(A[i]<=B[j] and A[i]<=C[k])i++;
    //     else if(C[k]<=A[i] and C[k]<=B[j])k++;
    // }
    
    // return ans;
    
    int diff = INT_MAX;
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    int i, j, k;
    for(i = 0, j = 0, k = 0; i < A.size() && j < B.size() && k < C.size();) {
        minimum = min(A[i], min(B[j], C[k]));
        maximum = max(A[i], max(B[j], C[k]));
        diff = min(diff, max - min);
        if (diff == 0) break;
        if (A[i] == minimum) i++;
        else if (B[j] == minimum) j++;
        else k++;
    }
    return diff;
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