#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(ll i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(ll i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll findMinMP(ll arr[], ll i, ll n, ll A, ll B, ll C, ll sum_a, ll sum_b, ll sum_c){
    if(i==n){
        // why i add this condtion
        // qki existing pe plus one karna hai Nothing(means when sum_a/b/c zero ho) pe nahi kar sakte
        // uss case mein 1 add kar kar ke mein Poora bana daalung bamboo
        if (!sum_a || !sum_b || !sum_c) return INT_MAX;
        return abs(A-sum_a)+abs(B-sum_b)+abs(C-sum_c);
    }
    ll opt1 = findMinMP(arr, i+1, n, A, B, C, sum_a, sum_b, sum_c);
    ll opt2 = findMinMP(arr, i+1, n, A, B, C, sum_a+arr[i], sum_b, sum_c)+(sum_a?10:0);
    ll opt3 = findMinMP(arr, i+1, n, A, B, C, sum_a, sum_b+arr[i], sum_c)+(sum_b?10:0);
    ll opt4 = findMinMP(arr, i+1, n, A, B, C, sum_a, sum_b, sum_c+arr[i])+(sum_c?10:0);

    // cout<<i<<" "<<opt1<<" "<<opt2<<" "<<opt3<<" "<<opt4<<endl;
    return min(opt1, min(opt2, min(opt3, opt4)));
}
void solve(){
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    ll arr[n];
    ip(arr, n);
    ll ans = findMinMP(arr, 0, n, a, b, c, 0, 0, 0);
    cout<<ans<<endl;
}

int main(){
    ll t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}