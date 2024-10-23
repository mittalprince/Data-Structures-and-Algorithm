//https://leetcode.com/problems/rank-transform-of-an-array/
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

vector<int> arrayRankTransform(vector<int>& arr) {
    std::unordered_map<int, int> valueToRank;  // Map to store value-to-rank mapping
    std::vector<int> sortedUniqueNumbers = arr;

    // Remove duplicates and sort
    std::sort(sortedUniqueNumbers.begin(), sortedUniqueNumbers.end());
    sortedUniqueNumbers.erase(std::unique(sortedUniqueNumbers.begin(), sortedUniqueNumbers.end()), sortedUniqueNumbers.end());

    // Assign ranks to sorted unique elements
    for (int i = 0; i < sortedUniqueNumbers.size(); i++) {
        valueToRank[sortedUniqueNumbers[i]] = i + 1;
    }

    // Replace each element in the original array with its rank
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = valueToRank[arr[i]];
    }

    return arr;
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