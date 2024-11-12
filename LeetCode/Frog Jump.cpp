// https://leetcode.com/problems/frog-jump/
#include<iostream>
#include<vector>
#include<unordered_set>
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

bool canCross(vector<int>& stones) {
    // The key of the map is stone. The value is, if the frog stand on this stone, how many steps this frog can jump.
    unordered_map<int, unordered_set<int>> hm;

    for(int stone : stones){
        hm[stone] = unordered_set<int>{};
    }

    hm[stones[0]].insert(1);
    int target = stones[stones.size()-1];

    for(int stone: stones){
        for(int step : hm[stone]){
            int reach = stone + step;
            if(stone + step == target){
                return true;
            }
            if(hm.count(reach)){
                hm[reach].insert(step);
                hm[reach].insert(step+1);
                if(step > 0) hm[reach].insert(step-1);
            }
        }
    }

    return false;
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