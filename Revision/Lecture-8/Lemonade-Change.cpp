// https://leetcode.com/problems/lemonade-change/
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

bool lemonadeChange(vector<int>& bills) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int five=0, ten=0;

    for(int i: bills){
        if(i==5)five++;
        else if(i==10){
            ten++;
            five--;
            if(five<0)return 0;
        }
        else{
            if(five and ten){
                five--; ten--;
            }
            else if(five>=3){
                five -= 3;
            }
            else return false;
        }
    }
    return true;
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