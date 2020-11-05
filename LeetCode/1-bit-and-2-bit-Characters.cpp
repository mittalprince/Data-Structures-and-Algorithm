//https://leetcode.com/problems/1-bit-and-2-bit-characters/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

bool isOneBitCharacter(vector<int>& bits) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(bits.back()==1){return false;}
    int i=0;
    while(i<bits.size()-1){
        if(bits[i]==1){
            i+=2;
        }else{
            i++;
        }
    }
    return i==bits.size()?false:true;
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