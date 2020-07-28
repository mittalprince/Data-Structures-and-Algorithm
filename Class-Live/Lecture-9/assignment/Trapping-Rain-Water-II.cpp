#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define ppi pair<int, pair<int, int>>
int x[]={0, -1, 0, 1};
int y[]={-1, 0, 1, 0};

class Solution {
public:
    class comp{
        public:
        bool operator()(ppi &a, ppi &b){
            return a.first>b.first;
        }
    };
    
    int trapRainWater(vector<vector<int>>& h) {
        priority_queue<ppi, vector<ppi>, greater<ppi>>pq;
        
        int n=h.size();
        if(n==0) return 0;
        int m=h[0].size();
        
        vector<vector<bool>>visited(n, vector<bool>(m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    pq.push({h[i][j], {i,j}});
                    visited[i][j]=1;
                }
            }
        }
        
        int ans=0, max_height=0;
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            max_height = max(top.first, max_height);
            
            for(int i=0; i<4; i++){
                int new_r = top.second.first+x[i];
                int new_c = top.second.second+y[i];
                
                if(new_r>=0&&new_c>=0&&new_r<n&&new_c<m&&!visited[new_r][new_c]){
                    if(h[new_r][new_c] < max_height){
                        ans += max_height-h[new_r][new_c];
                    }
                    visited[new_r][new_c]=true;
                    pq.push({h[new_r][new_c], {new_r, new_c}});
                }
            }
        }
        
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}