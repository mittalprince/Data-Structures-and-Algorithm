//https://leetcode.com/problems/diagonal-traverse-ii/
#include<iostream>
#include<vector>
#include<unordered_map>
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

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int max_key=0;
    unordered_map<int, vector<int> >m;
    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<nums[i].size(); j++){
            m[i+j].push_back(nums[i][j]);
            max_key = max(max_key, i+j);
        }
    }

    vector<int>ans;
    for(int i=0; i<=max_key; i++){
        for(int j=m[i].size()-1; j>=0; j--){
            ans.push_back(m[i][j]);
        }
    }
    return ans;
}

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<pair<int, int> >q;
    vector<int>ans;
    q.push({0,0});

    while(!q.empty()){
        auto [r,c]=q.front();
        q.pop();
        ans.push_back(nums[r][c]);

        if(c==0 and r+1<nums.size()){
            q.push({r+1,c});
        }
        if(c+1<nums[r].size()){
            q.push({r, c+1});
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