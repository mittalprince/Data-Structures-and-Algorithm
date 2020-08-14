// https://codeforces.com/contest/81/problem/A
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

void Reverse(string &S, int s, int e){
    while(s<e){
        swap(S[s], S[e]);
        s++;
        e--;
    }
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fstIO;

    string a;
    cin>>a;
    stack<char>s;

    for(char i: a){
        if(s.empty() or s.top() != i)s.push(i);
        else{
            while(!s.empty() and s.top() == i)s.pop();
        }
    }

    string ans="";
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    Reverse(ans, 0, ans.length()-1);
    cout<<ans<<endl;
    return 0;
}