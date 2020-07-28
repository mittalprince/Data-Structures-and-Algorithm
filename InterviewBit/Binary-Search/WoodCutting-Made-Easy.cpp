// https://www.interviewbit.com/problems/woodcutting-made-easy/
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

bool isPossible(vector<int>&height, int m, int min_height){
    long long extra_height=0;
    int n=height.size();
    for(int i=0; i<n; i++){
        if(height[i]>min_height){
            extra_height += height[i]-min_height;
        }

        if(extra_height >= m){
            return true;
        }
    }
    return false;
}

int solve(vector<int> &A, int B) {
    int n=A.size();
    sort(A.begin(), A.end());
    int s = A[0];
    int e = A[n-1];
    
    int ans=0;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(isPossible(A, B, mid)){
            ans=mid;
            s=mid+1;
        }
        else e=mid-1;
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