// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
#include<iostream>
#include<vector>
#include<queue>
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

class workers{
    public:
    int wage, quality;
    double wtqratio;

    workers(){}
    workers(int q, int w){
        wage=w;
        quality=q;
        wtqratio = (double)wage/quality;
    }
};

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=quality.size();

    workers arr[n];
    for(int i=0; i<n; i++){
        arr[i] = workers(quality[i], wage[i]);
    }

    sort(arr, arr+n, [=](workers a, workers b){
        return a.wtqratio<b.wtqratio;
    });

    priority_queue<int>pq;
    int sum=0;
    double ans = 10000000001;

    for(int i=0; i<n; i++){
        sum += arr[i].quality;
        pq.push(arr[i].quality);

        if(pq.size()>k){
            sum -= pq.top();
            pq.pop();
            ans = min(ans, sum*arr[i].wtqratio);
        }
        else if(pq.size()==k){
            ans = min(ans, sum*arr[i].wtqratio);
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