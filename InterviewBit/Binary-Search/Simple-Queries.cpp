// https://www.interviewbit.com/problems/simple-queries/
#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
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
#define MAX 100005
 
ll divisorProduct[MAX];
 
ll fstPow(ll a, ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
 
        b >>= 1;
    }
    return ans;
}

void sieve(){
    divisorProduct[0]=0;
    divisorProduct[1]=1;

    if(divisorProduct[2]!=0) return; //already calculated divisorProduct arr
    for(ll i=2; i<MAX; i++){
        if(divisorProduct[i]==0){
            divisorProduct[i]=2;
            for(int j=i+i; j<MAX; j+=i){
                if(divisorProduct[j]==0)divisorProduct[j]=1;
                ll val = j;
                ll ct=0;
                while(val%i==0){
                    ct++;
                    val /= i;
                }
                divisorProduct[j] *= (ct+1); // +1 as 1 is always inlcludes in this (15 -> (3)(5) -> [1,3]*[1,5]-> (1,3,5,15));
            }
        }
    }
    // product of factors will be n^(number of factor/2).
    // But when number of factor is odd, product will be n^(number of factor/2) * sqrt(n).
    for(int i=2; i<MAX; i++){
        divisorProduct[i] = (fstPow(i, divisorProduct[i]/2)%MOD * (divisorProduct[i]&1? (ll)sqrt(i): 1)%MOD)%MOD;
    }
}
 
int binarySearch(pair<ll, ll> ans[], ll val, int n){
    int s=0, e=n-1;
    int idx=-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(ans[mid].second>=val){
            idx=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    return idx;
}
 
bool compare(pair<ll, ll> a, pair<ll, ll> g) {
    return a.first > g.first;
}
 
vector<int> solve(vector<int> &A, vector<int> &B){
    sieve();
 
    int n=A.size();
    vector<int>left(n, -1), right(n, n);
 
    stack<int>s;
    for(int i=0; i<n; i++){
        while(!s.empty() and A[s.top()]<=A[i]){
            s.pop();
        }
        if(!s.empty())left[i] = s.top();
        s.push(i);
    }
    s = stack<int>();
    for(int i=n-1; i>=0; i--){
        while(!s.empty() and A[s.top()]<A[i]){
            s.pop();
        }
        if(!s.empty())right[i] = s.top();
        s.push(i);
    }
    
    pair<ll, ll> ans[n];
    for(int i = 0; i < n; i += 1) {
        ans[i].first = divisorProduct[A[i]];
        ans[i].second = (i-left[i])*(right[i]-i);
    }
    sort(ans, ans + n, [&](const pair<ll, ll>&a, const pair<ll, ll>&b)->bool{
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first>b.first;
    });
 
    
    for(int i=1; i<n; i++){
        ans[i].second += ans[i-1].second;
    }
    
    
    vector<int> res;
    for(int i = 0; i < B.size(); i += 1) {
        auto id = binarySearch(ans, B[i], n);
        res.push_back(ans[id].first);
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