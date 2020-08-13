// https://leetcode.com/problems/iterator-for-combination/
#include<iostream>
#include<vector>
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

class CombinationIterator {
public:
    bool hasNextOne;
    string res, input;
    int len, inputLen;
    int freq[26];
    
    CombinationIterator(string characters, int combinationLength) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        input = characters;
        inputLen = input.length();
        len = combinationLength;
        hasNextOne=true;
        
        for(int i=0; i<len; i++){
            res += input[i];
        }
        
        for(int i=0; i<inputLen; i++){
            freq[input[i]-'a']=i;
        }
    }
    
    string next() {
        string currRes=res;
        
        int idx=inputLen-1;
        int resIdx=len-1;
        int removal=0;
        
        while(resIdx>=0 and freq[res[resIdx]-'a'] == idx){
            idx--;
            resIdx--;
            removal++;
        }
        
        if(resIdx<0){
            hasNextOne=false;
            return currRes;
        }
        
        idx = freq[res[resIdx]-'a'];
        res = res.substr(0, len-removal);
        res.pop_back();
        
        while(res.length() != len){
            res += input[++idx];
        }
        return currRes;
    }
    
    bool hasNext() {
        return hasNextOne;
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