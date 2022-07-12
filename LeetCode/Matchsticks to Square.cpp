// https://leetcode.com/problems/matchsticks-to-square/
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<stdio.h>
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

// Approach 1
bool isPossible(vector<int> &arr, int i, int a, int b, int c, int d, int sideLen){
    if (i >= arr.size())
        return a == b && a == c && a == d;
    bool res = false;
    if (a + arr[i] <= sideLen)
        res |= isPossible(arr, i + 1, a + arr[i], b, c, d, sideLen);
    if (a != b && b + arr[i] <= sideLen)
        res |= isPossible(arr, i + 1, a, b + arr[i], c, d, sideLen);
    if (a != c && b != c && c + arr[i] <= sideLen)
        res |= isPossible(arr, i + 1, a, b, c + arr[i], d, sideLen);
    if (a != d && b != d && c != d)
        res |= isPossible(arr, i + 1, a, b, c, d + arr[i], sideLen);
    return res;
}
bool makesquare(vector<int> &matchsticks){
    long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0l);
    if (sum % 4)
        return 0;
    int sideLen = sum / 4;
    sort(matchsticks.rbegin(), matchsticks.rend());
    return isPossible(matchsticks, 0, 0, 0, 0, 0, sideLen);
}

// Approach 2

bool backtrack(int targetSum, vector<int>&m, vector<bool>&usedVales, int index, int remainingBuckets, int currentBucketSum){
    if (remainingBuckets == 0) return true;
    if (currentBucketSum == targetSum) return backtrack(targetSum, m, usedVales, 0, remainingBuckets-1, 0);
    for(int j=index; j<m.size(); j++){
        if (usedVales[j] || (currentBucketSum+m[j] > targetSum) || (j>0 && m[j] == m[j-1] && !usedVales[j-1])) { 
        // compare with j-1 and if same check whether its used or not
        // if not used means we already checked this as its j-1 and its not satisfy condition
            continue;           
        }
        usedVales[j] = true;
        if (backtrack(targetSum, m, usedVales, j+1, remainingBuckets, currentBucketSum+m[j])) return true;
        usedVales[j] = false;
    }
    return false;
}
bool makesquare(vector<int> &m){
    long sum = accumulate(m.begin(), m.end(), 0l);
    if (sum%4)return 0;
    int sideLen = sum/4, n=m.size();
    sort(m.rbegin(), m.rend());
    vector<bool> usedValues(n, false);
    return backtrack(sideLen, m, usedValues, 0, 4, 0);
}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}