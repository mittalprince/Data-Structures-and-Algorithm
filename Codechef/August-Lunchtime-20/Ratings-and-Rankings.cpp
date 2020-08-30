// https://www.codechef.com/problems/ELOMAX
#include<iostream>
#include<vector>
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

void solve(){
    ll n,m;
    cin>>n>>m;

    vector<ll>bestRank(n,inf), bestRate(n,0), bestRateMonth(n), bestRankMonth(n);
    vector<vector<pair<ll, ll> > >rating(m, vector<pair<ll,ll> >(n));

    vector<ll>curr(n);
    ip(curr, n); // take curr rating of each person

    // calculate rating of each persom for every m month and store the bestRate of each person in corresponding arr with month
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ll x;cin>>x;
            curr[i] += x;
            if(curr[i]>bestRate[i]){ // find bestRate of each person
                bestRate[i]=curr[i];
                bestRateMonth[i] = j;
            } 
            rating[j][i].first = curr[i]; // jth month mein ith person ki rating
            rating[j][i].second = i; // jth month mein ith person ka index
        }
    }

    // now for each month find the bestRank among n persons
    for(int i=0; i<m; i++){

        sort(rating[i].rbegin(), rating[i].rend());
        ll base=-1;
        ll currRating=-1;

        for(int j=0; j<n; j++){
            int personIdx = rating[i][j].second;
            if(rating[i][j].first != currRating){
                currRating = rating[i][j].first;
                base = j;
            }
            if(bestRank[personIdx]>base){
                bestRank[personIdx]=base;
                bestRankMonth[personIdx]=i;
            }
        }
    }

    ll ans=0;
    for(int i=0; i<n; i++){
        if(bestRankMonth[i] != bestRateMonth[i])ans++;
    }
    cout<<ans<<endl;

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}