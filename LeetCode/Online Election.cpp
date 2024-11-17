// https://leetcode.com/problems/online-election/
#include<iostream>
#include<vector>
#include<unordered_map>
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

class TopVotedCandidate {
public:
    unordered_map<int, int> m;
    vector<int> times;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size(), lead = -1;
        this->times = times;
        unordered_map<int, int>count;
        for (int i = 0; i < n; ++i){
            lead = ++count[persons[i]] >= count[lead] ? persons[i] : lead;
            m[times[i]] = lead;
        }
        
    }
    
    int q(int t) {
        return m[*--upper_bound(times.begin(), times.end(), t)];
    }
};

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