#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<string> findRepeatedDnaSequences(string s) {
    map<string, int>m;

    for(int i=0; i<s.length(); i++){
        if(i>=9){
            string t = s.substr(i-9, 10);
            // cout<<t<<endl;
            m[t]++;
        }
    }

    vector<string>ans;
    for(auto it: m){
        if(it.second>1){
            ans.push_back(it.first);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}