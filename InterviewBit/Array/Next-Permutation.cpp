// https://www.interviewbit.com/problems/next-permutation/
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

vector<int> nextPermutation(vector<int> &A) {
    int n=A.size();
    if(n==0 || n==1){
        return A;
    }
    
    int i,j;
    for(i=n-2; i>=0; i--){
        if(A[i] > A[i+1]){
            continue;
        }
        else{
            break;
        }
    }
    if(i==-1){
        reverse(A.begin(), A.end());
        return A;
    }
    j=i+1;
    while(j<n && A[j]>A[i]){
        j++;
    }
    swap(A[i], A[j-1]);
    reverse(A.begin()+i+1, A.end());
    return A;
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