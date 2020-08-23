// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
#include<iostream>
#include<vector>
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

class Solution {
public:
    vector<int> np;
    vector<vector<int>> Rects;
    Solution(vector<vector<int>>& rects) {
        Rects = rects;
        for(vector<int>rect: rects){
            int l1 = rect[2]-rect[0]+1;
            int l2 = rect[3]-rect[1]+1;
            
            int val = np.empty()?l1*l2:np.back()+(l1*l2);
            np.push_back(val);
        }
    }
    
    vector<int> pick() {
        int m = np.back();
        int t = rand()%m;
        int idx = upper_bound(np.begin(), np.end(), t) - np.begin();
        vector<int>R = Rects[idx];
        int x = rand()%(R[2]-R[0]+1) + R[0];
        int y = rand()%(R[3]-R[1]+1) + R[1];
        
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

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