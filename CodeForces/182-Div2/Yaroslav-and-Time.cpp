// https://codeforces.com/contest/302/problem/D
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,d;
    cin>>n>>d;
    int arr[100]={0};
    for(int i=1; i<n-1; i++){
        cin>>arr[i];
    }

    vector<pair<int, int> >points;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        points.push_back({x,y});
    }

    int dist[100][100]={0};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j)dist[i][j]=inf;
            else{
                dist[i][j] = d*(abs(points[i].first-points[j].first) + abs(points[i].second - points[j].second)) - arr[i];
            }
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(k!=i and i!=j){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    cout<<dist[0][n-1]<<endl;
    return 0;
}