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

ll upperBound(ll arr[], ll day, ll total_days){

    if(arr[day] > total_days){
        return total_days+1;
    }
    while(arr[day] != day){
        day = arr[day];
        if(arr[day] > total_days) return total_days+1;
    }
    // cout<<day<<" "<<arr[day]<<endl; 
    return arr[day];
}

void solve(){
    ll total_trainers, total_days;
    cin>>total_trainers>>total_days;
    ll arrival_day[MAX]={0}, lecture_wants[MAX]={0}, saddness[MAX]={0}, lecture_taken[MAX]={0};
    priority_queue<pair<ll, ll> >pq;

    ll total_satisfy=0;
    ll total_saddnees = 0;
    
    for(ll i=0; i<total_trainers; i++){
        cin>>arrival_day[i]>>lecture_wants[i]>>saddness[i];
        pq.push({saddness[i], i});
    }
    ll available_days[total_days+1];
    for(ll i=1; i<=total_days; i++){
        available_days[i] =i;
    }
    while(!pq.empty()){
        pair<ll, ll> top = pq.top();
        pq.pop();
        ll idx = top.second;

        ll lecture_start_day = arrival_day[idx];
        ll lecture_end_day = arrival_day[idx]+lecture_wants[idx]-1;

        for(ll i=lecture_start_day; i<=lecture_end_day; i++){
            ll index = upperBound(available_days, i, total_days);
            // cout<<index<<endl;
            if(index > total_days){
                total_satisfy++;
                total_saddnees += (lecture_wants[idx]*saddness[idx]);
                break;
            }
            else{
                lecture_wants[idx]--;
                if(lecture_wants[idx]==0) total_satisfy++;
                available_days[index]=index+1;
            }
        }
    }

    for(ll i=total_satisfy; i<total_trainers; i++){
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