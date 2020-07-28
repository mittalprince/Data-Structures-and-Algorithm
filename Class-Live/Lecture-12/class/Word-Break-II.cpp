#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

map<string, bool>m;
vector<vector<string>>dp;

//dp[i] -> for given index total possible i can construct

bool solve(string s, int end){
    if(end == 0) return true;

    if(!dp[end].empty()){
        if(dp[end][0] != "-1") return true;
        return false;
    }

    for(int pos=end-1; pos>=0; pos--){
        string x = s.substr(pos, end-pos);
        if(m.count(x) && solve(s, pos)){
            for(string i: dp[pos]){
                if(i=="")dp[end].push_back(x);
                else dp[end].push_back(i+" "+x);
            }
        }
    }

    if(!dp[end].empty()) return true;

    dp[end].push_back("-1");
    return false;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    for(string i: wordDict){
        m[i]=true;
    }

    dp = vector<vector<string>>(s.length()+1, vector<string>());
    dp[0].push_back(""); // for this if(i=="")dp[end].push_back(x);, i.e when s become epty i just push the substr 

    if(solve(s, s.length())) return dp[s.length()];
    return {};
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}