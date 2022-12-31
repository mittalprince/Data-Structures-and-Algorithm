//https://leetcode.com/problems/the-skyline-problem/
#include<iostream>
#include<vector>
#include<set>
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

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    // https://leetcode.com/problems/the-skyline-problem/discuss/2094329/C%2B%2B-Easiest-Explanation-Ever-Guaranteed-Beginner-Friendly-Detailed-O(nlogn)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<pair<int, int>> events;
    events.reserve(buildings.size() * 2);
    
    for (const auto& b : buildings) {
        const auto l = b.front(), r = b[1], h = b.back();
        events.push_back({l, -h});
        events.push_back({r, h});
    }
    sort(events.begin(), events.end());
    
    vector<vector<int>> res;
    multiset<int> heights;
    heights.emplace(0);
    
    int max_height_so_far = 0;
    for (const auto& e : events) {
        int c = e.first, h = e.second;
        if (h < 0) {
            heights.insert(-h);
        } else {
            heights.erase(heights.find(h));
        }
        
        const int curr_height = *(heights.rbegin());
        if (curr_height != max_height_so_far) {
            res.push_back(vector<int>{c, curr_height});
            max_height_so_far = curr_height;
        }
    }
    return res;
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