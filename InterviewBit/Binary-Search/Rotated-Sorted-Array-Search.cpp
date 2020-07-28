// https://www.interviewbit.com/problems/rotated-sorted-array-search/
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

int search(const vector<int> &A, int B) {
    int s=0, e=A.size()-1;
    
    while(s<=e){
        int mid = (s+e)/2;
        if(A[mid] == B)return mid;
        if(A[s]<A[mid]){
            if(A[s]<=B and B<A[mid])e=mid-1;
            else s=mid+1;
        }
        else{
            if(A[mid]<B and B<=A[e])s=mid+1;
            else e=mid-1;
        }
    }
    
    return -1;
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