#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 300009

bool comp(ll a, ll b){
    return a>b;
}

int main(){
    fstIO;
    int n, temp;
    cin>>n;
    vector<ll> arr;
    ll ans=0;
    ll ct=1;
    for(ll i=0; i<2*n; i++){
        string operation;
        cin>>operation;
        if(operation == "remove"){
            if(!arr.empty()){
                if(arr.back() == ct){
                    arr.pop_back();
                }
                else{
                    // sort(arr.begin(), arr.end(), comp);
                    // arr.pop_back();
                    arr.clear();
                    ans++;
                }
            }
            ct++;
        }
        else{
            cin>>temp;
            arr.push_back(temp);
        }
    }
    cout<<ans<<endl;
    return 0;
}