//https://leetcode.com/problems/count-items-matching-a-rule/
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

int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans=0;
    int idx = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2;
    for(vector<string> t: items){
        ans += t[idx] == ruleValue;
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