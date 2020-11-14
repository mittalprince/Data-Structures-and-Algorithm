//https://leetcode.com/problems/generate-parentheses/
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

void solve(string& s, vector<string>&ans, int open, int close, int n, int i){
    if(i==2*n){
        ans.push_back(s);
        return;
    }
    if(open>close){
        s += ")";
        solve(s, ans, open, close+1, n, i+1);
        s.pop_back();
    }
    if(open<n){
        s += "(";
        solve(s, ans, open+1, close, n, i+1);
        s.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>ans;
    string s="";
    solve(s, ans, 0, 0, n, 0);
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