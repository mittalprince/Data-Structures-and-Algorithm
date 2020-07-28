#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int n;
    cin>>n;
    vector<pair<int, int> >arr;
    for(int i=0; i<n; i++){
        int c,r;
        cin>>c>>r;
        arr.push_back({c-r, c+r});
    }
    
    sort(arr.begin(), arr.end(), [](const pair<int, int>&a, const pair<int, int>&b){
        return a.second==b.second ? a.first<b.first: a.second<b.second;
    });

    int done=1;
    int curr = arr[0].second;
    for(int i=1; i<n; i++){
        if(arr[i].first>=curr){
            done++;
            curr = arr[i].second;
        }
    }
    cout<<n-done<<endl;
    return 0;
}