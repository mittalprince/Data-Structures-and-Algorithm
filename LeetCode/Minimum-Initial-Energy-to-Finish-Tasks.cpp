//https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
#include<iostream>
#include<vector>
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

int minimumEffort(vector<vector<int>>& tasks) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l=0, r=1e9;
    for(vector<int> i:tasks){
        l = max(l, i[0]);
    }
    int n=tasks.size();

    sort(begin(tasks), end(tasks), [&](const vector<int>&a, const vector<int>&b)->bool{
       return (a[1]-a[0])>(b[1]-b[0]); 
    });

    int ans;
    while(l<=r){
        int mid = (l+r)/2;
        bool valid=true;
        int initial=mid;

        for(int i=0; i<n; i++){
            if(initial < tasks[i][1]){
                valid=false;
                break;
            }
            initial -= tasks[i][0];
        }

        if(valid){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
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