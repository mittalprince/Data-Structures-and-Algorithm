//https://leetcode.com/problems/decode-string/
#include<iostream>
#include<vector>
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

string decodeString(string S) {
    stack<string>s;

    for(int i=0; i<S.length(); i++){
        if(S[i]>= '0' && S[i] <= '9'){
            string n="";
            while(i<S.length() && S[i]>= '0' && S[i] <= '9'){
                n += S[i++];
            }
            s.push(n);
            i--;
        }
        else if(S[i] == ']'){
            string x="";
            while(!s.empty() && s.top() != "["){
                x = s.top()+x;
                s.pop();
            }
            s.pop();
            string t=x;
            for(int j=1; j<stoi(s.top()); j++){
                x += t;
            }
            s.pop();
            s.push(x);
        }
        else if(S[i] == '[') {
            s.push("[");
        }
        else{
            string x="";
            while(i<S.length() && S[i] != '[' && S[i] != ']' && (S[i] < '0' || S[i] > '9')){
                x += S[i++];
            }
            s.push(x);
            i--;
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