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
    int vec[n];
    ip(vec, n);

    int arr[6]={0};
    
    for(int i=0; i<n; i++){
        int x = vec[i];
        if(x==4) arr[0]++;
        else if(x==8 && arr[1]<arr[0]) arr[1]++;
        else if(x==15 && arr[2]<arr[1]) arr[2]++;
        else if(x==16 && arr[3]<arr[2]) arr[3]++;
        else if(x==23 && arr[4]<arr[3]) arr[4]++;
        else if(x==42 && arr[5]<arr[4])arr[5]++;
    }

    cout<<(n-(6*arr[5]))<<endl;
    return 0;
}