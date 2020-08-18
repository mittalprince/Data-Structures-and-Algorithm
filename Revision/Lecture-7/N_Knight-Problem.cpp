// https://hack.codingblocks.com/app/contests/1496/265/problem
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

int n,cnt=0;
int board[100][100]={0};
vector<pair<int, int> >ans;

const int x[]={-2,-2,-1,-1,1,1,2,2};
const int y[]={-1,1,-2,2,-2,2,-1,1};

bool isSafe(int i, int j){
    for(int k=0; k<8; k++){
        if(i+x[k]>=0 and i+x[k]<n and j+y[k]>=0 and j+y[k]<n){
            if(board[i+x[k]][j+y[k]])return false;
        }
    }
    return true;
}

bool solve(int placed, int r, int c){
    if(placed==n){
        for(int i=0;i<ans.size();i++){
			cout<<"{"<<ans[i].first<<"-"<<ans[i].second<<"} ";
		}
		cout<<" ";
		cnt++;
		return false;
    }
    if(r==n)return false;
    if(c==n){
        return solve(placed, r+1, 0);
    }

    if(isSafe(r, c)){
        ans.push_back({r,c});
        board[r][c]=1;
        bool checkRem = solve(placed+1, r, c+1);
        // if(checkRem)return true;
        ans.pop_back();
        board[r][c]=0;
    }
    return solve(placed, r, c+1);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n;
    solve(0,0,0);
    cout<<endl<<cnt<<endl;
    
    return 0;
}