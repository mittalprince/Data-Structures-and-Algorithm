// https://www.interviewbit.com/problems/container-with-most-water/
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

int maxArea(vector<int> &A) {
    int n=A.size();
    int ans=0;
    int l=0, r=n-1;
    
    while(l<r){
        ans = max(ans, min(A[l], A[r])*(r-l));
        if(A[l]<=A[r]){
            int hl=A[l];
            l++;
            while(l<r and A[l]<hl)l++;
        }
        else{
            int hr=A[r];
            r--;
            while(l<r and hr>A[r])r--;
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