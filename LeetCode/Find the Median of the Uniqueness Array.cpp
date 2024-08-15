// https://leetcode.com/problems/find-the-median-of-the-uniqueness-array/
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

int medianOfUniquenessArray(vector<int>& A) {
    int n = A.size();
    long long total = (long long) n * (n + 1) / 2;

    auto atmost = [&](int k) {
        long long res = 0;
        unordered_map<int, int> count;
        for (int i = 0, j = 0; j < n; j++) {
            count[A[j]]++;
            while (count.size() > k) {
                if (--count[A[i]] == 0)
                    count.erase(A[i]);
                i++;
            }
            res += j - i + 1;
        }
        return res;
    };

    int left = 1, right = unordered_set<int>(A.begin(), A.end()).size();
    while (left < right) {
        int k = (left + right) / 2;
        if (atmost(k) * 2 >= total)
            right = k;
        else
            left = k + 1;
    }
    return left;
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