// https://leetcode.com/problems/combination-sum-iii/
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

vector<vector<int>>ans;
vector<int>t;

void solve(int n, int k, int i){
    if(k==0 and n==0){
        ans.push_back(t);
        return;
    }
    if(k<0 or n<0)return;

    for(int j=i; j<=9 and n>=j; j++){
        t.push_back(j);
        solve(n-j, k-1, j+1);
        t.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(n==0 or k==0)return {};
    solve(n,k,1);
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