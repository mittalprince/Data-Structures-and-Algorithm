#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n,m;
ll arr[200002], time_freq[101]; //ek particular time ke total no of stduents

void solve(){
    ll total_time=0;

    for(ll i=0; i<n; i++){
        //1. jis bhi student par hai tab tak ka total time
        ll exam_start_time = total_time+arr[i]-m;
        // exam_start_time -> denotes the amount, by which time exceed given time m
        // total store cumulative time of all prev stufents and add curr time this gives for curr what actully time needed
        // then we subtract m time, to get the exceded time

        int student_removed=0;
        if(exam_start_time > 0){

            // here we check all times that are prev present and then we subtract this time(j) *freq[of this j] from x
            // repeat until exam_start_time>0

            for(int j=100; j>0; j--){
                ll y = time_freq[j]*j;
                if(exam_start_time<=y){
                    student_removed += ((exam_start_time+j-1)/j);
                    break;
                }
                exam_start_time -= (time_freq[j]*j);
                student_removed += time_freq[j];
            }
        }

        total_time += arr[i];
        time_freq[arr[i]]++;
        cout<<student_removed<<" ";
    }
    cout<<endl;
}
int main(){
    cin>>n>>m;
    ip(arr, n);
    solve();
    return 0;
}