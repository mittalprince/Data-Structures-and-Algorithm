// https://leetcode.com/problems/evaluate-division/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
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

unordered_map<string, vector<pair<string, double> > >adj;

double findValue(string src, string dest, unordered_set<string>visited){
    if(src==dest)return 1.0;

    visited.insert(src);
    for(pair<string, double> child: adj[src]){
        if(visited.count(child.first))continue;
        double res = findValue(child.first, dest, visited);
        if(res>0) return child.second*res;
    }

    return -1.0;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n=equations.size();
    for(int i=0; i<n; i++){
        adj[equations[i][0]].push_back({equations[i][1], values[i]});
        adj[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
    }

    vector<double>ans;

    for(vector<string> q: queries){
        string src = q[0];
        string dest = q[1];

        if(adj.count(src)==0 or adj.count(dest)==0){
            ans.push_back(-1.0);
        }
        else{
           unordered_set<string>visited;
            double res = findValue(src, dest, visited);
            ans.push_back(res);
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