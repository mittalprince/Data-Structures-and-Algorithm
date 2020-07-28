#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//     sort(people.begin(),people.end(),[](const vector<int>& a, const vector<int>& b) {
//         return (a[0] > b[0] || (a[0] == b[0] && a[1]<b[1]));
//     });
//     vector<vector<int>> ans;
//     for(auto person: people) {
//         ans.insert(ans.begin() + person[1], person);
//     }
//     return ans;
// }

class compare{
    public:
    bool operator()(const pair<int, int>&a, const pair<int, int>& b){
        if(a.first == b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
};

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare>pq;

    for(auto i: people){
        pq.push({i[0], i[1]});
    }

    vector<vector<int>>ans;
    vector<int>t;
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        ans.insert(ans.begin()+top.second, {top.first, top.second});
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}