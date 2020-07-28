// https://www.interviewbit.com/problems/square-root-of-integer/
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

int sqrt(int A) {
    int s=1, e=A/2;
    if(A<=1)return A;
    
    while(s<=e){
        int mid = (s+e)/2;
        if(mid == A/mid)return mid;
        else if(mid < A/mid){
            if(mid+1 == A/(mid+1))return mid+1;
            else if(mid+1 > A/(mid+1))return mid;
            else s=mid+1;
        }
        else e=mid-1;
    }
    return s;
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