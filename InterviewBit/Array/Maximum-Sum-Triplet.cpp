// https://www.interviewbit.com/problems/maximum-sum-triplet/
#include<iostream>
#include<vector>
#include<set>
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

int solve(vector<int> &A) {
    int n=A.size();
    int ans = INT_MIN;
    
    vector<int>right(n, 0);
    right[n-1]=A[n-1];
    for(int i=n-2; i>=0; i--){
        right[i] = max(right[i+1], A[i]);
    }
    
    vector<int>left(n, 0);
    set<int>s;
    s.insert(A[0]);
    
    for(int i=1; i<n; i++){
        s.insert(A[i]);
        
        auto it = s.find(A[i]);
        if(it != s.begin()){
            --it;
            left[i] = *it;
        }
        else left[i] = A[i];
    }
    
    for(int i=1; i<n-1; i++){
        if(left[i] != A[i] and A[i] != right[i]){
            ans = max(ans, left[i]+A[i]+right[i]);
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