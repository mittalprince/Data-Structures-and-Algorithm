// https://leetcode.com/problems/pancake-sorting/
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

vector<int> pancakeSort(vector<int>& A) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> res;
    int x,i;
    for (x = A.size(); x > 0; --x) {
        for (i = 0; A[i] != x; ++i);
        reverse(A.begin(), A.begin() + i + 1);
        res.push_back(i + 1);
        reverse(A.begin(), A.begin() + x);
        res.push_back(x);
    }
    return res;
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