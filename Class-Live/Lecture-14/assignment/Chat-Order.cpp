#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"

int main(){
    fstIO;
    int n;
    cin>>n;
    
    vector<string>arr;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        arr.push_back(s);
    }

    map<string, bool>freq;
    for(int i=n-1; i>=0; i--){
        if(freq.find(arr[i]) == freq.end()){
            freq[arr[i]]=true;
            cout<<arr[i]<<endl;
        }
    }
    return 0;
}