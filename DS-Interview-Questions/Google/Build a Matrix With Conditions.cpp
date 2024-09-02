// https://leetcode.com/problems/build-a-matrix-with-conditions/
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

vector<int> generateTopologicalSort(const vector<vector<int>>& a, int k){
    vector<vector<int>>adj(k);
    vector<int>inDeg(k, 0);
    vector<int>order;

    for(auto it: a){
        adj[it[0]-1].push_back(it[1]-1);
        inDeg[it[1]-1]++;
    }
    queue<int>q;
    for(int i=0; i<k ;i++){
        if(inDeg[i]==0)q.push(i);
    }
    while(!q.empty()){
        int top = q.front();
        q.pop();
        order.push_back(top+1);
        for(int child: adj[top]){
            if(--inDeg[child]==0)q.push(child);
        }
    }
    return order;
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    /*
        first we identify the order of numbers for both type (rows/cols)
        for this use topological sort
        number which have inDeg = 0, must come first either above or left
        now we have order of number in both row and col
        will place each number in each row one by one
        now we know ki konsa number kis row mein aeyga (by row order)
        but konsi column mein aeyga uske liye col order ka use karenge
        for that created a map to store ki x number will come in ith column
    */
    vector<int>rowsOrder = generateTopologicalSort(rowConditions, k);
    vector<int>colsOrder = generateTopologicalSort(colConditions, k);

    if(rowsOrder.size() < k || colsOrder.size() < k) return {};
    vector<vector<int>>ans(k, vector<int>(k, 0));
    unordered_map<int, int>m;

    for(int i=0; i<k; i++){
        m[colsOrder[i]] = i;
    }
    for(int i=0; i<k; i++){
        ans[i][m[rowsOrder[i]]] = rowsOrder[i];
    }
    return ans;
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