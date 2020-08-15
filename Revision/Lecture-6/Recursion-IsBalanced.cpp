// https://hack.codingblocks.com/app/contests/1496/729/problem
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

string s;
vector<char>state;

bool solve(int i){
    if(i==s.length()){
        return state.empty();
    }
    if(s[i]=='(' or s[i]=='{' or s[i]=='[')state.push_back(s[i]);
    else if(s[i]==')' or s[i]==']' or s[i]=='}'){
        if(s[i] == ']' && state.back() != '[') return false; 
        if(s[i] == '}' && state.back() != '{') return false; 
        if(s[i] == ')' && state.back() != '(') return false;

        state.pop_back();
    }
    return solve(i+1);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>s;
    if(solve(0)){
        cout<<"true";
    }
    else cout<<"false";
    
    return 0;
}