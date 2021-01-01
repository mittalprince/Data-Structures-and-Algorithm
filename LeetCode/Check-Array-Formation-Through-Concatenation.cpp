//https://leetcode.com/problems/check-array-formation-through-concatenation/
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

bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ps(101, -1);
    for (int i = 0; i < pieces.size(); ++i)
        ps[pieces[i][0]] = i;

    for (int i = 0; i < arr.size(); ) {
        int p = ps[arr[i]], j = 0;
        if (p == -1)
            return false;
        while (j < pieces[p].size())
            if (arr[i++] != pieces[p][j++])
                return false;
    }
    return true;
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