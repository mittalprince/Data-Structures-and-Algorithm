#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
// find the minimum number of conference rooms required.

// Example 1:

// Input: [[0, 30],[5, 10],[15, 20]]
// Output: 2
// Example 2:

// Input: [[7,10],[2,4]]
// Output: 1
// NOTE: input types have been changed on April 15, 2019. Please reset to default code
// definition to get new method signature.
// problem link : https://leetcode.com/problems/meeting-rooms-ii/

int minMeetingRooms(vector<vector<int>>& arr){
    int n=arr.size();
    priority_queue<int, vector<int>, greater<int> >pq;

    if(n==0) return 0;
    sort(arr.begin(), arr.end(), [=](vector<int>a, vector<int>b)->bool{
        return a[0]<b[0];
    });

    pq.push(arr[0][1]);
    int ans=0;
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
    int n;
    cin>>n;
    vector<vector<int> > arr(n, vector<int>());
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        arr[i].push_back(x);
        arr[i].push_back(y);
    }
    cout<<minMeetingRooms(arr)<<endl;
    return 0;
}