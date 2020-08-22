// https://leetcode.com/discuss/interview-question/794983/Google-or-OA-2020-or-Alphabet-Ordering-and-Maximum-Subarray
#include<iostream>
#include<vector>
#include<unordered_map>
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

/*

Input1:
3
6 5
5 9 7 8 2 4
7 5
5 7 5 4 5 8 2
8 5
5 7 2 8 7 4 5 9

Output1:
5
7
6
--------------------------------

Input2:
3
6 4
15 15 16 4 15 9
14 8
8 7 8 8 5 11 13 19 15 3 15 5 11 20
15 15 
18 10 19 19 5 19 16 17 18 18 10 18 17 9 19

Output2:
0
11
4
--------------------------------

Input3:
3
1 2
2
5 13
12 16 12 13 10
13 7
10 7 5 10 7 9 10 15 9 9 7 6 10

Output3:
1
2
6
--------------------------------

Input4:
3
14 19
3 3 17 17 11 14 1 5 5 5 1 3 20 12 
13 2
20 20 13 7 16 20 19 9 13 4 20 16 20
10 19
19 18 14 19 12 13 12 12 13 18

Output4:
2
0
1
--------------------------------
*/

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    ip(arr, n);

    int sum=0;
    for(int &i: arr){
        if(i<k)i=-1;
        else if(i>k) i=1;
        else i=0;

        sum += i;
    }

    if(sum==0){
        cout<<n<<endl;
    }
    else{
        unordered_map<int, int>m;
        m[0]=-1;
        int minLen=inf;
        int currSum=0;
        for(int i=0; i<n; i++){
            currSum += arr[i];
            if(m.count(currSum-sum)){
                minLen = min(minLen, i-m[currSum-sum]);
                if(minLen == sum){
                    break;
                }
            }
            m[currSum]=i;
        }

        cout<<(n-minLen)<<endl;
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}