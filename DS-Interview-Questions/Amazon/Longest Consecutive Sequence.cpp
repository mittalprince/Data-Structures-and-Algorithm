// https://leetcode.com/problems/longest-consecutive-sequence/
#include<iostream>
#include<vector>
#include<unordered_set>
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

vector<int>parent, size;

int get(int a){
    if(parent[a] == a)return parent[a];
    return parent[a] = get(parent[a]);
}

void union_set(int a, int b){
    a = get(a);
    b = get(b);
    if(a != b){
        parent[b] = a;
        size[a] += size[b];
    }
}

int longestConsecutive(vector<int>& nums){
    int n = nums.size();
    parent.resize(n);
    size.resize(n);

    for(int i=0; i<n; i++){
        parent[i] = i;
        size[i] = 1;
    }
    unordered_map<int,int>m;
    for(int i=0; i<n; i++){
        if(m.count(nums[i])) continue;
        if(m.count(nums[i]-1)){
            union_set(i, m[nums[i]-1]);
        }
        if(m.count(nums[i]+1)){
            union_set(i, m[nums[i]+1]);
        }
        m[nums[i]]=i;
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(parent[i] == i && size[i]>ans){
            ans = size[i];
        }
    }
    return size;
}

int longestConsecutive(vector<int>& nums){
    unordered_set<int>s(nums.begin(), nums.end());
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        if(s.find(nums[i]-1) == s.end()){
            int j = nums[i];
            while(s.count(j)){
                j++;
            }
            ans = max(ans, j-nums[i]);
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