//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
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

int removeDuplicates(vector<int>& A) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=A.size();
    if(n==0){
        return 0;
    }

    int k=1;
    for(int i=1; i<n; i++){
        if(A[i] != A[k-1]){
            A[k++]=A[i];
        }
    }

    return k;
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