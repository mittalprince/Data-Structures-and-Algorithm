// https://leetcode.com/problems/combinations/
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

vector<vector<int> >ans;
vector<int>t;

void solve(int i, int k, int n){
    if(0==k){
        ans.push_back(t);
        return;
    }
    if(i>n)return;

    for(int j=i; j<=n-k+1; j++){
        t.push_back(j);
        solve(j+1, k-1, n);
        t.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1,  k, n);
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