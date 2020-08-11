// https://www.spoj.com/problems/PERIOD/
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

void solve(int tc){
    printf("Test case #%d\n", tc);
    int n;
    scanf("%d", &n);
    string pattern;
    cin >> pattern;
    vector<int> table(n, 0);
    int j = 0;
    for(int i=1; i<n; i++){
        while(j>0 and pattern[j] != pattern[i]){
            j = table[j-1];
        }
        if(pattern[i]==pattern[j]){
            table[i]=j+1;
            j++;
        }
        else if(j==0)table[i]=0;

        if(table[i]==0)continue;
        int len = i+1-table[i];
        if((i+1)%len)continue;
        printf("%d %d\n", i + 1, (i + 1) / len);
    }
    printf("\n");
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t, tc_n=1;
    scanf("%d", &t);
    while(t--){
        solve(tc_n);
        tc_n++;
    }
    return 0;
}