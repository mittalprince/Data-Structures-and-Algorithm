// https://leetcode.com/problems/count-unhappy-friends/
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

int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& pairs) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>v(n);
    for(vector<int>it: pairs){
        v[it[0]]=it[1];
        v[it[1]]=it[0];
    }

    int ans=0;
    for(int i=0; i<n; i++){
        int x=0;
        for(int j=0; j<pref[i].size(); j++){
            if(pref[i][j] == v[i]){
                break;
            }
            for(int k=0; k<pref[pref[i][j]].size(); k++){
                if(pref[pref[i][j]][k] == i){
                    x++;break;
                }
                if(pref[pref[i][j]][k] == v[pref[i][j]]){
                    break;
                }
            }
            if(x)break;
        }
        ans += x;
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