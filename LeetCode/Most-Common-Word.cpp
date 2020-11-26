//https://leetcode.com/problems/most-common-word/
#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
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

string mostCommonWord(string p, vector<string>& banned) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_set<string> ban(banned.begin(), banned.end());
    unordered_map<string, int> count;

    for (auto & c: p) c = isalpha(c) ? tolower(c) : ' ';

    istringstream iss(p);
    string w;
    pair<string, int> res ("", 0);

    while(iss >> w)
        if (ban.find(w) == ban.end() && ++count[w] > res.second)
            res = make_pair(w, count[w]);
    return res.first;
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