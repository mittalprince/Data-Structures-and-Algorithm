// https://codeforces.com/contest/600/problem/D
// https://www.xarg.org/2016/07/calculate-the-intersection-area-of-two-circles/

#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
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

struct Point{
    double x,y,r;
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    const long double PI = acos(-1.0);
    long double d, a, b, r1, r2, x1, x2, y, y2;

    cin >> x1 >> y >> r1;
	cin >> x2 >> y2 >> r2;
	d=sqrtl((x1-x2)*(x1-x2)+(y-y2)*(y-y2));
	if (d>=r1+r2) {
		cout << 0.0;
		return 0;
	}
	if (d+min(r1,r2)<=max(r1,r2)) {
		cout << fixed << setprecision(20) << min(r1,r2)*min(r1,r2)*PI;
		return 0;
	}
	a=2*acosl((d*d+r1*r1-r2*r2)/(2*d*r1));
	b=2*acosl((d*d+r2*r2-r1*r1)/(2*d*r2));
	long double ans=r1*r1*(a-sinl(a))/2+r2*r2*(b-sinl(b))/2;
	cout << fixed << setprecision(20) << ans << endl;
    return 0;
}