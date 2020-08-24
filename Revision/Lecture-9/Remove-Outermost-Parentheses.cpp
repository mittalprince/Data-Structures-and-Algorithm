// https://leetcode.com/problems/remove-outermost-parentheses/
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

string removeOuterParentheses(string S) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int open=0, start=0;
    string ans="";

    for(int i=0; i<S.length(); i++){
        (S[i]=='(')?open++:open--;
        if(open==0){
            ans.append(S, start+1, i-start-1);
            start=i+1;
        }
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