#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int lengthOfLongestSubstring(string s){
    vector<int> m(128, 0);
    int n=s.length();
    int start=0, ans=0;

    for(int i=0; i<n; i++){
        if(m[s[i]]>0){
            start = max(start, m[s[i]]);
        }
        ans = max(ans, i-start+1);
        m[s[i]]=i+1;
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s)<<endl;

    return 0;
}