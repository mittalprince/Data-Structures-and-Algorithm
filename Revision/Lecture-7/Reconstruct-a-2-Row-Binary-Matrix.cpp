// https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/
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

vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int> >arr(2, vector<int>(colsum.size(), 0));

    for(int i=0; i<colsum.size(); i++){
        if(colsum[i]==2){
            upper--; lower--;
            arr[0][i]=arr[1][i]=1;
        }
        else if(colsum[i]==1){
            if(upper>lower){
                upper--;
                arr[0][i]=1;
            }
            else{
                lower--;
                arr[1][i]=1;
            }
        }
        else{
            arr[0][i]=arr[1][i]=0;
        }
    }

    if(upper!=0 or lower !=0)return {};
    return arr;

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