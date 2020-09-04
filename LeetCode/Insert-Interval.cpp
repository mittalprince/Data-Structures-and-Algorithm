// https://leetcode.com/problems/insert-interval/
#include<iostream>
#include<vector>
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

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(newInterval[0] > newInterval[1]){
        swap(newInterval[0], newInterval[1]);
    }

    vector<vector<int> >ans;

    int n=intervals.size();
    if(!n){
        ans.push_back(newInterval);
        return ans;
    }

    for(int i=0; i<n; i++){
        if(max(newInterval[0], intervals[i][0]) <= min(newInterval[1], intervals[i][1])){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
        else{
            ans.push_back(intervals[i]);
        }
    }

    int j=0;
    while(j<n and intervals[j][0] < newInterval[0])j++;
    ans.insert(ans.begin()+j, newInterval);

    return ans;
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