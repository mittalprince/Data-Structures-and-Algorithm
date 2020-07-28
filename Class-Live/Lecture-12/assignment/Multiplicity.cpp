#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define MAX 100005

int n;
int arr[MAX];
ll dp[MAX]={0};

ll solve(int i, int sub_len){
    if(i==(n+1)) return (sub_len>0);

    int opt1 = solve(i+1, sub_len);
    int opt2 = 0;
    if(arr[i]%(sub_len+1) == 0){
        opt2 = solve(i+1, sub_len+1);
    }

    return opt1+opt2;
}

void recurrsive(){
    // gives tle
    ip(arr, n);
    cout<<solve(1, 0)<<endl;
}

vector<int> getDivisors(int n){
    vector<int>t;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            t.push_back(i);
            if(i != n/i) t.push_back(n/i);
        }
    }
    sort(t.begin(), t.end(), [](const int a, const int b)->bool{
        return a>b;
    });
    return t;
}

void bottomup(){
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }   
    // dp[i] -> total no of good seq upto index i
    dp[0] =1;
    ll ans=0;

    for(int i=0; i<n; i++){
        vector<int> div = getDivisors(arr[i]);
        // here we find all factors of arr[i], because this help in find which index will completely divides arr[i]
        // we can't check all index from 1 to n for each element ads it gives tle, so find factors

        for(int idx: div){
            // now iterate over factors and check if this factor (idx) less than n
            // if yes means it can divides arr[i] and it will make a good seq

            if(idx>n) continue; // if greater nothing to do

            // if less, we check what is total seq upto idx-1, because if we place arr[i] say at index 5
            // then we must have 4 elments that are already at 1-4, so to check whether element are there or not
            // we use dp[i-1] as if they are present then they will make a goog seq, we just add dp[i] += dp[i-1]
            // i.e how to many goog seq upto idx-1, add their result to dp[i] as now dp[i] will also contribute in good seq
            dp[idx] += dp[idx-1];
            dp[idx] %= mod;
        }
    }

    // now for each index we add their good seq into ans 
    for(int i=1; i<=n; i++){
        ans = (ans + dp[i])%mod;
    }
    cout<<ans<<endl;
}
int main(){
    cin>>n;
    // recurrsive();
    bottomup();
    return 0;
}