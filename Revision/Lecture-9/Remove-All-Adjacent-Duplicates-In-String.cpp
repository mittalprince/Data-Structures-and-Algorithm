// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
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

string removeDuplicates(string S) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<char>s;

    for(char i: S){
        bool f=true;
        while(!s.empty() and s.top()==i){
            s.pop();
            f=false;
        }
        if(f)s.push(i);
    }

    string ans;
    ans.resize(s.size());
    int idx=s.size()-1;
    while(!s.empty()){
        ans[idx--] = s.top();
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