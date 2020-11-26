//https://leetcode.com/problems/reorder-data-in-log-files/
#include<iostream>
#include<vector>
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

vector<string> reorderLogFiles(vector<string>& logs) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>digLogs, ans;
    vector<pair<string, string> >letLogs;

    for(string &s: logs){
        int i=0;
        while(s[i]!=' ')i++;
        if(isalpha(s[i+1]))letLogs.emplace_back(s.substr(0,i), s.substr(i+1));
        else digLogs.push_back(s);
    }

    sort(letLogs.begin(), letLogs.end(), [&](const pair<string, string>&a, const pair<string, string>&b)->bool{
       if(a.second == b.second){
           return a.first<b.first;
       }
        return a.second<b.second;
    });

    for(pair<string, string>i:letLogs){
        ans.push_back(i.first+" "+i.second);
    }
    for(string i:digLogs){
        ans.push_back(i);
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