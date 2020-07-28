// https://leetcode.com/problems/the-k-strongest-values-in-an-array/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

class Solution {
public:
    class comp{
        public:
        
        bool operator()(pair<int, int>a, pair<int, int>b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first<b.first;
        }
    };
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n=arr.size();
        int median = arr[(n-1)/2];
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, comp>pq;
        for(int i=0; i<arr.size(); i++){
            pq.push({abs(arr[i]-median), arr[i]});
        }
        
        // while(!pq.empty()){
        //     auto top = pq.top();
        //     cout<<top.first<<" "<<top.second<<endl;
        //     pq.pop();
        // }
        vector<int>ans;
        while(k-- && !pq.empty()){
            auto top = pq.top();
            ans.push_back(top.second);
            pq.pop();
        }
        return ans;
    }
};

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