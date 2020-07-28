#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 9

int main(){
    int t;
    cin>>t;
    while(t--){
        int arr[MAX][MAX];
        string s;
        for(int i=0; i<MAX; i++){
            cin>>s;
            for(int j=0; j<MAX; j++){
                arr[i][j] = s[j]-'0';
            }
        }

        for(int i=0; i<MAX; i++){
            for(int j=0; j<MAX; j++){
                if(arr[i][j]==1) arr[i][j]=2;
            }
        }
        for(int i=0; i<MAX; i++){
            for(int j=0; j<MAX; j++){
                cout<<arr[i][j];
            }
            cout<<endl;
        }

    }
    return 0;
}