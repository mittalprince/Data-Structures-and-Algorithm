#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void Reverse(string &S, int s, int e){
    while(s<e){
        swap(S[s], S[e]);
        s++;
        e--;
    }
}
int main(){
    string s;
    cin>>s;
    stack<char>S;
    for(int i=0; i<s.length(); i++){
        if(S.empty() || S.top() != s[i]){
            S.push(s[i]);
        }
        else{
            while(!S.empty() && S.top() == s[i]){
                S.pop();
            }
        }
    }
    string ans="";
    while(!S.empty()){
        ans += S.top();
        S.pop();
    }
    Reverse(ans, 0, ans.length()-1);
    cout<<ans<<endl;
    return 0;
}