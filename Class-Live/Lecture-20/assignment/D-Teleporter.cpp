#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007
#define MAX 200005

vector<ll>dest(MAX); // what will be my dest when I have done teleporting ith time.
unordered_map<ll, ll>m; // at which teleporting no this dest will come.


int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    fstIO;
    
    int n;
    cin>>n;

    ll k;
    cin>>k;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
        arr[i]--;
    }

    int x=1;
    m[0]=0; // at which place when we done 0 times teleporting, obviously at 0 item(state).
    int start=0;
    int low, high;

    // now we done ith times telporting and find at which dest we are, and check whether this dest
    // occur earliear or not if yes then cyclw present.
    // so we check at which teleporting time the same dest will come, This will be our low and current teleporting index will be high
    for(int i=0; i<=n; i++){
        dest[x] = arr[start]; // at xth teleporting time we are on which state.
        if(m.count(dest[x])){
            low = m[dest[x]];
            high = x;
            break;
        }
        else{
            m[dest[x]]=x;
        }
        x++;
        start = arr[start];
    }

    if(k<high){
        cout<<dest[k]+1<<endl;
    }
    else{
        ll len = high-low;
        k -= low; // as cycle start at low, so first reduce 1 to low times teleporting from k.
        k = k%len;
        cout<<dest[low+k]+1<<endl;
    }

    return 0;
}