// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include<iostream>
#include<vector>
#include<unordered_map>
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

unordered_map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
vector<string>ans;

void solve(string s, int i, string t){
    if(i==s.length()){
        if(t.length()) ans.push_back(t);
        return;
    }
    if(s[i] == '1'){
        ans.clear();
        t = "";
        return;
    }
    for(int j=0; j<m[s[i]].length(); j++){
        t.push_back(m[s[i]][j]);
        solve(s, i+1, t);
        t.pop_back();
    }
}

vector<string> letterCombinations(string digits){
    solve(digits, 0, "");
    return ans;
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