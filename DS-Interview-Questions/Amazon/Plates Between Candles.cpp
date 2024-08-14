// https://leetcode.com/problems/plates-between-candles/
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

vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
//          A[i] - A[j] + 1 is the length between two candies,
//          i - j + 1is the number of candies.
//          (A[j] - A[i]) - (j - i) is the number of plates between two candies.
    vector<int> A, res;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == '|')
            A.push_back(i);
    for (int q = 0; q < queries.size(); ++q) {
        int i = lower_bound(A.begin(), A.end(), queries[q][0]) - A.begin();
        int j = upper_bound(A.begin(), A.end(), queries[q][1]) - A.begin() - 1;
        res.push_back(i < j ? (A[j] - A[i]) - (j - i) : 0);
    }
    return res;
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