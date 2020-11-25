//https://leetcode.com/problems/different-ways-to-add-parentheses/
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

// Recurssive Approach
vector<int> solve(string s){
    vector<int>res;
    int n=s.size();

    for(int i=0; i<n; i++){
        if(s[i]=='+' or s[i]=='-' or s[i]=='*'){
            vector<int>left = solve(s.substr(0,i));
            vector<int>right = solve(s.substr(i+1));

            for(int a:left){
                for(int b:right){
                    if(s[i]=='+'){
                        res.push_back(a+b);
                    }
                    else if(s[i]=='*'){
                        res.push_back(a*b);
                    }
                    else{
                        res.push_back(a-b);
                    }
                }
            }
        }
    }

    if(res.empty()){
        res.push_back(stoi(s));
    }
    return res;
}

vector<int> diffWaysToCompute(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>ans = solve(s);
    return ans;
}

// Dynamic Programming Approach
vector<int> solve(string s, unordered_map<string, vector<int> >&dp){
    vector<int>res;
    int n=s.size();

    for(int i=0; i<n; i++){
        if(s[i]=='+' or s[i]=='-' or s[i]=='*'){
            vector<int>left, right;

            string s1 = s.substr(0,i);
            string s2 = s.substr(i+1);

            if(dp.count(s1)==0){
                dp[s1] = solve(s1, dp);
            }
            left = dp[s1];

            if(dp.count(s2)==0){
                dp[s2] = solve(s2, dp);
            }
            right = dp[s2];

            for(int a:left){
                for(int b:right){
                    if(s[i]=='+'){
                        res.push_back(a+b);
                    }
                    else if(s[i]=='*'){
                        res.push_back(a*b);
                    }
                    else{
                        res.push_back(a-b);
                    }
                }
            }
        }
    }

    if(res.empty()){
        res.push_back(stoi(s));
    }
    return dp[s] = res;
}

vector<int> diffWaysToCompute(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, vector<int> >dp;
    return solve(s, dp);

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