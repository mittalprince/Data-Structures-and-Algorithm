//https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
#include<iostream>
#include<vector>
#include<stack>
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

string minRemoveToMakeValid(string S) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int>s;

    for(int i=0; i<S.length(); i++){
        if(S[i]=='(')s.push(i);
        else if(S[i]==')'){
            if(s.empty()){
                S[i]='A';
                continue;
            }
            s.pop();
        }
    }

    while(!s.empty()){
        int idx = s.top(); s.pop();
        S[idx]='A';
    }

    S.erase(remove(S.begin(), S.end(), 'A') ,S.end());
    return S;
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