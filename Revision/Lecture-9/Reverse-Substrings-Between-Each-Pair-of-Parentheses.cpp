// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/submissions/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
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

string reverseParentheses(string S) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=S.length();

    stack<string>s;

    for(int i=0; i<n;){
        if(S[i]=='('){
            s.push("(");
            i++;
        }
        else if(S[i]==')'){
            string x="";
            while(!s.empty() and s.top()!="("){
                x = s.top()+x;
                s.pop();
            }
            if(!s.empty() and s.top()=="(")s.pop();
            if(!x.empty()){
                reverse(x.begin(), x.end());
                s.push(x);
            }
            i++;
        }
        else{
            string x="";
            while(i<n and S[i]!='(' and S[i]!=')'){
                x += S[i++];
            }
            s.push(x);
        }
    }

    string ans="";

    while(!s.empty()){
        ans = s.top()+ans;
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