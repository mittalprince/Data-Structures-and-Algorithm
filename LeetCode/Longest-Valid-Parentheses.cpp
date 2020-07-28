#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int longestValidParentheses(string s) {
    int n=s.length();
    stack<int>S;
    S.push(-1);
    int ans=0;
    
    for(int i=0; i<n; i++){
        if(s[i] == '('){
            S.push(i);
        }
        else{
            S.pop();
            if(S.empty()) S.push(i);
            else{
                ans = max(ans, i-S.top());
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}