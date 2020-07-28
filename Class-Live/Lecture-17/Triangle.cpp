// Triangle
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int len[4];
    ip(len, 4);
    
    sort(len, len+4);

    int flag=-1;
    for(int i=0; i<2; i++){
        if((len[i]+len[i+1]) >= len[i+2]){
            if((len[i] + len[i+1]) == len[i+2]){
                flag=0;
            }
            else{
                flag=1;
                break;
            }
        }
    }

    if(flag == -1) cout << "IMPOSSIBLE" << endl;
    else if(flag == 0) cout << "SEGMENT" << endl;
    else cout << "TRIANGLE" << endl;
    return 0;
}
