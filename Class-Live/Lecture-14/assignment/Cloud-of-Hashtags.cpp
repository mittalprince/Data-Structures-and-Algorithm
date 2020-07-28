#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int n;
    cin>>n;
    vector<string>arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    for(int i=n-2; i>=0; i--){
        int l=1;
        int r=arr[i].length();

        string ans;
        while(l<=r){
            int mid = (l+r)/2;
            string t = arr[i].substr(0, mid);
            if(t <= arr[i+1]){
                ans = t;
                l=mid+1;
            }
            else r=mid-1;
        }
        arr[i] = ans;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}