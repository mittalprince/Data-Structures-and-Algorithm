// https://leetcode.com/problems/reconstruct-itinerary/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
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

map<string, priority_queue<string, vector<string>, greater<string> > >m;
vector<string>ans;

void DFS(string src){
    while(!m[src].empty()){
        string t = m[src].top();
        m[src].pop();
        DFS(t);
    }
    ans.push_back(src);
}

vector<string> findItinerary(vector<vector<string>>& tickets) {

    for(auto it: tickets){
        m[it[0]].push(it[1]);
    }

    DFS("JFK");
    reverse(ans.begin(), ans.end());
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