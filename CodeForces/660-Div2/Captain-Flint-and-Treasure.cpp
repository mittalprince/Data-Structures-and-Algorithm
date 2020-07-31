// https://codeforces.com/contest/1388/problem/D
#include<iostream>
#include<vector>
#include<algorithm>
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
#define MAX 200005

ll arr[MAX], b[MAX], inDeg[MAX]={0};
vector<ll>adj[MAX];

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
        if(b[i] != -1)b[i]--;
    }

    for(int i=0; i<n; i++){
        if(b[i] != -1){ // make a directed edge from i to b[i]
            adj[i].push_back(b[i]);
            inDeg[b[i]]++;
        }
    }

    // First find the possible seq using Topological Sort
    queue<ll>q;
    vector<ll>topoSort;

    for(ll i=0; i<n; i++){
        if(inDeg[i] == 0)q.push(i);
    }

    while(!q.empty()){
        ll front = q.front();
        q.pop();
        topoSort.push_back(front);

        for(ll child: adj[front]){
            inDeg[child]--;
            if(inDeg[child]==0){
                q.push(child);
            }
        }
    }

    vector<ll>finalSeq, remElmt;
    ll ans=0;

    /*
        Now iterating over topoSort and process only those i whose arr[i]>=0 as this will make tha ans max
        and add +ve value to other arr elemnt hence ans will be max.
        otherwise if we consider -ve val too then a[b[i]] += a[i] will add -ve value and hence ans will be less.

        Doing this process all maintain a finalSeq vector
    */
    for(ll i: topoSort){
        if(arr[i]>=0){
            ans += arr[i];
            if(b[i]!=-1){
                arr[b[i]] += arr[i];
            }
            finalSeq.push_back(i);
        }
        else{
            remElmt.push_back(i);
        }
    } 

    /*
        here we treat the rem elemnt in reverse order.
        Because we know the remElmt vector contain all i that have -ve val, so we process them in reverse order
        such that we have already included the val into ans child before visiting parent. Hence when we process arr[i] then
        arr[b[i]] != arr[i] doest affect out ans value.

        If we process them in same order the parent -ve value also include in child and hence ans will be less, so reverse.

    */

    reverse(remElmt.begin(), remElmt.end());
    for(ll i: remElmt){
        ans += arr[i];
        if(b[i]!=-1){
            arr[b[i]] += arr[i];
        }
        finalSeq.push_back(i);
    } 

    cout<<ans<<endl;
    for(ll i: finalSeq){
        cout<<i+1<<" ";
    }
    cout<<endl;
    return 0;
}