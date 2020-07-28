#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000000

ll n,k;
vector<ll>b,c;

vector<vector<ll> > multiply(vector<vector<ll> >a, vector<vector<ll> >b){
    vector<vector<ll> >C(k, vector<ll>(k));

    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            for(int l=0; l<k; l++){
                C[i][j] = (C[i][j] + (a[i][l]*b[l][j])%MOD)%MOD;
            }
        }
    }
    return C;
}

vector<vector<ll> > fstPower(vector<vector<ll> >T, ll p){
    if(p==1){
        return T;
    }
    if(p&1){
        return multiply(T, fstPower(T, p-1));
    }
    vector<vector<ll> >ans = fstPower(T, p/2);
    return multiply(ans, ans);
}

ll solve(){
    if(n == 0){
        return 0;
    }
    if(n<k){
        return b[n-1];
    }

    vector<ll>F1(k);
    for(int i=0; i<k; i++){
        F1[i] = b[i];
    }

    vector<vector<ll> >T(k, vector<ll>(k));

    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            if(i<k-1){
                if(j == (i+1)){
                    T[i][j]=1;
                }
                else T[i][j]=0;
            }
            else{
                 T[i][j] = c[k-1-j];
            }
        }
    }

    T = fstPower(T, n-1);
    ll ans=0;
    
    for(int i=0; i<k; i++){
        ans = (ans + (T[0][i]*F1[i])%MOD)%MOD;
    }
    return ans;
}

int main(){
    fstIO;

    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	#endif

    int t;
    cin>>t;
     while(t--){
        cin>>k;
        ll num;
        for(int i=0; i<k; i++){
            cin>>num;
            b.push_back(num);
        }
        for(int i=0; i<k; i++){
            cin>>num;
            c.push_back(num);
        }
        cin>>n;
        cout<<solve()<<endl;
        b.clear();
        c.clear();
    }
    return 0;
}