#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int maxProduct(vector<string>& words){
    vector<int>masks;
    vector<int>lens;

    for(string i: words){
        int mask=0;
        int len=0;
        for(char j: i){
            mask |= (1<<(j-'a'));
            len++;
        }
        lens.push_back(len);
        masks.push_back(mask);
    }

    int ans=0;
    for(int i=0; i<words.size(); i++){
        for(int j=i+1; j<words.size(); j++){
            if((masks[i] & masks[j]) == 0){
                int t = (lens[i]*lens[j]);
                ans = max(ans, t);
            }
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