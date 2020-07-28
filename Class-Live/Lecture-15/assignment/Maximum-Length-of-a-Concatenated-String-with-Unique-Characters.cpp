#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool isRepeat(bitset<26> &visited, string &str) {
    for (auto c : str) {
        if (visited[c - 'a']) return true;
        visited[c - 'a'] = 1;
    }
    return false;
}

void solve(vector<string>&arr, int i, int &ans, bitset<26>&visited){
    for(int j=i; j<arr.size(); j++){
        bitset<26>t = visited;
        if(isRepeat(t, arr[j])) continue;
        ans = max(ans, (int)t.count());
        solve(arr, j+1, ans, t);
    }
}
int maxLength(vector<string>& arr) {
    if(arr.empty()) return 0;
    int ans=0;
    bitset<26>visited(0);
    solve(arr, 0, ans, visited);
    return ans;

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}