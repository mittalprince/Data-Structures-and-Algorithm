// https://www.lintcode.com/problem/meeting-rooms-ii/description
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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

int minMeetingRooms(vector<vector<int>>& arr){
    int n=arr.size();
    if(n==0) return 0;
    sort(arr.begin(), arr.end(), [=](vector<int>a, vector<int>b)->bool{
        return a[0]<b[0];
    });

    priority_queue<int, vector<int>, greater<int> >pq;
    pq.push(arr[0][1]);
    for(int i=1; i<n; i++){
        if(pq.top()<=arr[i][0]){
            pq.pop();
            pq.push(arr[i][1]);
        }
        else pq.push(arr[i][1]);
    }
    return pq.size();
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