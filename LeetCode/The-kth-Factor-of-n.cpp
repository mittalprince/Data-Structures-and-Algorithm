//https://leetcode.com/problems/the-kth-factor-of-n/submissions/
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

int kthFactor(int n, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>factors;

    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            factors.push_back(n/i);
            if(n/i != i){
                factors.push_back(i);
            }
        }
    }

    sort(factors.begin(), factors.end());
    if(k>factors.size())return -1;
    return factors[k-1];
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