//https://leetcode.com/discuss/interview-question/485097/braze-oa-2020-stock-market-prediction
#include<iostream>
#include<vector>
#include<stack>
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

vector<int> solve(vector<int>arr, vector<int>quries, int n){
    vector<int>prefix(n), suffix(n);

    stack<int>s;
    for(int i=0; i<n; i++){
        while(!s.empty() && arr[i]<=arr[s.top()])s.pop();
        if(s.empty())prefix[i]=-1;
        else prefix[i]=s.top();
        s.push(i);
    }

    while(!s.empty())s.pop();
    for(int i=n-1; i>=0; i--){
        while(!s.empty() && arr[i]<=arr[s.top()])s.pop();
        if(s.empty())suffix[i]=-1;
        else suffix[i]=s.top();
        s.push(i);
    }
    // reverse(suffix.begin(), suffix.end());
    vector<int>ans;
    for(int i: quries){
        i--;
        int l = prefix[i]==-1?1e8:i-prefix[i];
        int r = suffix[i]==-1?1e8:suffix[i]-i;

        int low = min(l, r);
        if(low==1e8)ans.push_back(-1);
        else if(l==low)ans.push_back(prefix[i]+1);
        else if(low==r)ans.push_back(suffix[i]+1);
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
    ip(arr, n);
    int q;
    cin>>q;
    vector<int>queries(q);
    ip(queries, q);

    vector<int>ans = solve(arr, queries, n);
    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}