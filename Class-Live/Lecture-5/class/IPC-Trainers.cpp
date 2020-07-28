#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005

void solve(){
    ll total_trainers, total_days;
    cin>>total_trainers>>total_days;
    ll arrival_day[MAX]={0}, lecture_wants[MAX]={0}, saddness[MAX]={0}, lecture_taken[MAX]={0};

    priority_queue<pair<ll, ll> >pq;

    for(ll i=0; i<total_trainers; i++){
        cin>>arrival_day[i]>>lecture_wants[i]>>saddness[i];
        pq.push({saddness[i], i});
    }

    set<ll>available_days;
    for(ll i=1; i<=total_days; i++){
        available_days.insert(i);
    }

    while(!pq.empty()){
        pair<ll, ll> top = pq.top();
        pq.pop();
        ll idx = top.second;

        ll lecture_start_day = arrival_day[idx];
        ll lecture_end_day = arrival_day[idx]+lecture_wants[idx]-1;

        for(ll i=lecture_start_day; i<=lecture_end_day; i++){
            auto it = available_days.lower_bound(i);
            if(it == available_days.end()){
                /*
                In case k is not present in the set container, t
                he function returns an iterator pointing to the immediate next element which is just greater than k. 
                If the key passed in the parameter exceeds the maximum value in the container, 
                then the iterator returned is equivalent to s.end() 
                */
               // i.e no availbe days that is greater or equal to this this day so just break
                break;
            }
            else{
                lecture_taken[idx]++;
                available_days.erase(it);
            }
        }
    }

    ll total_saddnees=0;
    for(ll i=0; i<total_trainers; i++){
        total_saddnees += (lecture_wants[i]-lecture_taken[i])*saddness[i];
    }
    cout<<total_saddnees<<endl;
}

int main(){
    fstIO;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}