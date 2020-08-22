// https://leetcode.com/problems/remove-k-digits/
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

string removeKdigits(string num, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string ans="";

    for(char i: num){
        while(!ans.empty() and ans.back()>i and k>0){
            ans.pop_back();
            k--;
        }
        if(ans.size() or i>'0')ans.push_back(i);
    }

    while(!ans.empty() and k>0){
        ans.pop_back();
        k--;
    }

    return ans.empty()?"0":ans;
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