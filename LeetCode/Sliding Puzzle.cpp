// https://leetcode.com/problems/sliding-puzzle/
#include<iostream>
#include<vector>
#include<queue>
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

int slidingPuzzle(vector<vector<int>>& board) {
    int ans = 0;
    string end = "123450";
    vector<vector<int>>moves = {{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}};
    queue<string>q;
    unordered_set<string>visited;
    string start = "";
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            start += to_string(board[i][j]);
        }
    }
    q.push(start);
    visited.insert(start);
    while(!q.empty()){
        int sz = q.size();
        for(int i=0; i<sz; i++){
            string top = q.front();
            q.pop();
            if(top == end)return ans;

            int idx = top.find("0");
            for(int& j: moves[idx]){
                string temp = top;
                swap(temp[idx], temp[j]);
                if(visited.find(temp) == visited.end()){
                    q.push(temp);
                    visited.insert(temp);
                }
            }
        }
        ans++;
    }
    return -1;
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