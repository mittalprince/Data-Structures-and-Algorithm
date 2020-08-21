// https://leetcode.com/problems/decoded-string-at-index/
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

string decodeAtIndex(string S, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=S.length();

    stack<pair<string, long long> >s;
    for(int i=0; i<S.length(); i++){
        string x="";

        while(i<n and (S[i]>'9' or S[i]<'0')){
            x += S[i++];
        }
        long long len = (x.length() + (s.empty()?0:s.top().second))*(S[i]-'0');
        s.push({x, len});

        if(len>=k)break;
    }

    string ans="";
    while(!s.empty()){
        pair<string, long long>top = s.top();
        s.pop();
        string x = top.first;
        long long len = top.second;

        k = k%(x.length()+(s.empty()?0:s.top().second));
        if(k==0){
             k = x.length()+(s.empty()?0:s.top().second);
        }

        if(s.empty()){
            ans = x[k-1];
            return ans;
        }
        if(k>s.top().second){
            ans = x[k-s.top().second-1];
            return ans;
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