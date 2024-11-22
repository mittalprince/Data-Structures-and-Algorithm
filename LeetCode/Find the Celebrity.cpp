// https://leetcode.ca/all/277.html#google_vignette
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

bool knows(int a, int b){
    return true;
}
int findCelebrity(int n) {
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (knows(ans, i)) {
            ans = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (ans != i) {
            if (knows(ans, i) || !knows(i, ans)) {
                return -1;
            }
        }
    }
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