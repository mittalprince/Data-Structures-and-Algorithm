// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
#include<iostream>
#include<vector>
#include<unordered_set>
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

unordered_set<string>t;

void dfs(string s, int pos, int curr, int &ans){
    int n=s.length();
    if(pos == n){
        ans = max(ans, curr);
        return;
    }

    for(int i=pos; i<n; i++){
        if(n-i+curr <= ans)break;
        string x = s.substr(pos, i-pos+1);
        if(t.find(x) == t.end()){
            t.insert(x);
            dfs(s, i+1, curr+1, ans);
            t.erase(x);
        }
    }
}

int maxUniqueSplit(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans=0;
    dfs(s, 0, 0, ans);
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