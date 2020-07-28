#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

vector<int> transformArray(vector<int>&arr){
    int n=arr.size();
    vector<int>prev(arr.begin(), arr.end());

    bool isChanged=false;
    do{
        isChanged=false;
        for(int i=1; i<n-1; i++){
            if(prev[i]>prev[i-1] && prev[i]>prev[i+1]){
                arr[i]--;
                isChanged=true;
            }
            else if(prev[i]<prev[i-1] && prev[i]<prev[i+1]){
                arr[i]++;
                isChanged=true;
            }
        }
        prev = arr;
    }while(isChanged);
    return arr;
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    ip(arr, n);
    vector<int>ans = transformArray(arr);
    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}