// https://www.cnblogs.com/lz87/p/11968618.html
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

class Sea{
    public:    
    bool hasShips(vector<int>&topRight, vector<int>&bottomLeft);
};

int solve(Sea &sea, vector<int> topRight, vector<int> bottomLeft){
    if(topRight[0]<bottomLeft[0] or topRight[1]<bottomLeft[1] or !sea.hasShips(topRight, bottomLeft)){
        return 0;
    }

    if(topRight[0]==bottomLeft[0] and topRight[1]==bottomLeft[1])return 1;

    int midx = bottomLeft[0]+(topRight[0]-bottomLeft[0])/2;
    int midy = bottomLeft[1]+(topRight[1]-bottomLeft[1])/2;

    int cnt=0;
    cnt += solve(sea, {midx, midy}, bottomLeft);
    cnt += solve(sea, topRight, {midx+1,midy+1});
    cnt += solve(sea, {topRight[0], midy}, {midx+1, bottomLeft[1]});
    cnt += solve(sea, {midx, topRight[1]}, {bottomLeft[0], midy+1});

    return cnt;
}

int countShips(Sea &sea, vector<int> topRight, vector<int> bottomLeft){
    int ans = solve(sea, topRight, bottomLeft);
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