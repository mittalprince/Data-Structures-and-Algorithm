// https://leetcode.com/problems/rank-teams-by-votes/
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

string rankTeams(vector<string>& votes) {
    int n = votes[0].size();
    string ans = votes[0];
    vector<vector<int>>rank(26, vector<int>(n, 0));

    for(const string& vote: votes){
        for(int i=0; i<n; i++){
            rank[vote[i]-'A'][i]++;
        }
    }
    function<bool(const char&, const char&)> compare = [&](const char& x, const char& y) {
        for(int i=0; i<n; i++){
            if(rank[x-'A'][i] == rank[y-'A'][i]) continue;
            return rank[x-'A'][i] > rank[y-'A'][i];
        }  
        return x < y;
    };
    sort(ans.begin(), ans.end(), compare);
    /*
    vectors are comparable, runs faster if your compiler can optimize the comparisons
    sort(ans.begin(), ans.end(), [&](const char& x, const char& y) { return ranks[x - 'A'] > ranks[y - 'A'] || ranks[x - 'A'] == ranks[y - 'A'] && x < y; });
    */

    return ans;
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