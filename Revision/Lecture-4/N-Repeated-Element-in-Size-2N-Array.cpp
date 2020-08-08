// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
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

int repeatedNTimes(vector<int>& arr) {
    int n=arr.size();
    // for(int i=0; i<n-2; i++){
    //     if(arr[i]==arr[i+1]||arr[i]==arr[i+2]) return arr[i];
    // }
    // return arr[n-1];

    int cand=arr[0];
    int idx=-1, ct=0;
    for(int i=1; i<n; i++){
        if(arr[i] == cand) return arr[i];
        if(ct==0){
            idx=i;
        }
        ct += (arr[i]==arr[idx])?1:-1;
    }
    return arr[idx];
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