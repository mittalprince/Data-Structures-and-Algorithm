#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

int n;
int *arr;

int solve(){
    int sum=0;
    int mul=1;

    for(int i=0; i<30; i++){
        int l = 0, ct = 0;

        for(int j=0; j<n; j++){
            if(arr[j]&(1<<i)){
                if(ct){
                    l++;
                }
                else{
                    ct=1;
                    l=1;
                }
            }
            else if(ct){
                sum += (mul * l*(l+1)/2);
                ct=0;
                l=0;
            }
        }

        if(ct) sum += (mul * l * (l + 1) / 2);

        mul = mul<<1;
    }

    return sum;
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n;
    arr = new int[n];
    ip(arr, n);
    cout<<solve()<<endl;
    return 0;
}