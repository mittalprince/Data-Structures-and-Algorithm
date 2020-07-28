// https://leetcode.com/problems/course-schedule-iii/
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

// optimized
int scheduleCourse(vector<vector<int>>& courses) {

    vector<pair<int, int> >arr;

    for(auto it: courses){
        arr.push_back({it[1], it[0]});
    }

    sort(arr.begin(), arr.end());
    priority_queue<int>q;

    int time=0;

    for(auto it: arr){
        if(time+it.second <=it.first){
            time += it.second;
            q.push(it.second);
        }
        else{
            if(!q.empty() && q.top()>it.second){
                time -= (q.top()-it.second);
                q.pop();
                q.push(it.second);
            }   
        }
    }

    return q.size();
}

int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), [&](vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    });  

    priority_queue<int>q;
    int sum=0;

    for(auto it: courses){
        int dur = it[0];
        int end = it[1];

        sum += dur;
        q.push(dur);

        if(sum > end){
            sum -= q.top();
            q.pop();
        }
    }
    return q.size();
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