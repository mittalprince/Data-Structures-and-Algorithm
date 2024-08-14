// https://leetcode.com/problems/snakes-and-ladders/
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

int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size(), lbl = 1;
    vector<pair<int, int>> cells(n*n+1);
    vector<int> columns(n);
    iota(columns.begin(), columns.end(), 0);
    for (int row = n - 1; row >= 0; row--) {
        for (int column : columns) {
            cells[lbl++] = {row, column};
        }
        reverse(columns.begin(), columns.end());
    }
    vector<int> dist(n*n+1, -1);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next = curr + 1; next <= min(curr+6, n*n); next++) {
            auto [row, column] = cells[next];
            int destination = board[row][column] != -1 ? board[row][column] : next;
            if (dist[destination] == -1) {
                dist[destination] = dist[curr] + 1;
                q.push(destination);
            }
        }
    }
    return dist[n*n];
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