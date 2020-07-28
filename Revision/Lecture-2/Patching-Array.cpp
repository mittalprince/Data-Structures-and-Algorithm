#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

/*
Logic: We can make all no update [1, gayab)
so we find gayab no and update our range at each step and check it gayab var can make from the range or not
if yes we simple update the range
otherwise we update patch and add gayab no into range and update it

how to range update if [1, gayab) and now if we add 4 the range will chnage into [1,gayab+x)
*/
int minPatches(vector<int>&arr, int n){
    int miss=1; // assume initally missing no will be 1 (it also tell at which range we can create no's);
    int i=0, add=0; // index to iterate over arr and store min patches req

    while(miss<=n){
        if(i<arr.size() and miss >= arr[i]){// means we can create all no upto miss and since arr[i]<= so updtae the range
            miss += arr[i];// by adding curr arr[i]
            i++;
        }
        else{
            // the curr miss no we req neither present in arr nor we can make it using prev no
            add++; // so update patch
            miss += miss; // and if we add miss no the range change and new range will be [1, miss+miss];
        }
    }
    return add;
}

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