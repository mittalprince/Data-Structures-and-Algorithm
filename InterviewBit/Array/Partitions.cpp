// https://www.interviewbit.com/problems/partitions/
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

int solve(int A, vector<int> &B) {
    vector<long long>prefix(A, 0);
    
    for(int i=0; i<A; i++){
        prefix[i] = B[i];
        if(i>0) prefix[i] += prefix[i-1];
    }
    
    long long sum = prefix[A-1];
    if(sum%3)return 0; // if whole arr sum is not divisible by 3 then sol doesn't exist
    
    int ans=0, ct=0;
    long long a = sum/3, b=2*a; // a denote the first arr sum, b denote first two arr sum 
    
    // run A-1 times as we consider if we find b then we just update ans because we know the whole arr sum%3==0,
    // so if we found b then there must be another sum/3 val exist after i, so for this we need to iterate till A-1,
    // as there must be aleast a single elemnt in third arr 
    for(int i=0; i<A-1; i++){
        if(prefix[i] == b){
            // if we find sum = b menas here we have a val that must be equal to first two arr sum
            // so we add ct (total first arr we have until whose sum eqaul to a).
            ans += ct;
        }
        if(prefix[i] == a)ct++; // update when we have subarr having sum eqaul to a
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