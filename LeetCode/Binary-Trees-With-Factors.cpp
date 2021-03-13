#include<iostream>
#include<vector>
#include<unordered_map>
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

int numFactoredBinaryTrees(vector<int>& A) {
    sort(A.begin(), A.end());
    int len = A.size();
    long ans = 0;
    unordered_map<int, long> fmap;
    for (int num : A) {
        long ways = 1;
        double lim = sqrt(num);
        for (int j = 0, fA = A[0]; fA <= lim; fA = A[++j]) {
            if (num % fA != 0) continue;
            int fB = num / fA;
            if (fmap.find(fB) != fmap.end())
                ways += fmap[fA] * fmap[fB] * (fA == fB ? 1 : 2);
        }
        fmap[num] = ways;
        ans = (ans + ways) % 1000000007;
    }
    return (int)ans;
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