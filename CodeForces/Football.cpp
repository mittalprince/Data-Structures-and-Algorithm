#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int n;
    cin>>n;
    map<string, int> m;
    int ans=0;
    string team;
    for(int i=0l; i<n; i++){
        string s;
        cin>>s;
        m[s]++;
        if(ans < m[s]) {
            ans=m[s];
            team = s;   
        }
    }
    cout<<team<<endl;
    return 0;
}