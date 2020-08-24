// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
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

string removeDuplicates(string S, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<pair<char, int> >s;
    pair<char, int> curr;

    int i=0, n=S.length();

    while(i<n){
        curr = {S[i], 0};
        while(i<n and S[i] == curr.first){
            curr.second++;
            i++;
        }
        while(!s.empty() and s.top().first == curr.first){
            curr.second += s.top().second;
            s.pop();
        }
        curr.second %= k;
        if(curr.second) s.push(curr);
    }

    vector<string>t;

    while(!s.empty()){
        pair<char, int> p=s.top();
        s.pop();

        string a(p.second, p.first);
        t.push_back(a);
    }

    string ans="";
    for(int i=t.size()-1; i>=0; i--){
        ans += t[i];
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