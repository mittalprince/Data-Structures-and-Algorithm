#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int compress(vector<char>&arr){
    int n=arr.size();
    int i=1, k=0, ct=0;

    while(i<=n){
        ct=1;
        while(i<n && arr[i] == arr[i-1]){
            ct++;
            i++;
        }
        arr[k++] = arr[i-1];
        if(ct>1){
            string t = to_string(ct);
            for(char j: t) arr[k++]=j;
        }
        i++;
    }
    return k;
}
int main(){
    int n;
    cin>>n;
    vector<char>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int len = compress(arr);
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}