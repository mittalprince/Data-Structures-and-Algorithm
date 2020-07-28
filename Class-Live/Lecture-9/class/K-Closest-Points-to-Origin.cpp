#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<vector<int> > kClosest(vector<vector<int>>& points, int K) {
    priority_queue<pair<double,int> > q;
    int count = 0;
    for(int i=0;i<points.size();i++){
        double dist = (points[i][0]*points[i][0] + points[i][1]*points[i][1]);
        if(count == K){
            if(q.top().first>dist){
               q.pop();
                q.push({dist,i});
            }
        }
        else{
            q.push({dist,i});
            count++;
        }
    }

    vector<vector<int> > ans;
    while(!q.empty()){
        ans.push_back(points[q.top().second]);
        q.pop();
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > arr(n, vector<int>());
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        arr[i].push_back(x);
        arr[i].push_back(y);
    }
    
    return 0;
}