//https://leetcode.com/problems/simplify-path/
#include<iostream>
#include<vector>
#include<stack>
#include<sstream>
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

string simplifyPath(string path) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream ss(path);
    vector<string>words;

    string t="";
    while(getline(ss, t, '/')){
        words.push_back(t);
    }

    stack<string>s;
    for(string i: words){
        if(i=="." or i=="")continue;
        else if(i==".."){
            if(!s.empty())s.pop();
        }
        else s.push(i);
    }

    if(s.empty())return "/";
    string ans="";
    while(!s.empty()){
        ans = "/"+s.top()+ans;
        s.pop();
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