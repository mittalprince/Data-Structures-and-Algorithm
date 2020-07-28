#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100000

int ans = INT_MAX;
bool visisted[MAX];

void findMinSteps(int arr[], int n, int stair, int step){
    if(stair == n){
        ans = min(ans, step);
        return;
    }

    visisted[stair]=true;
    if(stair+1<=n && !visisted[stair+1]){
        findMinSteps(arr, n, stair+1, step+1);
    }
    if(stair+arr[stair]>=0 && stair+arr[stair]<=n && !visisted[stair+arr[stair]]){
        findMinSteps(arr, n, stair+arr[stair], step+1);
    }
    visisted[stair]=false;
}
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    ans = INT_MAX;
    memset(visisted, false, sizeof(visisted));
    findMinSteps(arr, n, 0, 0);
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}