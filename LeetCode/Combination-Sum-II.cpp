// https://leetcode.com/problems/combination-sum-ii/
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

vector<vector<int> >ans;
vector<int>t;
int n;

void solve(vector<int>&arr, int target, int i){
    if(target==0){
        ans.push_back(t);
        return;
    }
    if(i>=n or target<0 or arr[i]>target)return ;

    for(int j=i; j<n and target>=arr[j]; j++){
        if(j==i or arr[j] != arr[j-1]){
            t.push_back(arr[j]);
            solve(arr, target-arr[j], j+1);
            t.pop_back();       
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(candidates.empty())return {};

    n=candidates.size();

    sort(candidates.begin(), candidates.end());
    solve(candidates, target, 0);

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