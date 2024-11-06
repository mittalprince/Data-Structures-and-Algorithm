// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<limits.h>
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

int minTimeToReach(std::vector<std::vector<int>>& moveTime) {
    int rows = moveTime.size();
    int cols = moveTime[0].size();
    priority_queue<std::tuple<int, int, int>, vector<std::tuple<int, int, int>>, greater<std::tuple<int, int, int>>> pq;
    vector<vector<int>>time(rows, vector<int>(cols, INT_MAX));

    pq.push({0,0,0});
    time[0][0] = 0;

    int dir[4][4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!pq.empty()){
        auto [currentTime, x, y] = pq.top();
        pq.pop();

        if (x == rows - 1 && y == cols - 1) {
            return currentTime;
        }

        for(int i=0; i<4; i++){
            int newX = x + dir[i][0];
            int newY = y + dir[i][1];

            if(newX >=0 && newX < rows && newY >=0 && newY < cols){
                int waitTime = max(moveTime[newX][newY] - currentTime, 0);
                int newTime = currentTime + waitTime + 1;

                if(newTime < time[newX][newY]){
                    time[newX][newY] = newTime;
                    pq.push({newTime, newX, newY});
                }
            }
        }
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