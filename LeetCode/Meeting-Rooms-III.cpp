// https://leetcode.com/problems/meeting-rooms-iii/
#include<iostream>
#include<vector>
#include<queue>
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

int mostBooked(int n, vector<vector<int>>& meetings) {
    // https://leetcode.com/problems/meeting-rooms-iii/discuss/2527280/C%2B%2B-with-explanation-Magic-of-Priority-Queues

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* Create a priority queue for engaged rooms. Each node of PQ will store {current_meeting_ending_time, room_number} */
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> engaged;
    /* Create a priority queue for non-engaged rooms. Each node of PQ will store {room_number} */
    priority_queue<int, vector<int>, greater<int>> unused;

    sort(meetings.begin(), meetings.end());
    int arr[105]={0};

    for(int i=0; i<n; i++)unused.push(i);

    for(auto it:  meetings){
        // jo bhi room iss meeting se phela khali ho sake uunko kar do
        while(!engaged.empty() && engaged.top().first <= it[0]){
            int room = engaged.top().second;
            unused.push(room);
            engaged.pop();
        }
        if (!unused.empty()) {
            int room = unused.top();
            engaged.push({ it[1], room });
            unused.pop();
            arr[room]++;
        } else{
            auto top = engaged.top();
            engaged.pop();
            arr[top.second]++;
            //now its confirmed, jab yha aeyga toh usko koi room nahi mila
            // so voh meeting delay hogi -> so start end end time agge shift hoga
            engaged.push({ top.first + (it[1]-it[0]), top.second });
        }
    }
    int ans=0, freq=0;
    for(int i=0; i<n; i++){
        if (freq<arr[i]){
            ans = i;
            freq=arr[i];
        }
    }
    return ans;
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}