#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            ans += char((i % b) + 97);
        }
        cout << ans << endl;
    }
    return 0;
}