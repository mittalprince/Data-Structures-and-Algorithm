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

ll maxTime(ll rank, ll total_parata){
    ll time_req=0;
    for(int i=1; i<=total_parata; i++){
        time_req += (rank*i);
    }
    return time_req;
}

// can we make total total_Parata in max_time if yes means we can also make in higher time also,
// so dec the range as we want min time req to make total_parata parata
bool isPossible(ll ranks[], ll total_ranks, ll total_parata, ll max_time){
    ll total_parata_make=0;

    // now we check in given time max_time how many parata each chef can make, and if the sum of all 
    // these will be >= to total_parata we req then this configuration is possible otheriwse not 
    for(ll i=0; i<total_ranks; i++){
        ll curr_chef_parata_ct=0;
        ll curr_chef_available_time=max_time;
        ll curr_chef_req_time = ranks[i]; // intitally the time req to make 1 parata for each chef will be it rank

        while((curr_chef_available_time-curr_chef_req_time) >= 0){
            curr_chef_parata_ct++;
            curr_chef_available_time -= curr_chef_req_time;
            curr_chef_req_time += ranks[i];

            if(total_parata_make+curr_chef_parata_ct >= total_parata){
                return true;
            }
        }

        total_parata_make += curr_chef_parata_ct;
        if(total_parata_make>=total_parata){
            return true;
        }
    }
    return false;
}

void solve(){
    ll total_parata, total_ranks;
    cin>>total_parata>>total_ranks;

    ll ranks[total_ranks];
    ip(ranks, total_ranks);

    // we sort the ranks so that the chef which req less time to make parata will consider first 
    // so that we can make more parata in lesser time
    sort(ranks, ranks+total_ranks);

    ll s=0;
    ll e = maxTime(ranks[0], total_parata); // as maxTime will be that all parata will be made by lowest rank cook

    ll ans=0;
    while(s<=e){
        ll mid = s+(e-s)/2;
        if(isPossible(ranks, total_ranks, total_parata, mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
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