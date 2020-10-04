// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
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

int nA, nB, used=0, doub=0;

int find(int x, int* p) {
    return x == p[x] ? x : p[x] = find(p[x], p);
}

void uni(int x, int y, int* p, int pos) {
    int px = find(x, p);
    int py = find(y, p);
    if (px != py) {
        used++;
        p[py] = px;
        pos == 1 ? nA-- : nB--;
    }
}

int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    nA = nB = n;

    int pA[n+1], pB[n+1];
    for (int i = 0; i <= n; i++) pA[i] = pB[i] = i;

    for (auto& e: edges) {
        if (e[0] != 3) continue;

        uni(e[1], e[2], pA, 1);
        uni(e[1], e[2], pB, 2);
    }

    used /= 2;
    for (auto& e: edges) {
        if (e[0] != 1) continue;

        uni(e[1], e[2], pA, 1);
    }

    for (auto& e: edges) {
        if (e[0] != 2) continue;

        uni(e[1], e[2], pB, 2);
    }

    if (nA != 1 || nB != 1)
        return -1;

    return edges.size()-used;
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