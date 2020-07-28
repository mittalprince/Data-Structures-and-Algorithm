#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int numJewelsInStones(string J, string S) {
    vector<int> freq(128, 0);
    for(auto i: J){
        freq[i]=true;
    }
    int ans=0;
    for(auto i: S){
        if(freq[i])ans++;
    }
    return ans;
}

int main(){
    string J, S;
    cin>>J>>S;
    cout<<numJewelsInStones(J, S)<<endl;
    return 0;
}