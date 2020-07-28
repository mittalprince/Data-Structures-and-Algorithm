#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int findContentChildren(vector<int>& g, vector<int>& s) {
    if(g.size()==0||s.size()==0)
        return 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    if(s[s.size()-1]<g[0]) return 0;

    int ans=0;
    int i=0, j=0;
    while(i<g.size() && j<s.size()){
        if(g[i]<=s[j]){
            ans++;
            i++;
        }
        j++;
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}