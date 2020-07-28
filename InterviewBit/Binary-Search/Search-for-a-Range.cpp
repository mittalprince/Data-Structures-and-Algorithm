// https://www.interviewbit.com/problems/search-for-a-range/
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

vector<int> searchRange(const vector<int> &A, int B) {
    int s=0, e=A.size()-1;
    
    int l=-1,r=-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(A[mid]>=B){
            l=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    
    if(l==-1)return {-1,-1};
    
    s=0, e=A.size()-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(A[mid]<=B){
            r=mid;
            s=mid+1;
        }
        else e=mid-1;
    }
    if(r==-1 or A[r] != B)return {-1,-1};
    return {l,r};
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