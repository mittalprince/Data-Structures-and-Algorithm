// https://codeforces.com/contest/672/problem/C
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
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
#define maxn 100000 + 10

struct nod{
	double x;
	int id;
}a[maxn],b[maxn];
double d[maxn],ans,sum=0.0;
int n,ax,ay,bx,by,tx,ty;
 
bool cmp(nod a,nod b)
{
	return a.x<b.x;
}
 
inline void get_ready(){
	int x,y;
	cin>>ax>>ay>>bx>>by>>tx>>ty;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		d[i]=sqrt(pow(tx-x,2.0)+pow(ty-y,2.0));
		sum+=d[i]*2.0;
		a[i].x=sqrt(pow(ax-x,2.0)+pow(ay-y,2.0))-d[i];a[i].id=i;
		b[i].x=sqrt(pow(bx-x,2.0)+pow(by-y,2.0))-d[i];b[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
}
 
inline void slove(){
	ans=min(a[1].x,b[1].x);
    for(int i=1;i<=n;i++)if(a[i].id!=b[1].id)
	ans=min(ans,a[i].x+b[1].x);
	for(int i=1;i<=n;i++)if(a[1].id!=b[i].id)
	ans=min(ans,a[1].x+b[i].x);
	printf("%.12f\n",ans+sum);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    get_ready();
    slove();
    return 0;
}