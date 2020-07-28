// https://www.interviewbit.com/problems/maximum-absolute-difference/
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

int maxArr(vector<int> &A) {
    int n=A.size();
    int p_max = INT_MIN, p_min=INT_MAX;
    int n_max = INT_MIN, n_min = INT_MAX;

    for(int i=0; i<n; i++){
        p_max = max(p_max, A[i]+i);
        p_min = min(p_min, A[i]+i);
        n_max = max(n_max, A[i]-i);
        n_min = min(n_min, A[i]-i);
    }

    return max(p_max-p_max, n_max-n_min);
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