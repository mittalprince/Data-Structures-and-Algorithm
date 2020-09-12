// https://leetcode.com/problems/combination-sum/
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

void solve(vector<int>&a, int target, int i){
    if(target == 0){
        ans.push_back(t);
        return;
    }
    if(i>=a.size() || target<0)return;


    for(int k=i; k<a.size(); k++){
        if(a[k]<=target){
            t.push_back(a[k]);
            solve(a, target-a[k], k);
            t.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& c, int target) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(c.empty())return {};

    sort(c.begin(), c.end());
    solve(c, target, 0);
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