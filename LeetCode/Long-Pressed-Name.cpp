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

bool isLongPressedName(string name, string typed) {
    if(name == typed)return true;

    int i=0, j=0, ct=0;
    bool ans=true;

    while(i<name.size() and j<typed.size()){
        ct=1;
        while((i<name.size()-1) and name[i] == name[i+1]){
            i++;
            ct++;
        }

        while(j<typed.size() and name[i] == typed[j]){
            j++;
            ct--;
        }

        if(ct>0){
            return false;
        }
        if(name[i] != typed[j])i++;
    }

    if(i==name.size() and j==typed.size())return true;
    return false;
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