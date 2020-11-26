//https://leetcode.com/problems/expression-add-operators/
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

void dfs(vector<string>&ans, string num, int target, int pos, string curr, long cv, long pv, char op){
    if(pos==num.size()){
        if(cv==target){
            ans.push_back(curr);
        }
        return;
    }

    for(int i=pos+1; i<=num.size(); i++){
        string t = num.substr(pos, i-pos);
        long now = stol(t);

        if (to_string(now).size() != t.size()) continue;
        dfs(ans, num, target, i, curr+"+"+t, cv+now, now, '+');
        dfs(ans, num, target, i, curr+"-"+t, cv-now, now, '-');
        dfs(ans, num, target, i, curr+"*"+t, (op=='-')?cv+pv - pv*now: ((op=='+')?cv-pv + pv*now: pv*now), pv*now, op);
    }
}
vector<string> addOperators(string num, int target) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>ans;
    int n=num.size();

    for(int i=1; i<=n; i++){
        string t = num.substr(0,i);
        long curr = stol(t);

        if (to_string(curr).size() != t.size()) continue;
        dfs(ans, num, target, i, t, curr, curr, '#');
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