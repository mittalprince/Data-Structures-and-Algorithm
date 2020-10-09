// https: //leetcode.com/problems/find-servers-that-handled-most-number-of-requests/
#include<iostream>
#include<vector>
#include<set>
#include<queue>
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

vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int>free;
    int n=arrival.size();
    for(int i=0; i<2*k-1; i++){
        free.insert(i);
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
    vector<int>cnt(k, 0);

    for(int i=0; i<n; i++){
        int start = arrival[i];
        int end = load[i]+start;

        while(!pq.empty() and pq.top().first<=start){
            int server = pq.top().second;
            pq.pop();
            free.insert(server);
            free.insert(server+k);
        }

        if(!free.empty()){
            int server = (*free.lower_bound(i%k))%k;
            free.erase(server%k);
            free.erase(server%k+k);

            cnt[server]++;
            pq.push({end, server});
        }
    }


    vector<int>ans;
    int mx=-1;
    for(int i=0; i<k; i++){
        if(cnt[i]>mx){
            mx=cnt[i];
            ans = {i};
        }
        else if(cnt[i]==mx){
            ans.push_back(i);
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