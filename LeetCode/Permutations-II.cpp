//https://leetcode.com/problems/permutations-ii/
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

void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
    if (i == j-1) {
        res.push_back(num);
        return;
    }
    for (int k = i; k < j; k++) {
        if (i != k && num[i] == num[k]) continue;
        swap(num[i], num[k]);
        recursion(num, i+1, j, res);
    }
}
vector<vector<int> > permuteUnique(vector<int> &num) {
    sort(num.begin(), num.end());
    vector<vector<int> >res;
    recursion(num, 0, num.size(), res);
    return res;
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