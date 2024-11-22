#include<iostream>
#include<vector>
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

bool sequenceReconstruction(vector<int>& originalSeq, vector<vector<int>>& sequences) {
    int n = originalSeq.size();
    vector<vector<int>> graph(n, vector<int>());
    vector<int> inDegree(n, 0);

    for (const auto& seq : sequences) {
        for (int i = 1; i < seq.size(); ++i) {
            int from = seq[i - 1] - 1; 
            int to = seq[i] - 1; 
            graph[from].push_back(to);
            ++inDegree[to];
        }
    }
    queue<int> nodesWithNoIncomingEdges;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            nodesWithNoIncomingEdges.push(i);
        }
    }

    while (!nodesWithNoIncomingEdges.empty()) {
        // If there is more than one node with no incoming edges, return false
        // Because we should be able to determine the order unambiguously
        if (nodesWithNoIncomingEdges.size() > 1) return false;

        int currentNode = nodesWithNoIncomingEdges.front();
        nodesWithNoIncomingEdges.pop();

        for (int neighbor : graph[currentNode]) {
            if (--inDegree[neighbor] == 0) {
                nodesWithNoIncomingEdges.push(neighbor);
            }
        }
    }
    
    return true;
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}