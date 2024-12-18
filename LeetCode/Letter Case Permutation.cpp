// https://leetcode.com/problems/letter-case-permutation/
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

void solve(string s, int i, vector<string>&ans){
    if(i==s.length()){
        ans.push_back(s);
        return;
    }
    solve(s, i+1, ans);
    if(isalpha(s[i])){
        s[i] ^= 32;
        solve(s, i+1, ans);
    }
}
vector<string> letterCasePermutation(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>res;
    solve(s, 0, res);
    return res;
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}