// https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/
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

int distinctPrimeFactors(vector<int>& nums) {
    set<int>s;
    for(int i: nums){
        while(i%2==0){
            s.insert(2);
            i >>=1;
        }
        for(int j=3; j<=sqrt(i); j++){
            while(i%j==0){
                s.insert(j);
                i /= j;
            }
        }
        if(i>2)s.insert(i);
    }
    return s.size();
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}