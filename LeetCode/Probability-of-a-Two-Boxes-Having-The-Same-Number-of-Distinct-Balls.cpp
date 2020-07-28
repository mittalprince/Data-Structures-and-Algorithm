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

double equals=0.0;
vector<vector<int> >binom;

vector<vector<int> >getBinon(int n, int k){
    vector<vector<int> >t(n+1, vector<int>(k+1));
    t[0][0]=1;
    for(int i=1; i<=n; i++){
        t[i][0]=1;
        for(int j=1; j<=k; j++){
            t[i][j] = t[i-1][j]+t[i-1][j-1];
        }
    }
    return t;
}

void count(vector<int>&b1, vector<int>&balls, double factor){
    int ct1=0, ct2=0;
    for(int i=0; i<balls.size(); i++){
        ct1 += (b1[i]>0)?1:0;
        ct2 += (balls[i]-b1[i]>0)?1:0;
    }

    if(ct1 == ct2){
        equals += factor;
    }
    return;
}

void choose(vector<int>&balls, int size1, int size2, int k, int i, vector<int>&b1, vector<int>&b2, double factor){
    if(size1>k or size2>k)return;

    if(size1 == k){
        count(b1, balls, factor);
        return;
    }
    if(size2==k){
        count(b2, balls, factor);
        return;
    }

    for(int j=0; j<=min(balls[i], k-size1); j++){
        b1[i] += j;
        b2[i] += balls[i]-j;
        choose(balls, size1+j, size2+balls[i]-j, k, i+1, b1, b2, factor*binom[balls[i]][j]); // choose j balls from total of ball[i]
        b1[i] -= j;
        b2[i] -= balls[i]-j;
    }
    return;
}

double getProbability(vector<int>&balls){
    equals=0;
    int size=0;
    for(int i: balls){
        size += i;
    }
    int n=size;
    binom = getBinon(n, n/2);
    vector<int>b1(n, 0), b2(n, 0);
    choose(balls, 0, 0, n/2, 0, b1, b2, 1);
    return (double)equals/binom[n][n/2];
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