#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Logic: 
sort acc to end time
1. we will pick activity that has less end time and perform the acitivty and then pick which has start time
greater than equal to prev end time
*/

void solve(){
    int n;
    cin>>n;
    vector<vector<int> >arr(n, vector<int>(3, 0));

    for(int i=0; i<n; i++){
        int start_time;
        cin>>start_time;
        arr[i][0]=start_time;
    }
    for(int i=0; i<n; i++){
        int end_time;
        cin>>end_time;
        arr[i][1]=end_time;
        arr[i][2]=i+1;
    }

    sort(arr.begin(), arr.end(), [](const vector<int>&a, const vector<int>&b){
        return a[1]==b[1]?a[0]<b[0]:a[1]<b[1];
    });

    vector<int>ans;
    int curr = arr[0][1];
    ans.push_back(arr[0][2]);

    for(int i=1; i<n; i++){
        if(arr[i][0] >= curr){
            ans.push_back(arr[i][2]);
            curr = arr[i][1];
        }
    }

    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
}   

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}