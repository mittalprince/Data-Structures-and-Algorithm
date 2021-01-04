//https://leetcode.com/problems/ugly-number-ii/
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

int nthUglyNumber(int n) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>ans(n, 0);
    ans[0]=1;

    int p2=0, p3=0, p5=0;
    for(int i=1; i<n; i++){
        int t = min(ans[p2]*2, min(ans[p3]*3, ans[p5]*5));
        ans[i]=t;
        if(t == ans[p2]*2){
            p2++;
        }
        if(t == ans[p3]*3){
            p3++;
        }
        if(t == ans[p5]*5){
            p5++;
        }
    }

    return ans[n-1];
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