// https://leetcode.com/problems/next-greater-element-i/
#include<iostream>
#include<vector>
#include<stack>
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

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(nums1.size() == 0){
        return {};
    }
    unordered_map<int,int> map;
    stack<int> s;
    int lastNum = nums2[nums2.size() - 1];
    map[lastNum] = -1;
    s.push(lastNum);

    for(int i=nums2.size()-2; i>=0; i--){
        while(!s.empty() and s.top()<=nums2[i])s.pop();

        if(s.empty()){
            map[nums2[i]]=-1;
        }
        else map[nums2[i]]=s.top();

        s.push(nums2[i]);
    }

    vector<int>ans;
    for(int i: nums1){
        ans.push_back(map[i]);
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