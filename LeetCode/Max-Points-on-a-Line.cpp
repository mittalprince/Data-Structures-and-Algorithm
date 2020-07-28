// https://leetcode.com/problems/max-points-on-a-line/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
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

int maxPoints(vector<vector<int>>& points) {
    int ans=0;
    map<pair<int, int>, int> m;
    int n = points.size();

    for(int i=0; i<n; i++){
        m.clear();
        int curr=0, same=1, vertical=0;
        for(int j=i+1; j<n; j++){
            int xdiff=points[i][0]-points[j][0];
            int ydiff=points[i][1]-points[j][1];

            if (xdiff==0 && ydiff==0){ //Same points 
                same++;
            }
            else if(xdiff==0){
                vertical++;
            }
            else{
                int g = __gcd(xdiff, ydiff);
                m[{xdiff/g, ydiff/g}]++; 
                curr = max(curr, m[{xdiff/g, ydiff/g}]);
            }
            curr = max(curr, vertical);
        }
        curr += same;
        ans = max(ans, curr);
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