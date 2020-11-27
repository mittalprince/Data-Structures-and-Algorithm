//https://leetcode.com/problems/concatenated-words/
#include<iostream>
#include<vector>
#include<unordered_set>
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

bool solve(string &s, unordered_set<string>&dict){
    if(dict.empty())return false;
    int n=s.length();

    vector<bool>dp(n+1, false);
    dp[0]=1;

    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            if(!dp[j])continue;
            if(dict.count(s.substr(j, i-j))){
                dp[i]=true;
                break;
            }
        }
    }
    return dp[n];
}

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>ans;
    sort(words.begin(), words.end(), [&](const string &a, const string &b)->bool{
        return a.length()<b.length();    
    });

    unordered_set<string>dict;

    for(string i: words){
        if(solve(i, dict)){
            ans.push_back(i);
        }
        dict.insert(i);
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