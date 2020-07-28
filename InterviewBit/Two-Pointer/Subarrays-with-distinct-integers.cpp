// https://www.interviewbit.com/problems/subarrays-with-distinct-integers/
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

int atmostK(vector<int>& arr, int K) {
    int i = 0, j = 0, substrings = 0;
    unordered_map<int, int> freq;
    const int N = arr.size();
    
    while(i < N) {
        // Expand the window
        if(K >= 0) {
            ++freq[arr[i]];
            if(freq[arr[i]] == 1)
                --K;
            ++i;
        }
        // make the window valid
        while(K < 0) {
            --freq[arr[j]];
            if(freq[arr[j]] == 0)
                ++K;
            ++j;
        }
        // Each valid window adds the subarrays which satisfies the condition
        // For : 1,2,1, k=2
        // 1: [1] 
        // 2: [2], [1,2]
        // 3: [1,2], [2,1], [1,2,1]
        substrings += i - j + 1;
    }
    return substrings;
}

int solve(vector<int> &A, int k) {
    return atmostK(A, k)-atmostK(A, k-1);
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