//https://leetcode.com/discuss/interview-question/363036/walmart-oa-2019-activate-fountains
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

int activateFountains(vector<int> &fountains){
    int n = fountains.size();

    vector<int>interval(n);
    for(int i = 1; i <= n; i++){
        int left = max(i - fountains[i - 1], 1);
        int right = min(i + fountains[i - 1], n);
        interval[left - 1] = max(interval[left - 1], right); //make sure at this point we reach as far as possible on right.
    }

    int right = interval[0];
    int nextGreaterRight = right;

    int fountainsActivate = 1;

    for (int i = 1; i < n; i++){
        nextGreaterRight = max(nextGreaterRight, interval[i]);
        if (i == right){
            fountainsActivate++;
            right = nextGreaterRight;
        }
    }
    return fountainsActivate;
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
    cout<<activateFountains(arr)<<endl;
    return 0;
}