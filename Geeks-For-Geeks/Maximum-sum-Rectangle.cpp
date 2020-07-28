#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007
#define MAX 1005

int n,m;
int arr[MAX][MAX];

int kadanes(int a[], int &start, int &end, int n){
    int sum=0, max_sum=-inf;
    int local_start=0;

    for(int i=0; i<n; i++){
        sum += a[i];
        if(max_sum<sum){
            max_sum = sum;
            end=i;
            start=local_start;
        }

        if(sum<0){
            local_start=i+1;
            sum=0;
        }
    }

    return max_sum;
}

void solve(){
    int max_sum=-inf;
    int top,bottom,left,right;

    int l,r,i;
    int temp[n], start, end, sum;

    for(l=0; l<m; l++){
        memset(temp, 0, sizeof(temp));
        for(r=l; r<m; r++){
            
            for(i=0; i<n; i++){
                temp[i] += arr[i][r];
            }

            sum = kadanes(temp, start, end, n);
            if(max_sum<sum){
                max_sum=sum;
                top=start;
                bottom = end;
                left = l;
                right=r;
            }
        }
    }

    cout << "(Top, Left) (" << top 
         << ", " << left << ")" << endl;  
    cout << "(Bottom, Right) (" << bottom  
         << ", " << right << ")" << endl;  
    cout << "Max sum is: " << max_sum << endl;  
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>arr[i][j];
            }
        }
        solve();
    }
    return 0;
}