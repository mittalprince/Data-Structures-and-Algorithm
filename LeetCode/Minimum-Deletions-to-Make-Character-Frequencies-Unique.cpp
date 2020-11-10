//https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
#include<iostream>
#include<vector>
#include<map>
#include<queue>
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

int minDeletions(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<char, int>m;
    for(char i: s){
        m[i]++;
    }
    priority_queue < int>p;
    map<char,int >::iterator it;
    for(it=m.begin();it!=m.end();it++){
        p.push(it->second);
    }

    int ans=0;
    while(!p.empty()){
        int top = p.top();
        p.pop();

        if(p.empty())return ans;
        if(top == p.top()){
            ans++;
            if(top>1)p.push(top-1);
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