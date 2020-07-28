#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// struct compare {
//     bool operator() (pair<int, int>p1, pair<int, int>p2) {
//         return p1.first > p2.first;
//     }
// };
// int nthSuperUglyNumber(int n, vector<int>& primes) {

//     int p = primes.size();
//     priority_queue<pair<int, int>, vector<pair<int, int>>, compare>pq;
//     vector<int>index(p, 1);

//     for (int i = 0; i < p; i++)
//         pq.push(make_pair(primes[i], i));

//     vector<int>ugly(n+1, 0);
//     ugly[1] = 1;
//     int k = 2;

//     while (k <= n) {
//         ugly[k] = pq.top().first;            
//         while (!pq.empty() && ugly[k] == pq.top().first) {
//             pair<int, int>p = pq.top();
//             pq.pop();
//             index[p.second]++;
//             p.first = ugly[index[p.second]]*primes[p.second];
//             pq.push(p);
//         }

//         k++;
//     }

//     return ugly[n];
// }

int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int>ans(n);
    ans[0]=1;

    vector<int>prime(primes.size(), 0);

    for(int i=1; i<n; i++){
        int t=INT_MAX;
        for(int j=0; j<primes.size(); j++){
            t = min(t,ans[prime[j]]*primes[j]);
        }
        ans[i]=t;
        for(int j=0; j<primes.size(); j++){
            if(t == ans[prime[j]]*primes[j]) prime[j]++;
        }
    }
    return ans[n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}