// https://leetcode.com/problems/largest-component-size-by-common-factor/
#include<iostream>
#include<vector>
#include<unordered_map>
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

const static int N = 100001;
int parent[N];
int m[N];
int size[N];

int root(int val){
    while(val != parent[val]) {
        parent[val] = parent[parent[val]];
        val = parent[val];
    }

    return val;
}

int unionize(int x, int y){
    int r1 = root(x);
    int r2 = root(y);

    if(r1 == r2)
        return size[r1];

    parent[r1] = r2;
    size[r2] += size[r1];

    return size[r2];
}

// sieve algo
void findPrime(vector<int> &prime){
    prime.resize(N, 0);
    for (int i = 2; i*i < N; i++)
        if (prime[i] == 0)
            for (int j= i*i; j < N; j += i) 
                prime[j] = i; 

    for(int i = 2 ; i < N; ++i)
        if(prime[i] == 0)
            prime[i] = i;
}

void init(int n){
    for(int i = 0 ; i < n; ++i){
        parent[i] = i;
        size[i] = 1;
        m[i] = -1;
    }
}

int largestComponentSize(vector<int>& A) {
    static vector<int> prime;
    init (*max_element(A.begin(), A.end()));
    int res = 0;

    if(prime.empty())
        findPrime(prime);

    for (auto a : A) {

        int cur = a;

        while(a > 1){
            int p = prime[a];

            if(m[p] == -1)
                m[p] = cur;

            res = max(res , unionize(m[p],cur));

            //remove all prime factors p from a
            while(prime[a] == p)
                a /= p;      
        }        
    }

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