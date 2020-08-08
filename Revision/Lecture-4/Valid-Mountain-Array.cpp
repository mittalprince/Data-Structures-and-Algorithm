// https://leetcode.com/problems/valid-mountain-array/
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

bool validMountainArray(vector<int>& A) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=A.size();
    if(n<3)return false;
    int i=0;
    while(i<n-1 and A[i]<A[i+1])i++;
    if(i==0 or i==n-1)return false;

    while(i<n-1 and A[i]>A[i+1])i++;

    return i==n-1;
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