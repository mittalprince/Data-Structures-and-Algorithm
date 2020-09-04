// https://leetcode.com/problems/partition-labels/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
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

vector<int> partitionLabels(string S) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<char, pair<int, int> >m;

    for(int i=0; i<S.length(); i++){
        if(m.count(S[i])==0){
            m[S[i]].first = i+1;
        }
        m[S[i]].second = i+1;
    }

    vector<vector<int> >intervals;
    for(auto it: m){
        intervals.push_back({it.second.first, it.second.second});
    }

    sort(intervals.begin(), intervals.end(), [&](const vector<int>&a, const vector<int>&b)->bool{
       return a[0]<b[0]; 
    });

    int idx=0;
    int n=intervals.size();

    for(int i=1; i<n; i++){
        if(intervals[idx][1] >= intervals[i][0]){
            intervals[idx][1] = max(intervals[i][1], intervals[idx][1]);   
        }
        else{
            idx++;
            intervals[idx][0]=intervals[i][0];
            intervals[idx][1]=intervals[i][1];
        }
    }

    intervals.resize(idx+1);
    vector<int>ans;
    int sum=0;
    for(int i=0; i<=idx; i++){
        if(i>0) ans.push_back(intervals[i][1]-intervals[i-1][1]);
        else ans.push_back(intervals[i][1]);
    }

    return ans;
}

vector<int> partitionLabels(string S) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int lastIndex[26]={0};
    int n=S.length();

    for(int i=0; i<n; i++){
        lastIndex[S[i]-'a']=i;    
    }

    int start=0, j;
    vector<int>ans;

    for(int i=0; i<n; i++){
        j = max(j,lastIndex[S[i]-'a']);
        if(i==j){
            ans.push_back(i-start+1);
            start=i+1;
        }
    }
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