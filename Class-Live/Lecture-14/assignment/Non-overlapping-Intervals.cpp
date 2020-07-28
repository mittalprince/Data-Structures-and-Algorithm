#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
We know that we should remove the longest one
Why ? Because we want to be safe i.e. to reduce the risk of further overlap
we should remove the one which ends at the last, thats it!

So we sort and for each interval we check whether it is overlapping with the previous interval or not, if it is overlapping,we increase count, then we remove the interval which ends later ( update end to the shorter interval'end and forget about the longer interval ).
If it is not overlapping then we just move on.
*/
int eraseOverlapIntervals(vector<vector<int>>& I) {
    int n=I.size();
    if(n<=1) return 0;

    sort(I.begin(), I.end());

    int ans=0;
    int prev_end = I[0][1];

    for(int i=1; i<n; i++){
        if(I[i][0] < prev_end){
            ans++;
            prev_end = min(prev_end, I[i][1]);
        }
        else{
            prev_end = I[i][1];
        }
    }
    return ans;
}

int eraseOverlapIntervals(vector<vector<int>>& I) {
    int n=I.size();
    if(n<=1) return 0;

    sort(I.begin(), I.end(), [](const vector<int>&a, const vector<int>&b){
        return a[1]<b[1];
    });

    int end = I[0][1];
    int ct=1;
    for(int i=1; i<n; i++){
        if(I[i][0] >= end){
            ct++;
            end = I[i][1];
        }
    }

    return n-ct;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    return 0;
}