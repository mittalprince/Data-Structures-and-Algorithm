#include <iostream>
using namespace std;
 
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
int main() {
	int t;
	cin>>t;
	int f=1;
	while(t--){
	    cout<<"Case "<<f<<": ";
	    int a,b,c;
	    cin>>a>>b>>c;
	    int x = gcd(a,b);
	    if(c%x == 0){
	        cout<<"Yes\n";
	    }
	    else{
	        cout<<"No\n";
	    }
	    f++;
	}
} 