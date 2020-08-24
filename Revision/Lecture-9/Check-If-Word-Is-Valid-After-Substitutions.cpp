// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
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

bool isValid(string S) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(S.empty() or S.length()%3){
        return false;
    }
    stack<char>s;

    for(char i: S){
        if(i=='c'){
            if(s.size()<2)return false;
            if(s.top() != 'b')return false;
            s.pop();
            if(s.top()!='a')return false;
            s.pop();
        }
        else s.push(i);
    }

    return s.empty();
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