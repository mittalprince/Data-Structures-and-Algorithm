// https://hack.codingblocks.com/app/contests/1496/742/problem
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

vector<string>phone = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
string s;

void solve(int i, string t){
    if(i==s.length()){
        cout<<t<<endl;
        return;
    }
    int idx = s[i]-'0';
    for(int j=0; j<phone[idx].length(); j++){
        t += phone[idx][j];
        solve(i+1, t);
        t.pop_back();
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>s;
    solve(0, "");
    
    return 0;
}