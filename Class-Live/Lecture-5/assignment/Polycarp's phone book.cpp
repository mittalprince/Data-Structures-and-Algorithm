#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    fstIO;
    int n;
    cin>>n;
    // set<string>sstr;
    map<string, ll> m;
    vector<string> arr(n);
    for(int i=0; i<n; i++){
        set<string> sstr;
        cin>>arr[i];
        for(int j=0; j<9; j++){
            string key = "";
            for(int k=j; k<9; k++){
                key += arr[i][k];
                // cout<<key<<endl;
                sstr.insert(key);
            }
        }
        for(auto it: sstr) m[it]++;
    }
    
    vector<string> ans(n, "");
    for(int i=0; i<n; i++){
        ans[i] = arr[i];
        // cout<<arr[i]<<" ";
        for(int j=0; j<9; j++){
            string key = "";
            for(int k=j; k<9; k++){
                key += arr[i][k];
                if(m[key] == 1){
                    if(ans[i].length() > key.length()){
                        ans[i]=key;
                        break;
                    }
                }
            }
        }
    }

    for(auto i: ans){
        cout<<i<<endl;
    }
    return 0;
}