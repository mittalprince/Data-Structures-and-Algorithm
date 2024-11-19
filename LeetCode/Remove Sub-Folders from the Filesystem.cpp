// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
#include<iostream>
#include<vector>
#include<algorithm>
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

vector<string> removeSubfolders(vector<string>& folder) {
    const int n=folder.size();
    sort(folder.begin(), folder.end());
    vector<string> ans={folder[0]};
//    ans.reserve(40000);
    string prev=folder[0];
    for(int i=1; i<n; i++){
        string s=folder[i];
        if (s.find(prev+'/')!=0){
            ans.push_back(s);
            prev=s;
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